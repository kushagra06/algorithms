#include<iostream>
#include<stack>
using namespace std;
int getMaxArea(int hist[], int n)
{
    stack<int> s;

    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar

    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else
        {
            tp = s.top();  // store the top index
            s.pop();                                                                                                                   
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);                                                  
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main()
{

    int hist[] = {1,1,1,1,1,5,6,1,1,1,1};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
