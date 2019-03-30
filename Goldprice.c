#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int max(int day[],int l,int r){
	int i,buffer = day[l];
	for(i = l;i <= r; i++){
		if(day[i] >= buffer)
			buffer = day[i];
	}
	return(buffer);
}
int min(int day[], int l , int r){
	int i,buffer = day[l];
    for(i = l;i <= r; i++){
		if(day[i] <= buffer)
			buffer = day[i]; 
	}
	//printf("%d\n" ,buffer);
	return(buffer);
}
int maximum(int left,int right,int across){
	if(left >= right && left >= across)
		return left;
	else if(right >= left && right >= across)
		return right;
	else
		return across;
}

int gain(int day[],int l ,int r){
	int mid,left,right,across,profit;
	if(l == r) {
		return 0;
	}
	else if((r - l) == 1){
		return day[r] - day[l];
	}
    else{
	 	mid = (l + r)/2;
	    left = gain(day , l , mid);
		right = gain(day ,mid + 1,r);
		across = max(day , mid + 1, r) - min(day, l ,mid);
		profit = maximum(left,right,across);
		printf("%d %d %d\n",left,right,across);
		return(profit);
	}
  }

int main(){
	FILE *fp =fopen("Goldprice.txt","r"); 
	int total_days,i,max_profit = 0;
	int *day;
	fscanf(fp ,"%d" ,&total_days);
	day =(int *) malloc(sizeof(int) * total_days);
	for(i = 0 ;i < total_days;i++){
		fscanf(fp,"%d ", &day[i]);
	}
	for(i = 0 ;i < total_days;i++){
		printf("%d ",day[i]);
	}
    max_profit = gain(day,0,total_days-1);
    printf("\nTHE MAXIMUM PROFIT IS = %d\n",max_profit);
}

