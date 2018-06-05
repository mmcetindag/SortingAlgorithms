#include<iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 100000
class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
};
STACK::STACK(){
    top=-1;
}
 
int STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int STACK::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}
 
int STACK::push(int n){

    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int STACK::pop(){
  
    int temp;
    
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void STACK::displayItems(){
    int i; 
    cout<<""<< endl;
    cout<<"STACK is: " << endl;
    for(i=(top); i>=0; i--)
        cout<<num[i]<<",";
    cout<<endl;
}

template <class a>
void randomNumbers(a data[] , int size){
	for (int i = 0; i < size ; i++)

                   {

                    data[i] =(rand()%1000);
					
					}

}

template <class a>
void print(a data[] , long size){

	 for (long i = 0; i < size ; i++){
	 	cout << data[i] <<  ","; 
	 
	 }
	 cout<<""<< endl;
    
}

template <class X>
void selectionSort(X array[], int size)
{
    int smallindex = 0;
    for(int i = 0; i < size; i++)
    {
        smallindex = i; 
        for(int j = i + 1; j < size; j++) 
            if(array[j] < array[smallindex])
                smallindex = j;
        if(smallindex != i)
            swap(array[smallindex], array[i]);
    }     
}


template <class T>  T partition2(T data[], long start, long end)
{
	T pivotValue = data[start];
    long pivotPosition = start;

    for (long pos = start + 1; pos <= end; pos++)
    {
        if (data[pos] < pivotValue)
        {  
            swap(data[pivotPosition + 1], data[pos]);
            swap(data[pivotPosition], data[pivotPosition + 1]);
            pivotPosition ++;
        }
	}
    return pivotPosition;
}

template <class T> void quickSort2(T data[], long start, long end)
{
	  if (start < end)       
    {
        long p = partition2(data, start, end);
        quickSort2(data, start, p - 1);
        quickSort2(data, p + 1, end);
	}
	return; 
}

template <class Tmp> void partition3(Tmp data[], long l, long r, long &i, long &j)
{
    i = l-1, j = r;
    long p = l-1, q = r;
    Tmp v = data[r];
 
    while (true)
    {  
        while (data[++i] < v);
        while (v < data[--j])
            if (j == l)
                break;
 
        if (i >= j) break;
 
        swap(data[i], data[j]);
 
        if (data[i] == v)
        {
            p++;
            swap(data[p], data[i]);
        }
 
        if (data[j] == v)
        {
            q--;
            swap(data[j], data[q]);
        }
    }
    swap(data[i], data[r]);
    j = i-1;
    for (long k = l; k < p; k++, j--)
        swap(data[k], data[j]);
    i = i+1;
    for (long k = r-1; k > q; k--, i++)
        swap(data[i], data[k]);
}

template <class Tmp> void quicksort3(Tmp data[], long l, long r)
{
    if (r <= l) return;
 
    long i, j;
    partition3(data, l, r, i, j);
    quicksort3(data, l, j);
    quicksort3(data, i, r);
}

template <class a>
 void bucketSort(a data[], long count){
 	long minValue = data[0];
	long maxValue = data[0];

	for (long i = 1; i < count; i++){	
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

	long bucketLength = maxValue - minValue + 1;

	vector<long>* bucket = new vector<long>[bucketLength];
	for (long i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<long>();
	}

	for (long i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}
	
	long k = 0;
	
	for (long i = 0; i < bucketLength; i++)
	{
	long bucketSize = bucket[i].size();
		if (bucketSize > 0)
		{
			for (long j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}

	}	

}

template <class T>
 void sel(T *a, const int n)
 {// sort a[0] to a[n-1] into nondecreasing

 for (int i = 0; i < n; i++)
 {
 int j = i;
 // find smallest integer in a[i] to a[n-1]
 for (int k = i+1; k < n; k++)
 if (a[k] < a[j]) {j = k;}
 swap(a[i], a[j]);
 }
 }
int main(){
	
	
	long size;
		cout<< "Write the size of the Array" << endl;
 		cin >> size;
 	long data[size];
		srand((unsigned)time(0));
		randomNumbers(data , size);
	int select;
	int i=0;

	cout<< "Select to Sorting Algorithms" << endl;
	cout<< "1) Selection Sort" << endl;
	cout<< "2) Quicksort (2-way partitioning)" << endl;
	cout<< "3) Quicksort (3-way partitioning)" << endl;
	cout<< "4) Bucket Sort" << endl;
	cout<< "5) Exit" << endl;
 	cin >> select;
 	
	if(select == 1){
		selectionSort(data, size);
		cout<< "Sorted by Selection Sort Algorithms :" << endl;
	}
 	else if(select==2){
 		quickSort2(data, 0 , size-1);
 		cout<< "Sorted by Quicksort (2-way partitioning) Algorithms :" << endl;
	}
	else if(select==3){
		quicksort3(data,0 , size-1);
		cout<< "Sorted by Quicksort (3-way partitioning) Algorithms :" << endl;	
	}
	else{
		bucketSort(data, size);
		cout<< "Sorted by Bucket Sort Algorithms :" << endl;
	}
		
	
	print(data , size);
    STACK stk;

    for (long j = size-1; j >= 0 ; j--)
	{
		stk.push(data[j]); 
	}
			
	//stk.displayItems();		
 	 
	return 0;
}
