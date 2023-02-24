#include <iostream>
#include<vector>
#include <limits>
#include <string>
using namespace std;



vector<int> sortArray(vector<int>& nums) { //insertion sort, O(n^2) worst case
    for(int i =1; i<nums.size();i++){
        int j = i-1;
        while(j>=0 && nums[j+1]<nums[j]){
            //swap
            int temp =nums[j+1];
            nums[j+1] = nums[j];
            nums[j] = temp;
            j--;   
        }
    }
    return nums;

}



int main(){
    vector<int> arr ={5,6,7,3,4};
    arr=sortArray(arr);


    

    return 0;
}