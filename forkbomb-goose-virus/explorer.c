#define _WIN32_WINNT 0x0500
#include <stdio.h>
#include <time.h>
#include <windows.h>

int main(void){
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_MINIMIZE );
    ShowWindow( hWnd, SW_HIDE );

    srand(time(NULL));
    int dl = (int)5+(rand()%5);
    char r[dl];
    for( int i=0; i<dl; i++){
        r[i]=(char)(65+(rand()%26));
    }
    SetWindowTextA(hWnd, r);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    char s[]="C:\\Windows\\driv\\explorer.exe";
    for(int j=0; j<2; j++){
        for( int i=0; i<5; i++){
            r[i]=(char)(65+(rand()%26));
        }
        SetWindowTextA(hWnd, r);
        system("C:\\Windows\\DesktopGoose\\GooseDesktop.exe");
        if( !CreateProcess( NULL, s, NULL, NULL, FALSE, CREATE_NEW_PROCESS_GROUP, NULL, NULL, &si, &pi )){
            printf( "Prosze nie psuc (%d).\n", GetLastError());
            return 1;
        }
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
    }
    return 0;
}
