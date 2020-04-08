#include <iostream>
#include "windows.h"

using namespace std;

int main()
{
    UINT32 pathCount, modeCount;
    if (GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &pathCount, &modeCount) != 0)
    {
        cerr << "GetDisplayConfigBufferSizes was unsuccessful";
        return 1;
    }
    cout << pathCount;
    return 0;
}
