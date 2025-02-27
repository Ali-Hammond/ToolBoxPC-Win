#include "gpuusage.h"
#include <windows.h>
#include <iostream>
#include <wbemidl.h>
#include <comdef.h>

#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "ole32.lib")

// Initialize COM library for WMI
bool initializeCOM() {
    HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cerr << "COM initialization failed: " << std::hex << hres << std::dec << std::endl;
        return false;
    }

    hres = CoInitializeSecurity(
        NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL
        );

    if (FAILED(hres)) {
        std::cerr << "Security initialization failed: " << std::hex << hres << std::dec << std::endl;
        CoUninitialize();
        return false;
    }
    return true;
}

// Function to retrieve GPU usage from WMI
float GpuUsage::getGpuUsage() {
    if (!initializeCOM()) {
        return -1.0f;
    }

    IWbemLocator *pLoc = nullptr;
    IWbemServices *pSvc = nullptr;

    // Create the WMI locator object
    HRESULT hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *)&pLoc);
    if (FAILED(hres)) {
        std::cerr << "Failed to create WbemLocator instance: " << std::hex << hres << std::dec << std::endl;
        CoUninitialize();
        return -1.0f;
    }

    // Create BSTRs for the connection parameters
    _bstr_t bstrNamespace(L"ROOT\\CIMV2");
    _bstr_t bstrUser(L"");
    _bstr_t bstrPassword(L"");
    _bstr_t bstrLocale(L"");

    // Connect to the WMI namespace
    hres = pLoc->ConnectServer(
        bstrNamespace, bstrUser, bstrPassword, bstrLocale, 0, L"", 0, &pSvc
        );

    if (FAILED(hres)) {
        std::cerr << "Failed to connect to WMI namespace: " << std::hex << hres << std::dec << std::endl;
        pLoc->Release();
        CoUninitialize();
        return -1.0f;
    }

    // Set the security levels on the proxy
    hres = CoSetProxyBlanket(
        pSvc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, NULL, RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE
        );

    if (FAILED(hres)) {
        std::cerr << "Failed to set proxy blanket: " << std::hex << hres << std::dec << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return -1.0f;
    }

    // Query for GPU usage
    IEnumWbemClassObject* pEnumerator = nullptr;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT * FROM Win32_PerfFormattedData_GPUPerformanceCounters_GPUUsage"),
        WBEM_FLAG_FORWARD_ONLY, NULL, &pEnumerator
        );

    if (FAILED(hres) || pEnumerator == nullptr) {
        std::cerr << "Failed to execute WMI query: " << std::hex << hres << std::dec << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return -1.0f;
    }

    IWbemClassObject *pClassObject = nullptr;
    ULONG uReturn = 0;
    float gpuUsage = -1.0f;

    while (pEnumerator) {
        hres = pEnumerator->Next(WBEM_INFINITE, 1, &pClassObject, &uReturn);
        if (0 == uReturn) {
            break;
        }

        if (pClassObject == nullptr) {
            continue;  // Skip null class objects
        }

        // Get the GPU usage
        VARIANT vtProp;
        hres = pClassObject->Get(L"PercentBusUtilization", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hres)) {
            gpuUsage = vtProp.fltVal;
            VariantClear(&vtProp);
        } else {
            std::cerr << "Failed to get PercentBusUtilization: " << std::hex << hres << std::dec << std::endl;
        }

        pClassObject->Release();
    }

    pEnumerator->Release();
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    return gpuUsage;
}
