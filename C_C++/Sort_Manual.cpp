#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<new>
#include<random>
#include<exception>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
int Maximun(int data[],int size);
int Maximun(vector<int>& data);
int Minimun(int data[],int size);
int Minimun(vector<int>& data);
int Row(int number);
int Power10(int number);
void ProcessRadixSort(int *data,int size,int n,int row,int* MainData);
void MinusRadixCase(int data[],int size,int* MainData);
void ProcessQuickSort(int data[],int low,int high);
void ProcessMergeSort(int* data,int left,int right);
void ProcessHeapSort(int *data,int n,int i);
void ProcessdualpviotQuickSort(int data[],int low,int high);
void btoa(int* a,int* b,int size);
void swap(int& a,int& b);
void cSort(vector<int>& data);
int binarysearchlocate(int data[],int select,int low,int high);
void binarysearchinsertionSort(int data[],int size);
void radixSort(int data[],int size);
void bubbleSort(int data[],int size);
void insertionSort(int data[],int size);
void selectionSort(int data[],int size);
void quickSort(int data[],int size);
void mergeSort(int data[],int size);
void heapSort(int data[],int size);
void countingSort(int data[],int size);
void shellSort(int data[],int size);
void ProcessBucketSort(vector<int>& v,int row);
void bucketSort(int data[],int size);
void bandcSort(int data[],int size);
void dualpviotquickSort(int data[],int size);
void oddevenSort(int data[],int size);
void timSort(int data[],int size)
{
    
}
/*int main()
{
    default_random_engine eng(0);
    srand(0);
    uniform_int_distribution<int> distr;
    static int data[100000];
    for(int i=0;i<100000;i++) 
    {data[i]=distr(eng);}
    long t1,t2;
    double deltatime;
    t1=clock();
    //radixSort(data,sizeof(data)/sizeof(int));
    //bubbleSort(data,sizeof(data)/sizeof(int));
    //insertionSort(data,sizeof(data)/sizeof(int));
    //selectionSort(data,sizeof(data)/sizeof(int));
    //quickSort(data,sizeof(data)/sizeof(int));
    //mergeSort(data,sizeof(data)/sizeof(int));
    //heapSort(data,sizeof(data)/sizeof(int));
    //countingSort(data,sizeof(data)/sizeof(int));
    //shellSort(data,sizeof(data)/sizeof(int));
    //bucketSort(data,sizeof(data)/sizeof(int));
    //sort(&data[0],&data[sizeof(data)/sizeof(int)]);
    //bandcSort(data,sizeof(data)/sizeof(int));
    //dualpviotquickSort(data,sizeof(data)/sizeof(int));
    //oddevenSort(data,sizeof(data)/sizeof(int));
    //binarysearchinsertionSort(data,sizeof(data)/sizeof(int));
    timSort(data,sizeof(data)/sizeof(int));
    t2=clock();
    //for(int i : data) cout << i << " " ;
    deltatime=(double)(t2-t1)/1000.0;
    cout << "\nTime = " << setprecision(3) << deltatime ; 
    return EXIT_SUCCESS;
}*/
int Maximun(int data[],int size)
{
    int Max=data[0];
    for(int i=1;i<size;i++)
    {
        if(Max<data[i]) Max=data[i];
    }
    return Max;
}
int Maximun(vector<int>& data)
{
    int Max=data[0];
    for(int i=1;i<data.size();i++)
    {
        if(Max<data[i]) Max=data[i];
    }
    return Max;
}
int Minimun(int data[],int size)
{
    int Min=data[0];
    for(int i=1;i<size;i++)
    {
        if(Min>data[i]) Min=data[i];
    }
    return Min;
}
int Minimun(vector<int>& data)
{
    int Min=data[0];
    for(int i=1;i<data.size();i++)
    {
        if(Min>data[i]) Min=data[i];
    }
    return Min;
}
int Row(int a)
{
    int count=0;
    while(a)
    {
        a/=10;
        count++;
    }
    return count;
}
void ProcessRadixSort(int* data,int size,int n,int row,int* MainData)
{
    int* data2 = new int[size];
    int count[10]={0};
    for(int i=0;i<size;i++) count[abs(data[i]/Power10(row-n))%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=size-1;i>=0;i--)
    {
        data2[count[abs(data[i]/Power10(row-n))%10]-1]=data[i];
        count[abs(data[i]/Power10(row-n))%10]--;
    }
    if(n) ProcessRadixSort(data2,size,n-1,row,MainData);
    else MinusRadixCase(data,size,MainData);
    delete[] data2;
}
void MinusRadixCase(int data[],int size,int* MainData)
{
    int count=0,index;
    for(int i=0;i<size;i++) if(data[i]<0)count++;
    index=count;
    for(int i=0;i<size;i++)
    {
        if(data[i]<0) {MainData[count-1]=data[i];count--;}
        else {MainData[index]=data[i];index++;}
    }
}
int Power10(int number)
{
    int re=1;
    for(int i=0;i<number;i++) re*=10;
    return re;
}
void btoa(int* a,int* b,int size)
{
    for(int i=0;i<size;i++) *(a+i)=*(b+i);
}
void swap(int& a,int& b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void bubbleSort(int data[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=1;j<size-i;j++)
        {
            if(data[j-1]>data[j]) swap(data[j-1],data[j]);
        }
    }
}
void radixSort(int data[],int size)
{
    int Max,Min,row;
    Max=Maximun(data,size);
    Min=Minimun(data,size);
    Row(Max) > Row(Min) ? row=Row(Max) : row=Row(Min);
    ProcessRadixSort(data,size,row,row,data);
}
void insertionSort(int data[],int size)
{
    for(int i=1;i<size;i++)
    {
        int temp=data[i];
        int j;
        for(j=i;j>=1;j--)
        {
            data[j]=data[j-1];
            if(data[j-1]<=temp) break;
        }
        data[j]=temp;
    }
}
void selectionSort(int data[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int temp=i;
        for(int j=i+1;j<size;j++)
        {
            if(data[temp]>data[j]) temp = j;
        }
        if(temp!=i) swap(data[temp],data[i]);
    }
}
void quickSort(int data[],int size)
{
    ProcessQuickSort(data,0,size-1);
}
void ProcessQuickSort(int data[],int low,int high)
{
    if(low<high)
    {
    int a=low,b=(low+high)/2,c=high;
    if(data[a]>data[b]) swap(data[a],data[b]);
    if(data[c]<data[b]) swap(data[c],data[b]);
    swap(data[b],data[c]);
    int p=high,i=low,j=p-1;
    while(i<=j)
    {
        if(data[p]>data[i]) i++;
        else {swap(data[i],data[j]);j--;}
    }
    swap(data[i],data[p]);
    ProcessQuickSort(data,low,i-1);
    ProcessQuickSort(data,i+1,high);
    }
}
void ProcessMergeSort(int* data,int left,int right)
{
   if(left<right)
   {
        int mid=(left+right)/2;
        ProcessMergeSort(data,left,mid);
        ProcessMergeSort(data,mid+1,right);
        int* temp = new int [(right-left)+1];
        int index=0,i=left,j=mid+1;
        for(;i<=mid && j<=right ;index++)
        {
            if(data[i]<data[j]){temp[index]=data[i];i++;}
            else{temp[index]=data[j];j++;}
        }
        while(i<=mid){temp[index]=data[i];i++;index++;}
        while(j<=right){temp[index]=data[j];j++;index++;}
        index=0;
        for(int i=left;i<=right;i++) 
        {
            data[i]=temp[index];index++;
        }
        delete[] temp;
   }
}
void mergeSort(int data[],int size)
{
    ProcessMergeSort(data,0,size-1);
}
void heapSort(int data[],int size)
{
    for(int i=(size-1)/2;i>=0;i--)
    {
        ProcessHeapSort(data,size,i);
    }
    for(int i=size-1;i>=0;i--)
    {
        swap(data[0],data[i]);
        ProcessHeapSort(data,i,0);
    }
}
void ProcessHeapSort(int *data,int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && data[largest]<data[left]){largest=left;}
    if(right<n && data[largest]<data[right]){largest=right;}
    if(largest!=i){swap(data[i],data[largest]);ProcessHeapSort(data,n,largest);} 
}
void countingSort(int data[],int size)
{
    int Min,Max;
    Min=Minimun(data,size);
    Max=Maximun(data,size);
    try
    {
        int *count = new int [Max-Min+1]();
        int *arr = new int [size];
        for(int i=0;i<size;i++) count[data[i]-Min]++;
        for(int i=1;i<=Max-Min;i++) 
        count[i]+=count[i-1];
        for(int i=size-1;i>=0;i--)
        {
            arr[count[data[i]-Min]-1]=data[i];
            count[data[i]-Min]--;
        }
    btoa(data,arr,size);
    delete[] count,arr;
    }
    catch(const bad_array_new_length &e)
    {
        cout << e.what() << endl;
    }
}
void shellSort(int data[],int size)
{   
    for(int gap=size/2;gap>0;gap/=2)
    {
        for(int i=gap;i<size;i++)
        {
            int temp=data[i];
            int j;
            for(j=i;j>=gap;j-=gap)
            {
                data[j]=data[j-gap];
                if(data[j-gap]<=temp) break;
            }
            data[j]=temp;
        }
    }
}
void ProcessBucketSort(vector<int>& v,int row)
{
    vector<int> decimal[10];
    for(auto itr : v)
    {
        decimal[abs(itr/Power10(row))%10].push_back(itr);
    }
    if(row>0)for(int i=0;i<10;i++){if(decimal[i].size()>1) ProcessBucketSort(decimal[i],row-1);}
    for(int i=0,j=0;j<10;j++)
    {
       for(int k=0;k<decimal[j].size() && !decimal[j].empty();k++)
       {
           v[i]=decimal[j][k];i++;
       }
       decimal[j].clear();
    }
}
void bucketSort(int data[],int size)
{
    int Max,Min;
    Max=Maximun(data,size);
    Min=Minimun(data,size);
    vector<int> Minus,Plus;
    for(int i=0;i<size;i++)
    {
        if(data[i]<0) Minus.push_back(data[i]);
        else Plus.push_back(data[i]);
    }
    if(Minus.size()!=0){
        ProcessBucketSort(Minus,Row(Min)-1);
        }
    if(Plus.size()!=0){ProcessBucketSort(Plus,Row(Max)-1);}
    int i=0;
    for(int j=Minus.size()-1;j>=0;i++,j--) data[i]=Minus[j];
    for(int j=0;i<size;i++,j++) data[i]=Plus[j];
    Minus.clear();
    Plus.clear();
}
void cSort(vector<int>& data)
{
    int Min,Max,size=data.size();
    Min=Minimun(data);
    Max=Maximun(data);
    int *count = new int [Max-Min+1]();
    int *arr = new int [size];
    for(int i=0;i<size;i++) count[data[i]-Min]++;
    for(int i=1;i<=Max-Min;i++) 
    count[i]+=count[i-1];
    for(int i=size-1;i>=0;i--)
    {
           arr[count[data[i]-Min]-1]=data[i];
        count[data[i]-Min]--;
    }
    data.clear();
    for(int i = 0;i<size;i++)
    data.push_back(arr[i]);
    delete[] count,arr;
}
void bandcSort(int data[],int size)
{
    int Max,Min;
    Max=Maximun(data,size);
    Min=Minimun(data,size);
    unsigned range=Max-Min;
    int intival=(int)ceil(log2(range));
    vector<int>* bucket = new vector<int> [intival];
    unsigned r=range/intival;
    for(int i=0;i<size;i++)
    {
        int bound=Min;
        for(int j=0;j<intival-1;j++)
        {
            bound+=r;
            if(data[i]<bound)
            {
                bucket[j].push_back(data[i]);
                goto Skip;
            }
        }
        bucket[intival-1].push_back(data[i]);
        Skip:;
    }
    int index=0;
    for(int i=0;i<intival;i++)
    {
       cSort(bucket[i]);
       for(auto itr : bucket[i])
        {
            data[index]=itr;index++;
        }
    }
    delete[] bucket;
}
void ProcessdualpviotQuickSort(int data[],int low,int high)
{
    if(low<high)
    {
        int p1=low,p2=high,i,j,k;
        i=p1;j=p2;k=i+1;
        if(data[p1]>data[p2]) swap(data[p1],data[p2]);
        while(k<j)
        {
            if(data[k]<data[p1]) {i++;swap(data[i],data[k]);}
            else
            if(data[k]>data[p2]) {j--;swap(data[j],data[k]);continue;}
            k++;
        }
        swap(data[p1],data[i]);
        swap(data[p2],data[j]);
        ProcessdualpviotQuickSort(data,p1,i-1);
        ProcessdualpviotQuickSort(data,i+1,j-1);
        ProcessdualpviotQuickSort(data,j+1,p2);
    }
}
void dualpviotquickSort(int data[],int size)
{
    ProcessdualpviotQuickSort(data,0,size-1);
}
void oddevenSort(int data[],int size)
{
    bool isSorted=false;
    while(!isSorted)
    {
        isSorted=true;
        for(int i=1;i<=size-2;i+=2)
        {
            if(data[i]>data[i+1])
            {
                isSorted=false;
                swap(data[i],data[i+1]);
            }
        }
        for(int i=0;i<=size-2;i+=2)
        {
            if(data[i]>data[i+1])
            {
                isSorted=false;
                swap(data[i],data[i+1]);
            }
        }
    }
}
int binarysearchlocate(int data[],int select,int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        if(data[mid]==select) return mid;
        else if(data[mid]<select) return binarysearchlocate(data,select,mid+1,high);
        else return binarysearchlocate(data,select,low,mid-1);
    }
    else
    {
        if(select < data[low]) return low ;else return  low+1;
    }
}
void binarysearchinsertionSort(int data[],int size)
{
    for(int i=1;i<size;i++)
    {
        int select = data[i];
        int locate = binarysearchlocate(data,select,0,i-1);
        int j;
        for(j=i;j>locate;j--) data[j]=data[j-1];
        data[j]=select;
    }
}