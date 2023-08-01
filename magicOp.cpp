#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
 * 给一个包含n个整数元素的集合a，一个包含m个整数元素的集合b。
 * 定义magic操作为，从一个集合中取出一个元素，放到另一个集合里，
 * 且操作过后每个集合的平均值都大大于于操作前。
 * 注意以下两点：
 * 1）不可以把一个集合的元素取空，这样就没有平均值了
 * 2）值为x的元素从集合b取出放入集合a，但集合a中已经有值为x的元素，则a的平均值不变（因为集合元素不会重复）
 * b的平均值可能会改变（因为x被取出了）
 * 问最多可以进行多少次magic操作？
 */

class MagicOp{

public:
    // 请保证arr1无重复值、arr2中无重复值，且arr1和arr2肯定有数字
    int maxOps(vector<int> arr1, vector<int> arr2){

        double sum1 = 0;
        for(unsigned int i = 0; i < arr1.size(); ++i)
            sum1 += static_cast<double>(arr1[i]);

        double sum2 = 0;
        for(unsigned int i = 0; i < arr2.size(); ++i)
            sum2 += static_cast<double>(arr2[i]);
        //如果两个集合的平均值一样，那么是不可能通过移数使得两个集合的平均值都增大的(毕竟财富不可能凭空产生
        if(avg(sum1, arr1.size()) == avg(sum2, arr2.size()))
            return 0;

        vector<int> arrMore;//平均值大的集合
        vector<int> arrLess;//平均值小的集合
        double sumMore = 0;//平均值大的集合的累加和
        double sumLess = 0;//平均值小的集合的累加和
        if(avg(sum1, arr1.size()) > avg(sum2, arr2.size())){

            arrMore = arr1;
            arrLess = arr2;
            sumMore = sum1;
            sumLess = sum2;

        }else{

            arrMore = arr2;
            arrLess = arr1;
            sumMore = sum2;
            sumLess = sum1;
        }//以上操作是，区分出平均值大的集合 和 平均值小的集合

        //使平均值较大的集合中的数有序，因为我要按照从小到大的方式把数拿出来塞到平均值较小的集合中(这样操作的次数才尽可能多
        sort(arrMore.begin(), arrMore.end());

        unordered_set<int> mySet;
        for(int i : arrLess){//把平均值较小的集合中的数全部塞到Set中去

            mySet.insert(arrLess[i]);
        }

        int moreSize = arrMore.size();
        int lessSize = arrLess.size();
        int ops = 0;//操作次数
        for(unsigned int i = 0; i < moreSize; ++i){

            double cur = static_cast<double>(arrMore[i]);
            /*
             *执行一次ops操作的规则是,
             * 1.我当前拿出来的数一定是小于我较大集合的平均值
             * 2.我当前拿出来的数一定是大于我较小集合的平均值
             * 3.当前要拿到较小平均值集合中的数，一定是在较小平均值集合中没有出现的数(因为要保证集合中没有重复值
             */
            if(cur < avg(sumMore, moreSize) && cur > avg(sumLess, lessSize) && (mySet.find(arrMore[i]) == mySet.end())){

                sumMore -= cur;
                moreSize--;
                sumLess += cur;
                lessSize++;
                mySet.insert(arrMore[i]);
                ops++;
            }
        }

        return ops;
    }

private:
    double avg(double sum ,int size){

        return sum / static_cast<double>(size);
    }
};

int main()
{
    vector<int> arr1 = { 1, 2, 5 };
    vector<int> arr2 = { 2, 3, 4, 5, 6 };

    MagicOp op;

    cout << op.maxOps(arr1, arr2) << endl;

    return 0;
}
