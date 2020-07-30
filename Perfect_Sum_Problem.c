//Solution to GFG Perfect Sum Problem
/* I have adopted the Dynamic Programming's tabulation approach to solve the problem in C 
INPUTS:
tc = total # testcases 
n = array size 
s = required sum
OUTPUT:
# subsets of input array that give the given sum s
Note : The array sizes and datatypes are fixed as per gfg problem constraint
*/

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
           
           //arr[]> sub_sum
           if( arr[i-1] > s){
            t[i][j] = t[i-1][j];
           }
            //arr[]<=sub_sum (taken & not taken)
            else{
                t[i][j] = ( t[i-1][j] + t[i-1][ j - arr[i-1] ] ) % 1000000007;
            }
       }
   }
   
  /* 
  // UNCOMMENT TO SEE THE SUBPROBLEMS CALCULATION 2D TABULATION MATRIX
   for( int i =0 ; i <= n ; i++){
       printf("\n");
      for( int j = 0 ; j<=s ; j++){
          
          printf("%d\t",t[i][j]);
      }
   } */
   printf("%d\n", t[n][s]);
}

int main() {

    int tc , n ; 
	scanf("%d",&tc);
	for(int i =0 ; i< tc ; i++){
	    scanf("%d",&n);
	     int s;
	    for( int j =0 ; j < n ; j++){
	        scanf("%d",&arr[j]);
	        
	    }
	    scanf("%d",&s);
	    count(n , s);
	    
	}
	return 0;
}