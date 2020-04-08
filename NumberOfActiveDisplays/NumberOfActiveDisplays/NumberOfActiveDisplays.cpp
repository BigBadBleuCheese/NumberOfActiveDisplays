#include <iostream>
#include "windows.h"

using namespace std;

int main()
{
    UINT32 pathCount, modeCount;
    LONG getDisplayConfigBufferSizesResult = GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &pathCount, &modeCount);
    switch (getDisplayConfigBufferSizesResult)
    {
    case ERROR_SUCCESS:
        cout << pathCount;
        return 0;
    case ERROR_INVALID_PARAMETER:
        cerr << "GetDisplayConfigBufferSizes says the combination of parameters and flags I've specified is invalid";
        return 2;
    case ERROR_NOT_SUPPORTED:
        cerr << "GetDisplayConfigBufferSizes says the system is not running a graphics driver that was written according to the Windows Display Driver Model (WDDM), which it requires";
        return 3;
    case ERROR_ACCESS_DENIED:
        cerr << "GetDisplayConfigBufferSizes says the I do not have access to the console session";
        return 4;
    case ERROR_GEN_FAILURE:
        cerr << "GetDisplayConfigBufferSizes says an unspecified error occurred (which is immensely helpful)";
        return 5;
    default:
        cerr << "GetDisplayConfigBufferSizes returned unsuccessful result: " << getDisplayConfigBufferSizesResult;
        return 1;
    }
}
