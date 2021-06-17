#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Array{
    int *arr;
    int max,n;
};

void init(struct Array *a){  
    a->arr=(int *)malloc(10 * sizeof(int));
    a->max=MAX;
    a->n=0;
}

int size(struct Array a)
{
    return a.n;
}

int capacity(struct Array a)
{
    return a.max;
}

int is_empty(struct Array a)
{
    return a.n > 0 ? a.n : 0;
}

int at(struct Array a,int i)
{
    return a.arr[i];
}

//this is needed in C because array out of bounds gives an error in C
//But it is not needed in C++ because : https://stackoverflow.com/questions/1239938/accessing-an-array-out-of-bounds-gives-no-error-why
// instead you could only just increase the value of max
void increaseSize(struct Array *a)
{
    int *newarr;
    newarr = (int *)malloc(a->n * 2 * sizeof(int));
    for (int i = 0; i < a->n; i++)
    {
        newarr[i] = a->arr[i];
    }
    a->arr = newarr;
    a->max = a->n * 2;
    printf("\nincreased size");
}

//same explanation as above
void decreaseSize(struct Array *a)
{
    int *newarr;
    newarr = (int *)malloc((a->max / 2) * sizeof(int));
    for (int i = 0; i < a->n; i++)
    {
        newarr[i] = a->arr[i];
    }
    a->arr = newarr;
    a->max = a->max / 2;
    printf("\ndecreased size");
}

void checkSize(struct Array *a)
{
    if (a->n == a->max)
        increaseSize(a);
    else if (a->n == a->max / 4)
        decreaseSize(a);
}

void printArray(struct Array a)
{
    printf("\n[");
    for (int i = 0; i < a.n; i++)
    {
        printf("%d ", *(a.arr + i));
    }
    printf("]\n");
}

void push(struct Array *a, int x)
{
    checkSize(a);
    a->arr[a->n++] = x;
}

void insert(struct Array *a, int index, int x)
{
    if (index > a->n - 1)
    {
        printf("Not allowed to insert at index greater than %d",a->n-1);
        return;
    }
    checkSize(a);
    for (int i = a->n - 1; i >= index; i--)
    {
        a->arr[i + 1] = a->arr[i];
    }
    a->arr[index] = x;
    a->n++;
}

void prepend(struct Array *a,int x)
{
    checkSize(a);
    for (int i = a->n - 1; i >= 0; i--)
    {
        a->arr[i + 1] = a->arr[i];
    }
    a->arr[0] = x;
    a->n++;
}

int pop(struct Array *a)
{
    checkSize(a);
    return a->arr[--a->n];
}

void removeAtIndex(struct Array *a, int index)
{
    for (int i = index; i < a->n - 1; i++)
    {
        a->arr[i] = a->arr[i + 1];
    }
    a->n--;
    checkSize(a);
}

void remover(struct Array *a, int x)
{
    for (int i = 0; i < a->n; i++)
    {
        if (a->arr[i] == x)
            removeAtIndex(a,i);
    }
    checkSize(a);
}

int find(struct Array a, int x)
{
    for (int i = 0; i < a.n; i++)
    {
        if (a.arr[i] == x)
            return i;
    }
    return -1;
}

void arrdetails(struct Array a){
    printf("Array : \n");
    printArray(a);
    printf("\nSize : %d        Max : %d\n",a.n,a.max);
}

int main()
{
    struct Array a1;
    init(&a1);
    arrdetails(a1);
    for(int i=0;i<20;i++){
        push(&a1,i);
    }
    arrdetails(a1);

    printf("\nAt index 6 : %d\n",at(a1,6));
    if(!is_empty(a1)) printf("Empty");
    else printf("Not empty");

    insert(&a1,14,8008);
    insert(&a1,5,588);
    arrdetails(a1);

    printf("\n%d",pop(&a1));
    printf("\n%d\n",pop(&a1));

    prepend(&a1,999);
    push(&a1,654);
    push(&a1,64);
    push(&a1,34);
    push(&a1,83);
    push(&a1,984);
    arrdetails(a1);

    removeAtIndex(&a1,18);
    remover(&a1,999);
    arrdetails(a1);

    printf("\nFound 34 at : %d\n",find(a1,34));
    printf("Found 999 at : %d\n",find(a1,999));
    printf("Found 10 at : %d\n",find(a1,10));
    printf("Found 110000 at : %d\n",find(a1,110000));

    arrdetails(a1);
}
