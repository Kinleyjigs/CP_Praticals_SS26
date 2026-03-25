#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int result = 0;
        
        // Greedy approach: try each bit from MSB to LSB
        for(int bit = 29; bit >= 0; bit--){
            int candidate = result | (1 << bit);
            
            // Check if there exists a subarray of length k where AND with candidate equals candidate
            bool found = false;
            for(int i = 0; i <= n - k; i++){
                int and_val = a[i];
                for(int j = i + 1; j < i + k; j++){
                    and_val &= a[j];
                }
                
                // Check if this subarray satisfies the candidate value
                if((and_val & candidate) == candidate){
                    found = true;
                    break;
                }
            }
            
            if(found){
                result = candidate;
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}
