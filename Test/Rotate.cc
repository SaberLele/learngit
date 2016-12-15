 ///
 /// @file    Rotate.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-12 23:25:01
 ///

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Rotate
{
	public:
		vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n)
		{
			if(n==1 || n==0)
				return mat;

			int up=0;
			int right = n-1;
			int left = 0;
			int down = n-1;

			while(up < down && left < right)
			{
				int begin = up + 1;
				for(int i = left+1; i < right; ++i)
				{
					std::swap(mat[up][i],mat[begin++][right]);
				}

				begin = down - 1;
				for(int i = left + 1; i< right; i++)
				{
					std::swap(mat[up][i],mat[begin--][left]);
				}

				begin = up + 1;
				for(int i = left + 1; i < right; i++)
				{
					std::swap(mat[down][i],mat[begin++][left]);
				}

				//四个角上的元素互换
				std::swap(mat[up][left],mat[up][right]);
				std::swap(mat[up][left],mat[down][left]);
				std::swap(mat[down][left],mat[down][right]);

				up++;
				down--;
				left++;
				right--;
			}
			return mat;
		}
};

int main()
{
	vector<vector<int> > mat(4);
	for(int i = 0; i < 4; ++i)
	{
		mat[i].resize(4);
	}

	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			mat[i][j]=i+j;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	vector<vector<int> >newmat;
	Rotate rotate;
	newmat = rotate.rotateMatrix(mat,4);

	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			cout << newmat[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
