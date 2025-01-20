/*Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].*/

#include <iostream>
using namespace std;
int main (){
    int arr[5], target, index1 = -1, index2 = -1;
    for (int i = 0; i < 5; i++){
        cout << "enter array number: ";
        cin >> arr[i];
    }
    cout << "Enter target: ";
    cin >> target;
    for(int i = 0; i < 4; i++){
        for (int j = i+1; j<5; j++){
            if(arr[i] + arr[j] == target){
                index1 = i;
                index2 = j;
                break;
            }
        }
    }
    cout << index1 << ", " << index2;
}