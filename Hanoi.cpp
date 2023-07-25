#include <iostream>

using namespace std;

class Hanoi{

public:
    //1 ~ i, 从 from 移动到 to,另外一个叫other
    void process(int i, string from, string to, string other){

        if(i == 1){

            cout << "Move 1 from " << from << " to " << to << endl;

        }else{

            process(i - 1, from, other, to); //1~i-1, 从from到other，to
            cout << "Move " << i << " from " << from << " to " << to << endl;//i, 从from到to
            process(i - 1, other, to, from); //1~i-1, 从other到to, from
        }
    }
};

int main()
{
    Hanoi hanoi;

    hanoi.process(3, "left", "right", "middle");

    return 0;
}
