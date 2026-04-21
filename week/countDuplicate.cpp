#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    cout << "Enter size of second array: ";
    cin >> n;
    int arr1[m];
    int arr2[n];
    cout << "Enter first sorted array:";
    for(int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    cout << "Enter second sorted array:";
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    int i = 0;
    int j = 0;
    cout << "common Elements:";
    while(i < m && j < n){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
 return 0;
}