#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        int sum = accumulate(ar, ar + n, 0);
        int a=0, b=0;
        bool found = false;
        for(int i=0; i<n-2; i++) {
            a+=ar[i];
            b=0;
            for(int j=i+1; j<n-1; j++) {
                b+=ar[j];
                int c=sum-b-a;
                int p=a%3;
                int q=b%3;
                int r=c%3;
                if((p==q && q==r) || (p!=q && p!=r && q!=r)) {
                    // cout<<a<<" "<<b<<" "<< c<<endl;
                    cout << i+1 << " " << j+1 << endl;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) cout << "0 0" << endl;
    }
}