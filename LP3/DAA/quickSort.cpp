#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int partition(vi &arr,int low,int high){
int p = arr[low];
int i = low;
int j = high;
while(i<j){
    do{
        i++;
    }while(arr[i]<=p && i<high);

    do{
        j--;
    }while(arr[j]>p && j>low);

    if(i<j) swap(arr[i],arr[j]);
}
swap(arr[j],arr[low]);
return j;
}

void quickSortR(vi &arr,int low,int high){
    if(low<high){
        int random = rand() %(high-low) + low;
        swap(arr[low],arr[random]);
        int p = partition(arr,low,high);
        quickSortR(arr,low,p);
        quickSortR(arr,p+1,high);
    }
}

void quickSort(vi &arr,int low,int high){
    if(low<high){
    int p = partition(arr,low,high);
    quickSort(arr,low,p);
    quickSort(arr,p+1,high);
    }
}

int main(){
    vi a = {3,4,5,1};
    int low=0;
    int high=a.size();
    quickSort(a,low,high);
    for(int i:a) cout<<i<<' ';
    cout<<'\n';
    return 0;
}