#include<iostream>
#include<time.h>

using namespace std;
void swap(int arr[], int i, int j)
{
 int temp;
 temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
int partition(int arr[],int l,int r)
{
 int pivot=arr[r];
 int i=l-1;
 for(int j=l;j<r;j++)
 {
 if(arr[j]<pivot)
 {
 i++;
 swap(arr,i,j);
 }
 }
 swap(arr,i+1,r);
 return i+1;
}
void quicksort(int arr[],int l,int r)
{
 if(l<r)
 {
 int pi=partition(arr,l,r);
 quicksort(arr,l,pi-1);
 quicksort(arr,pi+1,r);
 }
}
void merge(int arr[], int l, int mid, int r)
{
 int n1=mid-l+1;
 int n2=r-mid;
 int a[n1],b[n2];
 for(int i=0;i<n1;i++)
 {
 a[i]=arr[l+i];
 }
 for(int i=0;i<n2;i++)
 {
 b[i]=arr[mid+1+i];
 }
 int i=0,j=0,k=l;
 while(i<n1 && j<n2){
 if(a[i]<b[j])
 {
 arr[k]=a[i];
 i++,k++;
 }
 else {
 arr[k]=b[j];
 j++,k++;
 }
 }
 while(i<n1)
 {
 arr[k]=a[i];
 i++,k++;
 }
 while(j<n2)
 {
 arr[k]=b[j];
 j++,k++;
 }
}
void mergesort(int arr[],int l,int r)
{
 if(l<r)
 {
 int mid=(l+r)/2;
 mergesort(arr,l,mid);
 mergesort(arr,mid+1,r);
 merge(arr,l,mid,r);
 }
}
void selectionSort(int arr[], int n)
{
 int i, j, min_idx;

 for (i = 0; i < n-1; i++)
 {
 min_idx = i;
 for (j = i+1; j < n; j++)
 if (arr[j] < arr[min_idx])
 min_idx = j;

 swap(arr, min_idx, i);
 }
}
void insertionSort(int arr[], int n)
{
 int i, key, j;
 for (i = 1; i < n; i++)
 {
 key = arr[i];
 j = i - 1;
 while (j >= 0 && arr[j] > key)
 {
 arr[j + 1] = arr[j];
 j = j - 1;
 }
 arr[j + 1] = key;
 }
}
int main(){
 int i;
 int A[50];
 cout<<"\t\t\t\t-YASH GREWAL-\n";
 cout<<"\n THE ARRAY :\n";
 for(i=0;i<50;i++)
 {
 A[i]=rand();
 cout<<A[i]<<"  ";
 }
 int B[50],C[50],D[50];
 for(i=0;i<50;i++)
 {
 B[i]=A[i];
 C[i]=A[i];
 D[i]=A[i];
 }
 clock_t start,end;
 start=clock();
 mergesort(A,0,49);
 end=clock();
 cout<<"\n\nMERGE SORT : ";
 for(i=0;i<50;i++)
 cout<<A[i]<<" ";
 double timetaken=1000.00*(end-start)/CLOCKS_PER_SEC;
 cout<<"\nTime taken (MERGE SORT) = "<<timetaken;
 cout<<endl;

 start=clock();
 quicksort(B,0,49);
 end=clock();
 cout<<"\n\nQUICK SORT : ";
 for(i=0;i<50;i++)
 cout<<B[i]<<" ";
 timetaken=1000.00*(end-start)/CLOCKS_PER_SEC;
 cout<<"\nTime taken (QUICK SORT) = "<<timetaken;
 cout<<endl;
 start=clock();
 selectionSort(C, 50);
 end=clock();
 cout<<"\n\nSELECTION SORT : ";
 for(i=0;i<50;i++)
 cout<<C[i]<<" ";
 timetaken=1000.00*(end-start)/CLOCKS_PER_SEC;
 cout<<"\nTime taken (QUICK SORT) = "<<timetaken;
 cout<<endl;
 start=clock();
 insertionSort(D,50);
 end=clock();
 cout<<"\n\nINSERTION SORT : ";
 for(i=0;i<50;i++)
 cout<<D[i]<<" ";
 timetaken=1000.00*(end-start)/CLOCKS_PER_SEC;
 cout<<"\nTime taken (INSERTION SORT) = "<<timetaken;
 cout<<endl;
 }



