#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 * 给定一个数组arr长度为N， 你可以把任意长度大于0且小于N的前缀作为左部分，
 * 剩下的作为右部分。 但是每种划分下都有左部分的最大值和右部分的最大值，
 * 请返回最大的，左部分最大值减去右部分最大值的绝对值。
 */

class MaxABSBetweenLeftAndRight{

public:
    int maxABS(vector<int> arr){

        int maxs = std::numeric_limits<int>::min();
        for(unsigned int i = 0; i < arr.size(); ++i)
            maxs = max(maxs, arr[i]);

        return maxs - min(arr[0], arr[arr.size() - 1]);
    }
};

int main()
{
    vector<int> arr = {2, 1, 6, 3, 9, 0, 3, 5};
    MaxABSBetweenLeftAndRight ans;

    cout << ans.maxABS(arr) << endl;

    return 0;
}
