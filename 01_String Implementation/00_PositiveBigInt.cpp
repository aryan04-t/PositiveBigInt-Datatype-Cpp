#include<iostream> 
#include<vector> 
#include<string> 
using namespace std; 


class PositiveBigInt{
    private:
        string num; 
        PositiveBigInt() {}

    public:

        PositiveBigInt(string s){ 

            int n = s.length(); 
            char digit; 

            for(int i = n-1; i >= 0; i--){
                if(s[i] >= 48 && s[i] <= 57){
                    digit = s[i]; 
                    num.push_back(digit); 
                }
                else{
                    throw 101;
                }
            }
     
            while(!num.empty() && (num.back() == '0')){
                num.pop_back();
            }

            if(num.empty()){
                num.push_back(char(0 + '0'));
            }

        }


        PositiveBigInt(const PositiveBigInt& copy){
            
            this->num = "";
            this->num = copy.num;

        }


        string toString();
        PositiveBigInt betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, int i);

        friend ostream& operator<<(ostream& os, const PositiveBigInt &obj);
        void operator=(const PositiveBigInt& obj);
        PositiveBigInt operator+(PositiveBigInt &obj);
        PositiveBigInt operator*(PositiveBigInt &obj);
};


string PositiveBigInt::toString(){

    return this->num;

}


ostream& operator<<(ostream& os, const PositiveBigInt &obj){

    int n = obj.num.length();
    
    for(int i=n-1; i >= 0; i--){
        os << (obj.num[i]);
    }

    return os;
}


void PositiveBigInt::operator=(const PositiveBigInt& copy){ 
    
    this->num = copy.num;

}


PositiveBigInt PositiveBigInt::operator+(PositiveBigInt &obj){

    PositiveBigInt ans; 
    int n = this->num.length(); 
    int m = obj.num.length(); 
    
    if(m > n){
        PositiveBigInt temp(*this);
        *this = obj; 
        obj = temp; 

        n = this->num.length();
        m = obj.num.length();
    }

    short data; 
    short digit; 
    short carry = 0; 
    
    for(int i=0; i < m; i++){
        data = short(this->num[i] - '0') + short(obj.num[i] - '0') + carry; 
        digit = data % 10; 
        carry = data / 10; 
        ans.num.push_back(char(digit + '0')); 
    }

    int i = m; 
    int temp = n; 
    while(i != temp){
        data = short(this->num[i] - '0') + carry;
        digit = data % 10;
        carry = data / 10;
        ans.num.push_back(char(digit + '0'));
        i++;
    }

    if(carry){
        ans.num.push_back(char(1 + '0'));
    }

    return ans;

} 


PositiveBigInt PositiveBigInt::betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, int i){

    int n = ans.num.length();
    int m = ans2.num.length();

    short data;
    short digit;
    short carry = 0;

    int j=0;
    for(; i < n; i++, j++){ 
        data = short(ans.num[i] - '0') + short(ans2.num[j] - '0') + carry; 
        digit = data % 10; 
        carry = data / 10; 
        ans.num[i] = char(digit + '0');
    }

    for(; j < m; j++){
        data = short(ans2.num[j] - '0') + carry; 
        digit = data % 10; 
        carry = data / 10; 
        ans.num.push_back(char(digit + '0'));
    }

    if(carry){
        ans.num.push_back(char(1 + '0'));
    }

    return ans;

}


PositiveBigInt PositiveBigInt::operator*(PositiveBigInt &obj){


    PositiveBigInt ans; 
    int n = this->num.length(); 
    int m = obj.num.length(); 

    if( (m == 1 && obj.num[0] == 0) || (n == 1 && this->num[0] == 0)){
        return PositiveBigInt("0");
    }

    if(m > n){
        PositiveBigInt temp(*this); 
        *this = obj; 
        obj = temp; 

        n = this->num.length();
        m = obj.num.length();
    }


    short multiply_data;
    short multiply_digit;
    short multiply_carry = 0;
    
    int i = 0;
    for(int j=0; j < n; j++){

        multiply_data = (short(obj.num[i] - '0') * short(this->num[j] - '0')) + multiply_carry; 
        multiply_digit = multiply_data % 10;
        multiply_carry = multiply_data / 10;

        ans.num.push_back(char(multiply_digit + '0'));

        if(multiply_carry > 0 && j == n-1){
            ans.num.push_back(char(multiply_carry + '0'));
        }
    }


    for(int i=1; i < m; i++){
        
        multiply_carry = 0; 

        PositiveBigInt ans2; 

        for(int j=0; j < n; j++){

            multiply_data = (short(obj.num[i] - '0') * short(this->num[j] - '0')) + multiply_carry; 
            multiply_digit = multiply_data % 10;
            multiply_carry = multiply_data / 10;

            ans2.num.push_back(char(multiply_digit + '0'));

            if(multiply_carry > 0 && j == n-1){
                ans2.num.push_back(char(multiply_carry + '0'));
            }

        }

        ans = betweenMultiplicationAdd(ans, ans2, i);

    }

    return ans;

}


int main(){
    
    try{
    
        string s1, s2;
        cin >> s1 >> s2;

        short n;
        cin >> n;
    
        PositiveBigInt prev2 = s1;
        PositiveBigInt prev1 = s2;
        PositiveBigInt curr("0");

        for (short i = 2; i < n; ++i) { 
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