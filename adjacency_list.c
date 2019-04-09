//adjacency list
#include<stdio.h>
#include<stdlib.h>
//Creating a structure for main list
typedef struct node{
	int vertex_no;
	int weight;
	struct node *next;
}node;
//creating adjacency list
void adjlistofgraph(FILE *f_source,int total,node *array){
	int i=0,x,y,w,total_weight=0;
	node *trav;
	for(i = 0;i < total;i++){
		array[i].vertex_no = i;
		array[i].next = NULL;
	}
	while(fscanf(f_source,"%d %d %d",&x,&y,&w) ==3){
		node *temp = (node *)malloc(sizeof(node));
		total_weight+=w;
		temp->vertex_no = y-1;
		temp->weight = w;
		temp->next = NULL;
		trav = &(array[x-1]);
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = temp;
	}
	for(i = 0;i < total;i++){
		trav = &(array[i]);
        printf("(%d)->", array[i].vertex_no+1);
		while(trav->next != NULL){
			printf("%d",trav->next->vertex_no+1);
			printf("wt[%d]->",trav->next->weight);
			trav = trav->next;
		}
		printf("\n");
	}
	printf("The total weight is %d",total_weight);
}
int main(){
	FILE *f_source = fopen("nodes.txt","r");
	int total,start;
	fscanf(f_source,"%d %d",&total,&start);
	node array[total];
	printf("%d %d\n",total,start);
	adjlistofgraph(f_source,total,array);
}