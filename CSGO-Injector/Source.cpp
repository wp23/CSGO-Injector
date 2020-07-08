#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#include "Junk.h"

#define Junk \
__asm _emit 0x89 \
__asm _emit 0x06 \
__asm _emit 0x80 \
__asm _emit 0x97 \
__asm _emit 0x12 \
__asm _emit 0x98 \
__asm _emit 0x67 \
__asm _emit 0x64 \
__asm _emit 0x74 \
__asm _emit 0x22 \
__asm _emit 0x96 \
__asm _emit 0x95 \
__asm _emit 0x35 \
__asm _emit 0x60 \
__asm _emit 0x53 \
__asm _emit 0x64 \
__asm _emit 0x77 \
__asm _emit 0x52 \
__asm _emit 0x17 \
__asm _emit 0x12 \
__asm _emit 0x22 \
__asm _emit 0x49 \
__asm _emit 0x90 \
__asm _emit 0x67 \
__asm _emit 0x04 \
__asm _emit 0x26 \
__asm _emit 0x59 \
__asm _emit 0x33 \
__asm _emit 0x10 \
__asm _emit 0x98 \
__asm _emit 0x64 \
__asm _emit 0x96 \
__asm _emit 0x74 \
__asm _emit 0x64 \
__asm _emit 0x55 \
__asm _emit 0x35 \
__asm _emit 0x48 \
__asm _emit 0x47 \
__asm _emit 0x44 \
__asm _emit 0x89 \
__asm _emit 0x97 \
__asm _emit 0x78 \
__asm _emit 0x56 \
__asm _emit 0x50 \
__asm _emit 0x87 \
__asm _emit 0x69 \
__asm _emit 0x88 \
__asm _emit 0x79 \
__asm _emit 0x89 \
__asm _emit 0x23 \
__asm _emit 0x44 \
__asm _emit 0x16 \
__asm _emit 0x18 \
__asm _emit 0x03 \
__asm _emit 0x50 \
__asm _emit 0x76 \
__asm _emit 0x75 \
__asm _emit 0x53 \
__asm _emit 0x73 \
__asm _emit 0x35 \
__asm _emit 0x48 \
__asm _emit 0x78 \
__asm _emit 0x80 \
__asm _emit 0x67 \
__asm _emit 0x30 \
__asm _emit 0x02 \
__asm _emit 0x21 \
__asm _emit 0x07 \
__asm _emit 0x30 \
__asm _emit 0x37 \
__asm _emit 0x82 \
__asm _emit 0x59 \
__asm _emit 0x13 \
__asm _emit 0x88 \
__asm _emit 0x65 \
__asm _emit 0x22 \
__asm _emit 0x37 \
__asm _emit 0x14 \
__asm _emit 0x46 \
__asm _emit 0x72 \
__asm _emit 0x23 \
__asm _emit 0x63 \
__asm _emit 0x91 \
__asm _emit 0x83 \
__asm _emit 0x37 \
__asm _emit 0x51 \
__asm _emit 0x71 \
__asm _emit 0x08 \
__asm _emit 0x30 \
__asm _emit 0x37 \
__asm _emit 0x59 \
__asm _emit 0x22 \
__asm _emit 0x72 \
__asm _emit 0x74 \
__asm _emit 0x06 \
__asm _emit 0x99 \
__asm _emit 0x21 \
__asm _emit 0x85 \
__asm _emit 0x42 \
__asm _emit 0x47 \

#define _JUNK_BLOCK(s) __asm jmp s Junk __asm s:

void clearWindow()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}
DWORD GetProcId(const char* procName)
{
    _JUNK_BLOCK(jmp_label1)
    DWORD procId = 0;
    _JUNK_BLOCK(jmp_label18)
    gHo();
    iHj();
    TNsp();
    DHaz();
    SieU();
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        _JUNK_BLOCK(jmp_label19)
        procEntry.dwSize = sizeof(procEntry);
        _JUNK_BLOCK(jmp_label2)
        if (Process32First(hSnap, &procEntry))
        {
            _JUNK_BLOCK(jmp_label3)
            do
            {
                if (!_stricmp(procEntry.szExeFile, procName))
                {
                    _JUNK_BLOCK(jmp_label16)
                    xtXP();
                    BNxW();
                    Wchh();
                    Xze();
                    DbL();
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
        _JUNK_BLOCK(jmp_label4)
    }
    CloseHandle(hSnap);
    _JUNK_BLOCK(jmp_label5)
    return procId;
}

int main()
{
    clearWindow();
    char filename[MAX_PATH];
    const char* procName = "csgo.exe";
    _JUNK_BLOCK(jmp_label6)
    OPENFILENAME ofn;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = "DLL\0*.dll\0";
    ofn.lpstrFile = filename;
    _JUNK_BLOCK(jmp_label7)
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrTitle = "Select file to inject!";
    ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
    _JUNK_BLOCK(jmp_label8)
    if (GetOpenFileNameA(&ofn))
    {
        std::cout << "You chose the file \"" << filename << "\"\n";
        DWORD procId = 0;
        _JUNK_BLOCK(jmp_label9)
        while (!procId)
        {
            procId = GetProcId(procName);
            Sleep(30);
        }
        _JUNK_BLOCK(jmp_label10)
        HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);
        _JUNK_BLOCK(jmp_label11)
        if (hProc && hProc != INVALID_HANDLE_VALUE)
        {
            _JUNK_BLOCK(jmp_label12)
            void* loc = VirtualAllocEx(hProc, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            _JUNK_BLOCK(jmp_label13)
            WriteProcessMemory(hProc, loc, filename, strlen(filename) + 1, 0);
            _JUNK_BLOCK(jmp_label4)
            HANDLE hThread = CreateRemoteThread(hProc, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
            _JUNK_BLOCK(jmp_label15)
            pBut();
            yAD();
            mop();
            LlKk();
            AfUh();
            if (hThread)
            {
                CloseHandle(hThread);
            }
        }

        if (hProc)
        {
            CloseHandle(hProc);
            _JUNK_BLOCK(jmp_label17)
            dmfc();
            tXm();
            dgm();
            qmY();
            MYa();
        }
    }
    else
    {
        switch (CommDlgExtendedError())
        {
        case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
        case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
        case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
        case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
        case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
        case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
        case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
        case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
        case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
        case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
        case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
        case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
        case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
        case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
        case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
        default: std::cout << "You cancelled.\n";
        }
    }
    _JUNK_BLOCK(jmp_label20)
    Sleep(1500);
    return 0;
}

