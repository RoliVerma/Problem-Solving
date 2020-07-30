//Solution to GFG Perfect Sum Problem

#include <stdio.h>
#include <string.h>
int t[1001][1001];
int arr[1001];

void count(int n ,  int s){
    //t is of size assume [n+1][s+1]
    
    //initialise 1st row =0
   for(  int i =0 ; i<= s ; i++){
       t[0][i] = 0;
   }
      //initialise 1st col =1
   for( int i =0 ; i<= n ; i++){
       t[i][0] = 1;
   }
   
   for( int i =1 ; i <= n ; i++){
       for(  int j = 1 ; j<=s ; j++){
           
           //arr[]>s
           if( arr[i-1] > s){
            t[i][j] = t[i-1][j];
           }
            //arr[]<=s (taken & not taken)
            else{
                t[i][j] = t[i-1][j] + t[i-1][ j - arr[i-1] ];
            }
       }
   }
   
  /* 
  // UNCOMMENT TO SEE THE 2D SUBPROBLEMS CALCULATION MATRIX
   for( int i =0 ; i <= n ; i++){
       printf("\n");
      for( int j = 0 ; j<=s ; j++){
          
          printf("%d\t",t[i][j]);
      }
   } */
   printf("%d\n", t[n][s] % 1000000007);
}

int main() {
    int tc , n ;
	scanf("%d",&tc);
	for(int i =0 ; i< tc ; i++){
	    scanf("%d",&n);
	     int s;
	    for( int j =0 ; j < n ; j++){
	        scanf("%d",&arr[j]);
	        //printf("%d\t",arr[j]);
	    }
	    scanf("%d",&s);
	    count(n , s);
	    
	}
	return 0;
}