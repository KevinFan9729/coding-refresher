#include <iostream>
#include<vector>
#include <limits>
#include <string>
using namespace std;


void merge(vector<int>& arr, int s, int m, int e){
    // Copy the sorted left & right halfs to temp arrays
    vector<int> L = {arr.begin() + s, arr.begin() + m + 1};
    vector<int> R = {arr.begin() + m + 1, arr.begin() + e + 1};
    int i = 0; // index for L
    int j = 0; // index for R
    int k = s; // index for arr

    while(i<L.size() && j<R.size()){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            k++;
            i++;
        }else{
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    while(i<L.size()){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<R.size()){
        arr[k]=R[j];
        k++;
        j++;
    }
}

vector<int> sortArray(vector<int>& nums, int start, int end) { //merge sort, O(nlogn) worst case
    if(end-start+1==1){//arr of size 1, base case
        return nums;
    }
    int mid = (end+start)/2;
    sortArray(nums, start, mid);//left sub arrary
    sortArray(nums, mid+1, end); //right sub array
    merge(nums,start,mid,end);
    return nums;
}



int main(){
    vector<int> arr ={5,6,7,3,4};
    arr=sortArray(arr,0,arr.size()-1);


    

    return 0;
}