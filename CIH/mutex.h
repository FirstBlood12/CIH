#include <Windows.h>

HANDLE CreateOneAppMutex(LPCTSTR lpName)
{
    HANDLE hMutex;
 
    // Create mutex
    hMutex = CreateMutex(NULL, TRUE, lpName);
 
    switch(GetLastError())
    {
    case ERROR_SUCCESS:
        // Mutex created successfully. There is 
        // no instances running
        break;
 
    case ERROR_ALREADY_EXISTS:
        // Mutex already exists so there is a 
        // running instance of our app.
        hMutex = NULL;
		ExitProcess(true);
        break;
 
    default:
        // Failed to create mutex by unknown reason
        break;
    }
 
    return hMutex;
}