#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*����˼·��˳ʱ���ӡ���ǰ�Ȧ��ѭ����ӡ��һȦ�������л������У��ڴ�ӡ��ʱ������ĳһȦ��ֻ����һ�У�Ҫ�жϴ������Ҵ�ӡ�ʹ��������ӡ��ʱ���Ƿ������ظ���ӡ��ͬ��ֻ����һ��ʱ��Ҫ�жϴ������´�ӡ�ʹ������ϴ�ӡ��ʱ���Ƿ������ظ���ӡ�����*/
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>res;
		res.clear();
		int row = matrix.size();//����
		int collor = matrix[0].size();//����
		//�����ӡ��Ȧ��
		int circle = ((row<collor ? row : collor) - 1) / 2 + 1;//Ȧ��
		for (int i = 0; i<circle; i++){
			//�������Ҵ�ӡ
			for (int j = i; j<collor - i; j++)
				res.push_back(matrix[i][j]);
			//�������µ�ÿһ������ 
			for (int k = i + 1; k<row - i; k++)
				res.push_back(matrix[k][collor - 1 - i]);
			//�ж��Ƿ���ظ���ӡ(���������ÿ������) 
			for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)
				res.push_back(matrix[row - i - 1][m]);
			//�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
			for (int n = row - i - 2; (n>i) && (collor - i - 1 != i); n--)
				res.push_back(matrix[n][i]);
		}
		return res;
	}
};

void TestFunc(){
	vector<vector<int>> array = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }
	, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int i = 0;
	int j = 0;
	for (i = 0; i < array.size(); ++i){
		for (j = 0; j < array[0].size(); ++j){
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Solution s;
	vector<int> temp = s.printMatrix(array);
	i = 0;
	for (i = 0; i < temp.size(); ++i){
		cout << temp[i] << " ";
	}
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}