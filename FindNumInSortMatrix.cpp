#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个元素为非负整数的二维数组matrix， 每行和每列都是从小到大有序的。
 * 再给定一个非负整数aim， 请判断aim是否在matrix中。
 */

class FindNumInSortMatrix{

public:
    bool isContains(vector< vector<int> >& matrix, int k){

        int row = 0;
        int col = matrix[0].size() - 1;
        while(row < matrix.size() && col > -1){

            if(matrix[row][col] == k){

                return true;

            }else if(matrix[row][col] > k){

                col--;

            }else{

                row++;
            }
        }

        return false;
    }
};

int main()
{
    vector< vector<int> > arr = { { 0, 1, 2, 3, 4, 5, 6 },// 0
                                  { 10, 12, 13, 15, 16, 17, 18 },// 1
                                  { 23, 24, 25, 26, 27, 28, 29 },// 2
                                  { 44, 45, 46, 47, 48, 49, 50 },// 3
                                  { 65, 66, 67, 68, 69, 70, 71 },// 4
                                  { 96, 97, 98, 99, 100, 111, 122 },// 5
                                  { 166, 176, 186, 187, 190, 195, 200 },// 6
                                  { 233, 243, 321, 341, 356, 370, 380 } }; // 7
    FindNumInSortMatrix matrix;

    cout << matrix.isContains(arr, 102) << endl;

    return 0;
}
