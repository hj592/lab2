#include <iostream>
#include <vector>

using namespace std;

void sumMatrix(vector<vector<int> > &a, vector<vector<int> > &b, vector<vector<int> > &sum){
	for(int i=0; i< a.size(); i++){
		vector<int> v;
		for(int j=0; j<a[0].size(); j++){
			v.push_back(a[i][j]+b[i][j]);
		}
		sum.push_back(v);
	}
}

int main(){
	int row;
	int col;
	cout << "row size : ";
	cin >> row;
	cout << "col size : ";
	cin >> col;
	
	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
	vector<vector<int>> sumM;
	
	cout <<"matrix1"<<endl;
	for(int i=0; i<row ;i++){
		vector<int> mCol;
		for(int j=0;j<col;j++){
			int temp = 0;
			cin >> temp;
			mCol.push_back(temp);
		}
		matrix1.push_back(mCol);
	}
	
	cout <<"matrix2"<<endl;
	
	
	for(int i=0; i<row ;i++){
		vector<int> mCol;
		for(int j=0;j<col;j++){
			int temp = 0;
			cin >> temp;
			mCol.push_back(temp);
		}
		matrix2.push_back(mCol);
	}
	
	sumMatrix(matrix1, matrix2, sumM);
	
	cout << "sum"<<endl;
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<sumM[i][j]<<"\t";
		}
		cout << endl;
	}
	return 0;
}
	
