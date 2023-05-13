#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {

    // Initialize variables for file selection
    OPENFILENAME ofn;           // common dialog box structure
    char szFile[260];           // buffer for file name
    HWND hwnd = NULL;           // owner window

    // Initialize OPENFILENAME struct
    ZeroMemory(&ofn, sizeof(ofn));                      // Clear memory for struct
    ofn.lStructSize = sizeof(ofn);                      // Set size of struct
    ofn.hwndOwner = hwnd;                               // Set owner window (null in this case)
    ofn.lpstrFile = szFile;                             // Set buffer for file name
    ofn.nMaxFile = sizeof(szFile);                      // Set maximum length of file name
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";        // Set filter for file types
    ofn.nFilterIndex = 1;                               // Set default filter index
    ofn.lpstrFileTitle = NULL;                          // Set buffer for file title (not used in this case)
    ofn.nMaxFileTitle = 0;                              // Set maximum length of file title (not used in this case)
    ofn.lpstrInitialDir = NULL;                         // Set initial directory (not used in this case)
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;  // Set options for file selection
    szFile[0] = '\0';

    cout << "\t\t********************************** press 1 to browse **********************************\n\n\n";

    while (true) {
        // Check if the '1' key is pressed
        if (_getch() == '1') {
            // Display the Open dialog box.
            if (GetOpenFileName(&ofn)==TRUE) {
                // Do something with the selected file
                cout << "\n**********************************\n";
                cout << "Selected file: " << szFile << endl;
                cout << "**********************************\n\n";
            }
        }
        else cout << "No, press 1 to browse\n";
    }

    return 0;
}
