#include <stdio.h>

//Fuction Prototype
void QuickSort(int*,int,int);
int Partition(int*,int,int);
void swap(int*,int*);

int main()
{
    int n,i,arr[100];
    int fst_max_freq = 0;
    int fst_max_freq_value = arr[0];
    int snd_max_freq = 0;
    int snd_max_freq_value = arr[n-1];
    int count = 1;

//Scanning the length
    printf("Enter the length: ");
    scanf("%d",&n);

//Scanning of array
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

//Sorting the array  
QuickSort(arr,0,n-1);


for(i=0;i<n-1;i++)
{
    if(arr[i] == arr[i+1])
    {
        count++;
    }
    else
    {
        if(count > fst_max_freq)
        {
            snd_max_freq = fst_max_freq;
            snd_max_freq_value = fst_max_freq_value;
            fst_max_freq = count;
            fst_max_freq_value = arr[i];
        }
        count = 1;
    }
}
if(count > fst_max_freq)
{
    snd_max_freq = fst_max_freq;
    snd_max_freq_value = fst_max_freq_value;
    fst_max_freq = count;
    fst_max_freq_value = arr[i-1];
}

//printing the frequency findings
printf("%d:%d %d:%d",fst_max_freq,fst_max_freq_value,snd_max_freq,snd_max_freq_value);
    return 0;
}

void QuickSort(int *a,int lb,int ub)
{
    int loc;
    if(lb < ub)
    {

        //Partitioning the array
        loc = Partition(a,lb,ub);

        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);
    }
}

int Partition(int *a,int lb,int ub)
{
    int pivot = *(a+lb);
    int start = lb;
    int end = ub;
    while(start < end)
    {
        while(*(a+start) <= pivot)
        {
            start++;
        }
        while(*(a+end) > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(a+start,a+end);
        }
    }
    swap(a+lb,a+end);
    return end;
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}