#include <iostream>
#include <vector>

using namespace std;

/*
 * 给出一组正整数，你从第一个数向最后一个数方向跳跃， 每次至少跳跃1格，
 * 每个数的值表示你从这个位置可以跳跃的最大长度。 计算如何以最少的跳跃次数跳到最后一个数。
 * 输入描述：
 * 第一行表示有多少个数n
 * 第二行开始依次是1到n个数， 一个数一行
 * 输出描述：
 * 输出一行， 表示最少跳跃的次数。
 * 输入
 * 7 2 3 2 1 2 1 5
 * 输出
 * 3
 */

class JumpGame{

public:
    int jump(vector<int> arr){

        if(arr.empty() || arr.size() == 0)
            return 0;

        int jump = 0;
        int cur = 0;//当前步，最远可以到达的位置
        int next = 0;//下一步，最远可以到达的位置
        for(int i = 0; i < arr.size(); ++i){//枚举每一个位置

            if(cur < i){

                jump++;
                cur = next;
            }
            next = max(next, i + arr[i]);//之前收集到的next 和 从当前位置出发能够到达的右边界的位置
        }

        return jump;
    }
};

int main()
{
    vector<int> arr = { 3, 2, 3, 1, 1, 4 };
    JumpGame game;

    cout << game.jump(arr) << endl;

    return 0;
}

