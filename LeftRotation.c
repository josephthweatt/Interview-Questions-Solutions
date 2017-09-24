/******************************************************************
* Written by: Joseph Thweatt
* Runtime: Unknown
*
* A left rotation operation on an array of size  shifts each of the
* array's elements  unit to the left. For example, if 1 left rotation
* was performed on array [1,2,3], then the array would become [2,3,1].
* Given an array of n integers and a number d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.
********************************************************************/

void print_rotation(int n, int d, int *a) {
    // value at index 'd' will always end in the back of the array
    int j;
    char *out = malloc(sizeof(char) * n * 2);
    
    for (int i = d; i < n; printf("%d ", a[i++]));
    for (int i = 0; i < d; printf("%d ", a[i++]));

    printf("\n");
}

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    
    print_rotation(n, k, a);
    return 0;
}
