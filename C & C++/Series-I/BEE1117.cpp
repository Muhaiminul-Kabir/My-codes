#include<bits/stdc++.h>
using namespace std;
int main(){
    double x;
    stack<double> z;
    double count = 0;
    double sum = 0;
    int p_count = 0;
    bool valid = true;
    while(true){
        cin >> x;
        if(x < 0){
            valid = false;
        }
        if(x >=0){
            if(valid){
                p_count++;
            }
            z.push(x);
            
        
        }
        if(!valid){
            cout << "not incaloh"<<endl;
        }
        if(x >= 0){
            valid = true;
        
        }
        count++;
        
        if(p_count == 2){
           double t;
           int size = z.size();
           for(int i = 0;i < size;i++) {
                cout<<z.top()<<" ";
                t = z.top();
                z.pop();
                sum += t;
           }
           
           p_count = 0;
           break;
        }
    }
    cout << "m" <<sum/count<< (double)sum;
    
}
