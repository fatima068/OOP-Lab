/* You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    float area;
    int i, j, maxArea = 0; 
    int height[10]; //assuming size of array is always 10

    for (int i=0; i<10; i++)
    {
        cout << "Enter your array element: ";
        cin >> height[i];
    }
    
    for (int i = 0; i < 10; i++) 
    {
        for (int j = i + 1; j < 10; j++) 
        {
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
        }
    }
    
    cout << "Maximum area is " << maxArea;
}
