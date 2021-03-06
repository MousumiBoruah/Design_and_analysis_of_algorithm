#include<stdio.h>
#include<stdlib.h>
void merge(int* ,int* ,int  ,int ,int);
void mergesort(int* ,int [],int ,int);
void print(int* ,int ,int );
int isLarge(int* , int , int );
int partition(int *,int,int );
void swap(int *,int , int); 
void Quick_Sort(int *,int,int);
int main(){
	int apple_size[6] = {54,12,0,100,45,16};
	int size_index[6] = {0,1,2,3,4,5};
	int packet_size[6] = {46,59,19,100,7,17};
	int match_pack[6] = {0,1,2,3,4,5};
	printf("\n");
	mergesort(apple_size, size_index,0,5);
	quicksort(match_pack,0,5);
	printf("\n");
	finalMatch(apple_size,packet_size,size_index,match_pack);
	int i;
    for(i = 0;i < 6;i++){
    	printf("The Uniquely Fitted Packet for apple number:- %d is packet number = %d \n",size_index[i],match_pack[i]);
    }
}

int isLarge(int* a, int i , int j){
	if(a[i] < a[j])
		return -1;
	else
		return 1;
}
void merge(int *apple_size,int *a,int left ,int mid ,int right){
	int i=0 , j=0 , k =left , n1 ,n2,l=0;
	n1 = mid - left + 1;
	n2 = right - mid;
	int a_left[n1] , a_right[n2];
	for(i = 0 ; i < n1 ; i++){
		a_left[i] = a[left + i];
	}
	for (j = 0; j < n2 ; j++)
	{
		a_right[j] = a[mid + 1 + j];
	}
	i = 0 ; j = 0;
	while(i < n1 && j < n2){
		if(isLarge(apple_size, a_left[i],a_right[j]) == -1){
			a[k++] = a_left[i++];
		}
		else if(isLarge(apple_size, a_left[i],a_right[j]) == 1){
			a[k++] = a_right[j++];
		}
	}
	while(i < n1){
		a[k++] = a_left[i++];
		
	}
	while(j < n2){
		a[k++] = a_right[j++];
		
	}
}
void mergesort(int *apple_size,int *a,int left ,int right){
	if(left < right){
		int mid = (left + right - 1)/2;
		mergesort(apple_size, a,left,mid);
		mergesort(apple_size, a,mid+1,right);
		merge(apple_size,a,left,mid,right);
	}
}


void print(int *size_index,int i,int j){
	for(i = 0;i < j ; i++){
		printf("%d \n",size_index[i]);
	}
}
void mergesortpacket(int *packet_size,int *match_pack,int left,int right){
	if(left < right){
	int mid = (left + right - 1)/2;
	mergesortpacket(packet_size,match_pack,left,mid);
	mergesortpacket(packet_size,match_pack,mid+1,right);
	mergepacket(packet_size,match_pack,left,mid,right);
  }
}
void mergepacket(int *packet_size,int *a,int left ,int mid ,int right){
	int i=0 , j=0 , k =left , n1 ,n2,l=0;
	n1 = mid - left + 1;
	n2 = right - mid;
	int a_left[n1] , a_right[n2];
	for(i = 0 ; i < n1 ; i++){
		a_left[i] = a[left + i];
	}
	for (j = 0; j < n2 ; j++)
	{
		a_right[j] = a[mid + 1 + j];
	}
	i = 0 ; j = 0;
	while(i < n1 && j < n2){
		if(isLargepack(packet_size, a_left[i],a_right[j]) == -1){
			a[k++] = a_left[i++];
		}
		else if(isLargepack(packet_size, a_left[i],a_right[j]) == 1){
			a[k++] = a_right[j++];
		}
	}
	while(i < n1){
		a[k++] = a_left[i++];
		
	}
	while(j < n2){
		a[k++] = a_right[j++];
		
	}
}
int Tightfit(int *packet_size,int *apple_size,int i,int j){
    if(packet_size[j] == apple_size[i])
		return 0;
	else if(packet_size[j] > apple_size[j])
		return 1;
	else 
		return -1;

}
void swap(int *M,int left_index, int i){
    int temp = M[left_index];
    M[left_index] = M[i];
    M[i] = temp;
	}
    
int partition(int *M,int low,int high){
    int i = 0;
    int last_index = high;
    int apple_to_compare;
    while (i < len(A)){
        if (TightFit(i, M[last_index]) == 0){
            apple_to_compare = i
            break;
		}
        i+=1;
	}	
    i = low;
    left_index = low - 1;
    while (i < high){
        if TightFit(apple_to_compare, M[i]) == -1{
            left_index+=1;
            swap(M, left_index, i);
			}
        i+=1;
	}
    swap(M, left_index + 1, high);
    return (left_index + 1);

void Quick_Sort(int *M,int low,int high){
    if(low < high){
        pivot = partition(M, low, high);
        Quick_Sort(M, low, pivot-1);
        Quick_Sort(M, pivot+1, high);
    return;
	}

