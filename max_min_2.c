#include <stdio.h>
#include<stdlib.h>
int mini(int *A_l){
	if(A_l[0] > A_l[1] && A_l[0] > A_l[2]){
		return A_l[0];
	}
	else if(A_l[1] > A_l[2] && A_l[1] > A_l[0]){
		return A_l[1];
	}
	else{
		return A_l[2];
	}
}
int maxi(int x,int y,int z){
	if(x <  y & x < z){
		return x;
	}
	else if(y < x && y < z){
		return y;
	}
	else{
		return z;
	}
}
int main(){
	int n,i,r,A_l[3],A_r[3],k=3,result=0,min = 1000,j,max=0;
	printf("Enter the size of the array");
	scanf("%d",&n);
	int *A = (int *)(malloc(sizeof(int) * n));
	for(i = 0;i < n;i++){
		printf("Enter the values of %d element",i);
		scanf("%d",&A[i]);
	}
	for(i = 0;i < n;i++){
		printf("\n%d ",A[i]);
	}
	for (int i=0; i <n-2; i++) 
    {  
       result = A[i] + A[i+1] + A[i+2];
       	if(min > result){
       		min = result;
       		for(j = 0 ;j < 3;j++){
       			A_l[j]= A[i + j];
       		}
       	}
    } 
   min = mini(A_l);
   for (int i=0; i <n-2; i++) 
    {  
       result = A[i] + A[i+1] + A[i+2];
       r = maxi(A[i],A[i+1],A[i+2]);
       	if(max < result && min >= r){
       		max = result;
       		for(j = 0 ;j < 3;j++){
       			A_r[j]= A[i + j];
       		}
       	}
     }
     for(i = 0 ;i< 3;i++){
     	printf("AL=%d,",A_l[i]);
     }
     printf("\n");
     for(i = 0 ;i< 3;i++){
     	printf("AR=%d,",A_r[i]);
     }
 }
