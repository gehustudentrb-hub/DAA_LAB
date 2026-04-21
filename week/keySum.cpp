#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int key;
    cout << "Enter key: ";
    cin >> key;
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    bool found = false;
    while(i < j){
        int sum =
        arr[i] + arr[j];
        if(sum == key){
            cout << "Elements Found: " << arr[i] << " and "<< arr[j];
            found = true;
           break;
        }
        else if(sum < key){
            i++;
        }
        else {
            j--;
        }
    }
     if(!found)    {
        cout << "Not found!!!";
    }
 return 0;
}