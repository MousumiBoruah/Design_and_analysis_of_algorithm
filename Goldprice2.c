#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct goldp{
	int buy;
	int sell;
	int profit;
}gold;
int max(int day[],int l,int r){
	int i,buffer = day[l],m;
	for(i = l;i <= r; i++){
		if(day[i] >= buffer){
			buffer = day[i];
			m = i;
	    }
    }
	return(m);
}
int min(int day[], int l , int r){
	int i,buffer = day[l],m;
    for(i = l;i <= r; i++){
		if(day[i] <= buffer){
			buffer = day[i]; 
			m = i;
   		}
	}
	//printf("%d\n" ,buffer);
	return(m);
}
gold maximum(gold left,gold right,gold across){
	if(left.profit >= right.profit && left.profit >= across.profit)
		return left;
	else if(right.profit >= left.profit && right.profit >= across.profit)
		return right;
	else
		return across;
}

gold gain(int day[],int l ,int r){
	int mid;
	gold left,right,across,profitt;
	if(l == r) {
		gold temp;
		temp.buy = l;
		temp.sell = r;
		temp.profit = 0;
		return temp;
	}
	else if((r - l) == 1){
		gold temp;
		temp.buy = l;
		temp.sell = r;
		temp.profit = day[r] - day[l];
		return temp;
	}
    else{
	 	mid = (l + r)/2;
	    left = gain(day , l , mid);
		right = gain(day ,mid + 1,r);
		across.sell =  max(day , mid + 1, r);
		across.buy = min(day, l ,mid);
		across.profit = day[across.sell] - day[across.buy];
		profitt = maximum(left,right,across);
		printf("%d %d %d\n",left.profit,right.profit,across.profit);
		return profitt;
		
	}
  }

int main(){
	FILE *fp =fopen("Goldprice.txt","r"); 
	int total_days,i;
	gold max_profit;
	int *day;
	fscanf(fp ,"%d" ,&total_days);
	day =(int *) malloc(sizeof(int) * total_days);
	for(i = 0 ;i < total_days;i++){
		fscanf(fp,"%d ", &day[i]);
	}
	for(i = 0 ;i < total_days;i++){
		printf("%d \n",day[i]);
	}
    max_profit = gain(day,0,total_days-1);
    printf("\nTHE MAXIMUM PROFIT IS = %d\n",max_profit.profit);
}

