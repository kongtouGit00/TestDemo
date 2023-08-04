#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 给定两个数组arrx和arry， 长度都为N。
 * 代表二维平面上有N个点， 第i个点的x坐标和y坐标分别为arrx[i]和arry[i]，
 * 返回求一条直线最多能穿过多少个点？
 */

struct Point{

    int x;
    int y;

    Point(){

        this->x = 0;
        this->y = 0;
    }

    Point(int x,int y){

        this->x = x;
        this->y = y;
    }
};

class MaxPointsOneLine{

public:
    int maxPoints(vector<Point*> point){

        if(point.empty())
            return 0;

        if(point.size() <= 2)
            return point.size();

        unordered_map< int, unordered_map<int, int> > myMap;
        int result = 0;
        for(unsigned int i = 0; i < point.size(); ++i){//尝试以每一个点作为开头

            myMap.clear();
            int samePosition = 1;
            int sameX = 0;
            int sameY = 0;
            int line = 0;
            for(int j = i + 1; j < point.size(); ++j){//依次查看后续每一个点和当前i位置点的关系

                int x = point[j]->x - point[i]->x;
                int y = point[j]->y - point[i]->y;
                if(x == 0 && y == 0){//两个点是同一个位置的点，就是1个点

                    samePosition++;

                }else if(x == 0){//两个点共Y轴, x相同

                    sameX++;

                }else if(y == 0){//两个点共X轴, y相同

                    sameY++;

                }else{

                    int g = gcd(x, y);//最大公约数
                    x /= g;
                    y /= g;
                    if(myMap[x].find(y) == myMap[x].end()){

                        myMap[x].insert(make_pair(y, 0));
                    }
                    myMap[x][y] = myMap[x][y] + 1;//斜率相同的数的数量加1
                    line = max(line, myMap[x][y]);
                }
            }

            result = max(result, max(max(sameX, sameY), line) + samePosition);
        }

        return result;
    }

private:
    int gcd(int m, int n){

        return n == 0 ? m : gcd(n, m % n);
    }
};

int main()
{
    vector<Point*> arr;
    Point* p1 = new Point(1, 2);
    Point* p2 = new Point(2, 4);
    Point* p3 = new Point(1, 5);
    Point* p4 = new Point(1, 7);
    Point* p5 = new Point(3, 6);

    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);

    MaxPointsOneLine ans;

    cout << ans.maxPoints(arr) << endl;

    return 0;
}
