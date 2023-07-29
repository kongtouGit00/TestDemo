#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个有序数组arr， 代表数轴上从左到右有n个点arr[0]、 arr[1]...arr[n－ 1]，
 * 给定一个正数L， 代表一根长度为L的绳子， 求绳子最多能覆盖其中的几个点。
 */

class CordCoverMaxPoint{

public:
    int maxPoint(vector<int> arr, int L){

        int result = 1;
        for(int i = 0; i < arr.size(); ++i){

            int nearest = nearestIndex(arr, i, arr[i] - L);
            result = max(result, i - nearest + 1);
        }

        return result;
    }

private:
    //在arr[L...R]范围上，找 >= value 最左的位置
    int nearestIndex(vector<int>& arr, int R, int value){

        int L = 0;
        int index = R;
        while(L < R){

            int mid = L + ((R - L) >> 1);
            if(arr[mid] >= value){

                index = mid;
                R = mid - 1;

            }else{

                L = mid + 1;
            }
        }

        return index;
    }
};

int main()
{
    vector<int> arr = { 0, 13, 24, 35, 46, 57, 60, 72, 87 };
    CordCoverMaxPoint coverMax;

    cout << coverMax.maxPoint(arr, 30);

    return 0;
}
