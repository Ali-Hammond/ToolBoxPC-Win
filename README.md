## ToolboxPC-Win Setup Guide

This guide will walk you through setting up, building, and running ToolboxPC-Win using `Qt Creator` and `CMake` with `Qt 6.8`.

---

# Important: Read the  [LICENSE](LICENSE)

Before forking the ToolboxPC-Win repository or making any modifications to the code, please be sure to read the [LICENSE](LICENSE) file included in the repository. The LICENSE outlines the terms and conditions for using, modifying, and redistributing the code. By forking or contributing to this project, you agree to comply with the terms of the  [LICENSE](LICENSE). It is important to fully understand the permissions and limitations set by the license before proceeding with any changes or distribution.

---

**Step 1: Install `Qt` and `Qt Creator`**

Go to the [Qt download page](https://www.qt.io/download-qt-installer-oss)
Download and run the `Qt Online Installer`.
During installation, select `Qt 6.8 (Desktop version)`.
Complete the installation. `Qt Creator` will be installed along with `Qt`.

---

**Step 2: Install `CMake`**

Go to the [CMake download page](https://cmake.org/download/)
Download and run the `CMake` installer for Windows.
During installation, ensure you add `CMake` to your system’s `PATH` so you can run it from the command line.

---
**Step 3: Install `Git`**

Go to the [Git download page](https://git-scm.com/download/win)
Download and run the `Git installer for Windows`.
Make sure you choose to add Git to your system’s `PATH` during installation.

---

**Step 4: Clone the Repository**

Open `Command Prompt` or `Git Bash`.

Run the following command to clone the repository:

```
git clone https://github.com/yourusername/ToolboxPC-Win.git
```
---

**Step 5: Open the Project in Qt Creator**

Open `Qt Creator`.
Click `File > Open File or Project`.
Navigate to the folder where you cloned the repository and open the `CMakeLists.txt` file.
`Qt Creator` will automatically detect the project and configure it.

---

**Step 6: Configure the Project in Qt Creator**

In the bottom-left corner of Qt Creator, click on the PC monitor icon to open the Kit options.
Make sure `Qt 6.8 MinGW 64-Bit` (or the appropriate kit for your setup) is selected under the Kit section.
Ensure that the Build Configuration is set to `Release`, not `Debug`.

---

**Step 7: Build the Project**

In `Qt Creator`, click the Build button (or press Ctrl + Shift + B) to start building the project.
`Qt Creator` will use `CMake` to generate the necessary build files and build the project with the selected kit.
The executable will be generated in the build directory<br>
(e.g., `ToolboxPC-Win/build/ToolboxPC-Win-Desktop_Qt_6_8_2_MinGW_64bit-Release`).

---

**Step 8: Run the Release Version**

Navigate to the release folder.
Find the `ToolboxPC-Win.exe` file and double-click to run it.
The application should now run as a fully built, release version.

---

### Issue Reporting

If you encounter any issues not covered in this guide, please feel free to open a new issue using the [Issues tab](https://github.com/Ali-Hammond/ToolBoxPC-Win/issues)

***Before submitting an issue, make sure you are using the official version of ToolboxPC-Win. Issues related to unofficial versions or modifications may not be supported, as it's not original code.***