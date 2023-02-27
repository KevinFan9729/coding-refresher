#include <iostream>
#include<vector>
#include <limits>
#include <string>
using namespace std;


vector<int> sortArray(vector<int>& nums, int start, int end) { //merge sort, O(n^2) worst case O(nlogn) average
    if(end-start+1<=1){//arr of size 1, base case
        return nums;
    }
    int pivot = end; //taking the end of the arrary as the pviot
    int write_indx = start;
    int temp;
    for(int i = start; i<end; i++){
        if(nums[i]<nums[pivot]){
            temp = nums[write_indx];
            nums[write_indx] = nums[i];
            nums[i] = temp;
            write_indx++;
        }
    }
    //fit the pivot in place
    temp = nums[write_indx];
    nums[write_indx] = nums[pivot];
    nums[pivot] = temp;

    //recurivse call
    sortArray(nums, start, write_indx-1);
    sortArray(nums, write_indx+1, end);


    return nums;
}



int main(){
    vector<int> arr ={5,6,7,3,4};
    vector<int> arr2 ={6,2,4,1,3};

    arr=sortArray(arr,0,arr.size()-1);
    arr2=sortArray(arr2,0,arr2.size()-1);


    

    return 0;
}