#include<iostream>
using namespace std;

template<typename T>
T** get_2D_Array(int rows, int colomns){
	T** array_2D=new T*[rows];//assign main 2d array or array of pointers
	for(int i=0;i<rows;++i)
		array_2D[i]=new T[colomns];//assign 1d (sub) arrays
	return array_2D;
}

int main(){
	int R, C;

	cout<<"enter total rows: ";
	cin>>R;
	
	cout<<"enter total colomns: ";
	cin>>C;

	int** array=get_2D_Array<int>(R, C);
	
	cout<<"\nenter values:\n";
	for(int i=0,j;i<R;++i)
		for(j=0;j<C;++j)
			cin>>array[i][j];
	
	cout<<"\nvalues of 2D aaray:\n";
	for(int i=0,j;i<R;++i){//Traverse the 2D array
		for(j=0;j<C;++j)
			cout<<array[i][j]<<' ';
		cout<<'\n';
	}
	
	for(int i=0;i<R;++i)//Delete the array created
		delete[] array[i];
	delete[] array;
	
	return 0;
}

