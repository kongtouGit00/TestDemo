#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个N*N的矩阵matrix， 只有0和1两种值， 返回边框全是1的最大正方形的边长长度。
 * 例如:
 * 01111
 * 01001
 * 01001
 * 01111
 * 01011
 * 其中边框全是1的最大正方形的大小为4*4， 所以返回4。
 */

class MaxOneBorderSize{

public:
    int getMaxSize(vector< vector<int> >& matrix){

        vector< vector<int> > right(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector< vector<int> > down(matrix.size(), vector<int>(matrix[0].size(), 0));

        setBorderSize(matrix, right, down);
        //依次尝试边长为1的所有正方形，边长为2的所有正方形...一直到边长为n的所有正方形
        for(int size = min(matrix.size(), matrix[0].size()); size != 0; --size){

            if(hasSizeOfBorder(size, right, down))
                return size;
        }

        return 0;
    }

private:
    void setBorderSize(vector< vector<int> >& matrix, vector< vector<int> >& right, vector< vector<int> >& down){

        int row = matrix.size();
        int col = matrix[0].size();
        //先设置右下角的点的情况
        if(matrix[row - 1][col - 1] == 1){

            right[row - 1][col - 1] = 1;
            down[row - 1][col - 1] = 1;
        }
        //设置最后一列的情况
        for(int i = row - 2; i >= 0; --i){

            if(matrix[i][col - 1] == 1){

                right[i][col - 1] = 1;
                down[i][col - 1] = down[i + 1][col - 1] + 1;
            }
        }
        //设置最后一行的情况
        for(int i = col - 1; i >= 0; --i){

            if(matrix[row - 1][i] == 1){

                right[row - 1][i] = right[row - 1][i + 1] + 1;
                down[row - 1][i] = 1;
            }
        }
        //设置除了最后一行以及最后一列的其他的行列情况
        for(int i = row - 2; i >= 0; --i)
            for(int j = col - 2; j >= 0; --j){

                if(matrix[i][j] == 1){

                    right[i][j] = right[i][j + 1] + 1;
                    down[i][j] = down[i + 1][j] + 1;
                }
            }
    }

    bool hasSizeOfBorder(int size, vector< vector<int> >& right, vector< vector<int> >& down){

        /*
         * 在尝试每个点的时候，有些点注定是不可能到达的，
         * 比如当前长度是测试长度为size，而正方形边长为length，
         * 那么当前点p(x, y)，那么必须得保证x + size < length,
         * 否则是没有意义的；
         * 因此，一个点的尝试范围就是(length - size),
         * 因为要写成!=的形式，所以,就是 != (length - size + 1),
         * 同理, y的变化也是如此
         */
        for(int i = 0; i != right.size() - size + 1; ++i)
            for(int j = 0; j != right[0].size() - size + 1; ++j)
                if(right[i][j] >= size && down[i][j] >= size
                        && right[i + size - 1][j] >= size
                        && down[i][j + size - 1] >= size)
                    return true;

        return false;
    }
};

int main()
{
    vector< vector<int> > matrix = {{0, 1, 1, 1, 1}, {0, 1, 0, 0, 1},
                                    {0, 1, 0, 0, 1}, {0, 1, 1, 1, 1}, {0, 1, 0, 1, 1}};

    MaxOneBorderSize borderSize;

    cout << borderSize.getMaxSize(matrix) << endl;

    return 0;
}
