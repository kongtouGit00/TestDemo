#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个无序数组arr， 如果只能对一个子数组进行排序，
 * 但是想让数组整体都有序， 求需要排序的最短子数组长度。
 * 例如:arr = [1,5,3,4,2,6,7]返回4， 因为只有[5,3,4,2]需要排序
 */

/* 第一次遍历从左往右，找到需要排序的最右的位置
 * 第二次遍历从右往左，找到需要排序的最左的位置
 * 两位置之间的就是需要排序的子数组
 */

class MinLengthForSort{

public:
    int getMinLength(vector<int>& arr){

        if(arr.empty() || arr.size() < 2)
            return 0;

        int mins = arr[arr.size() - 1];
        int noMinIndex = -1;
        for(int i = arr.size() - 2; i >= 0; --i){

            if(arr[i] > mins){

                noMinIndex = i;

            }else{

                mins = min(mins, arr[i]);
            }
        }
        if(noMinIndex == -1)
            return 0;

        int maxs = arr[0];
        int noMaxIndex = -1;
        for(int i = 1; i < arr.size(); ++i){

            if(arr[i] < maxs){

                noMaxIndex = i;

            }else{

                maxs = max(maxs, arr[i]);
            }
        }

        return noMaxIndex - noMinIndex + 1;
    }
};

int main()
{
   vector<int> arr = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
    MinLengthForSort ans;

    cout << ans.getMinLength(arr) << endl;

    vector<int> arr2 = {1, 5, 3, 4, 2, 6, 7};

    cout << ans.getMinLength(arr2) << endl;

    return 0;
}
