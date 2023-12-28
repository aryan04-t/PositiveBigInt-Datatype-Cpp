#include"positivebigint.h"


int main(){
    
    try{
        string s1, s2;
        cin >> s1 >> s2;

        int n;
        cin >> n;
    
        PositiveBigInt prev2 = s1;
        PositiveBigInt prev1 = s2;
        PositiveBigInt curr("0");

        for (int i = 2; i < n; ++i) { 
            PositiveBigInt temp = prev1 * prev1; 
            curr = prev2 + temp; 
            prev2 = prev1; 
            prev1 = curr; 
        }

        cout << curr;
    
    }
    catch(int num){
        if(num == 101){
            cout << endl << endl;
            cout << "{ " << endl;
            cout << "   ERROR!!!" << endl;
            cout << endl; 
            cout << "   # Try Initializing PositiveBigInt with a \"Valid Number\"." << endl;
            cout << endl; 
            cout << "   --> PositiveBigInt has theoretical range of 0 to infinity." << endl; 
            cout << "   --> You cannot give input of negative numbers to initialize PositiveBigInt." << endl; 
            cout << "   --> PositiveBigInt only represents \"Positive Integers\", that's why don't give input of decimal numbers." << endl; 
            cout << "   --> PositiveBigInt processes numbers in decimal format." << endl; 
            cout << "   --> In the initializing string of PositiveBigInt There should be only digits from 0-9." << endl; 
            cout << "} " << endl; 
            cout << endl << endl; 

        }
    }

    return 0;
}