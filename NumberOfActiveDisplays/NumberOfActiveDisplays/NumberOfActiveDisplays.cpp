#include <iostream>
#include "windows.h"

using namespace std;

int main()
{
    UINT32 pathCount, modeCount;
    LONG getDisplayConfigBufferSizesResult = GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &pathCount, &modeCount);
    if (getDisplayConfigBufferSizesResult != 0)
    {
        cerr << "GetDisplayConfigBufferSizes returned unsuccessful result: " << getDisplayConfigBufferSizesResult;
        return 1;
    }
    cout << pathCount;
    return 0;
}
