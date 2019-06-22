#include <stdio.h>
#include <stdbool.h>

/*
                        depth == 3

         3              max(12) => 12
       /   \
      5     2           min(12, 23) => 12
     / \   / \
    9  12 5   23        max(9, 12) => 12 , max(5, 23) => 23
   /
  23            

 */


int minimax(int depth, int node_index, bool is_max, int scores[], int h);
int log_2(int n);
int max(int a, int b);
int min(int a, int b);

int main(){
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(scores)/sizeof(scores[0]);
    int height = log_2(n);
    int result = minimax(0, 0, true, scores, height);
    printf("The optimal value is: %d\n", result);
    printf("max(2, 5) = %d\n", max(2, 5));
    printf("min(2, 5) = %d\n", min(2, 5));
    return 0;
}

int max(int a, int b);

int minimax(int depth, int node_index, bool is_max, int scores[], int h){
    if(depth == h){
        return scores[node_index];
    }

    if(is_max){
        return max(minimax(depth+1, node_index*2, false, scores, h),
                   minimax(depth+1, node_index*2 + 1, false, scores, h));
    } else {
        return min(minimax(depth+1, node_index*2, true, scores, h),
                   minimax(depth+1, node_index*2 + 1, true, scores, h));
    }
}

int log_2(int n){
    return (n==1) ? 0 : 1 + log_2(n/2);
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a < b) ? a : b;
}
