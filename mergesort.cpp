#include <iostream>
using namespace std;

void print_array(int a[],int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return;
}

void merge(int a[],int s,int mid,int e){
	int b[100];
	int i = s;
	int j = mid + 1;
	int k = s;
	
	while (i <= mid && j <= e){
		if (a[i] <= a[j]){
			b[k] = a[i];
			i ++;
		}
		else{
			b[k] = a[j];
			j ++;
		}
		k ++;
	}
	while (i <= mid){
		b[k] = a[i];
		k ++;
		i ++;
	}
	while (j <= e){
		b[k] = a[j];
		k ++;
		j ++;
	}
	
	for (int i=s;i<=e;i++){
        a[i] = b[i];
    }
	return;
}

void merge_sort(int a[],int s,int e){
	if (s < e){
		int mid = (s + e) / 2;
		merge_sort(a,s,mid);
		merge_sort(a,mid + 1,e);
		merge(a,s,mid,e);
	}
	return;
}

int main(){
	
	int a[100],n;
	
	cout<<"How many elements:";
	cin>>n;
	
	cout<<"Enter "<<n<<" elements:";
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<"Original array:";
	print_array(a,n);
	
	int s = 0;
	int e = n - 1;
	
	merge_sort(a,s,e);
	
	cout<<"\nSorted array:";
	print_array(a,n);
	
	return 0;
}
