#include<stdlib.h>
#include<stdio.h>

float* createFloatArray(int, float);
void editValue(float*, float);

int main(){
    float* p;
    float f = 3.14;
    float* arr;

    arr = createFloatArray(10, 1.0f);
    for (int i=0; i<10; i++)
        printf("%f,  ", arr[i]);
    printf("\n\n");
    
    free(arr);

    p = &f;

    printf("%f, %f\n", f, *p);

    editValue(p, 1.1);
    printf("%f, %f\n", f, *p);

    return 0;
}

float* createFloatArray(int n, const float init){
    float* array = malloc( n*sizeof(float) );
    if (array == NULL)
        return NULL;
    
    for (int i=0; i<n; i++){
        *(array + i) = init;
    }

    return array;
}

void editValue(float* var, const float val){
    *var = val;
}