#include<iostream>
using namespace std;
void merge_sort(int *,int , int);
void merge(int *,int ,int ,int);
int main(){
	int points[6] = {12,3,12,0,90,24};
	merge_sort(points , 0 ,6);
	for(int i =0 ; i <6 ;i++ ){
	cout << "The sorted array is" << points[i] << endl;
   }
}

void merge_sort(int *a ,int left ,int right){

	int mid = (left + right-1)/2;
	merge_sort(a ,left , mid);
	merge_sort(a , mid+1 ,right);
	merge(a , left ,right ,mid);
}

void merge(int *a , int left , int right , int mid){
	int i=0,j=0,k=0,n1,n2;
	n1 = mid - left + 1;
	n2 = right - mid;
	int size = right - left + 1;
	int a_left[n1],a_right[n2],a_main[size];
	while(i < n1 && j < n2){
		if(a_left[i] < a_right[j]){
			a_main[k++] = a_left[i++];
		}
		else
			a_main[k++] = a_right[j++];
	}
    while(i < n1){
    	a_main[k++] = a_left[i++];
    }
    while(j < n2){
    	a_main[k++] = a_right[j++];
    }
}
