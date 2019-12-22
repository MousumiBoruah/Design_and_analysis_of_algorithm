#include<iostream>
#include"merge_sort.h"
using namespace std;

main(){
	
	int *points,min,distance,left_point,right_point;
	points = new int[6];
	cout << "Enter the points" << endl;

	for (int i = 0; i < 6; ++i)
	{
		cin >> points[i];
	}
	merge_sort(points , 0 , 5);
	for (int i = 0; i < 6; ++i)
	{
		cout << "the points are" << points[i] << endl;
	}
     
    min = points[1] - points[0];
	for(int j = 1 ;j < 6;j++){
		distance = points[j+1] - points[j];
		if(min > distance){
			min = distance;
		    left_point = points[j];
		    right_point = points[j+1];
          }
       
	}
    
	cout << " The closest points are" << left_point <<"&" << right_point <<"with distance =" << min<<" units "<< endl;
 	
}