#include<iostream> 
#include<vector> 
#include<string> 
using namespace std; 


class PositiveBigInt{
    private:
        vector<short> num; 
        PositiveBigInt() {}

    public:

        PositiveBigInt(string s){ 

            short n = s.length(); 
            short digit; 

            for(short i = n-1; i >= 0; i--){
                if(s[i] >= 48 && s[i] <= 57){
                    digit = s[i] - '0';
                    num.push_back(digit);
                }
                else{
                    throw 101;
                }
            }
     
            while(!num.empty() && (num.back() == 0)){
                num.pop_back();
            }

            if(num.empty()){
                num.push_back(0);
            }

        }


        PositiveBigInt(const PositiveBigInt& copy){
            
            short n = copy.num.size();

            while(!(this->num.empty())){
                this->num.pop_back();
            }

            for(short i=0; i < n; i++){
                this->num.push_back(copy.num[i]);
            }

        }


        string toString();
        PositiveBigInt betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, short i);

        friend ostream& operator<<(ostream& os, const PositiveBigInt &obj);
        void operator=(const PositiveBigInt& obj);
        PositiveBigInt operator+(PositiveBigInt &obj);
        PositiveBigInt operator*(PositiveBigInt &obj);
};


string PositiveBigInt::toString(){

    string ans = "";
    short n = this->num.size();

    for(short i=n-1; i >= 0; i--){
        ans.push_back(this->num[i] + '0');
    }

    return ans;

}


ostream& operator<<(ostream& os, const PositiveBigInt &obj){

    short n = obj.num.size();
    
    for(short i=n-1; i >= 0; i--){
        os << (obj.num[i]);
    }

    return os;
}


void PositiveBigInt::operator=(const PositiveBigInt& copy){ 
    
    short n = copy.num.size();

    while(!(this->num.empty())){
        this->num.pop_back();
    }

    for(short i=0; i < n; i++){
        this->num.push_back(copy.num[i]); 
    }

}


PositiveBigInt PositiveBigInt::operator+(PositiveBigInt &obj){

    PositiveBigInt ans; 
    short n = this->num.size(); 
    short m = obj.num.size(); 
    
    if(m > n){
        PositiveBigInt temp(*this);
        *this = obj;
        obj = temp;

        n = this->num.size();
        m = obj.num.size();
    }

    short data;
    short digit;
    short carry = 0;
    
    for(short i=0; i < m; i++){
        data = this->num[i] + obj.num[i] + carry; 
        digit = data % 10;
        carry = data / 10;
        ans.num.push_back(digit);
    }

    short i = m;
    short temp = n;
    while(i != temp){
        data = this->num[i] + carry;
        digit = data % 10;
        carry = data / 10;
        ans.num.push_back(digit);
        i++;
    }

    if(carry){
        ans.num.push_back(1);
    }

    return ans;

} 


PositiveBigInt PositiveBigInt::betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, short i){

    short n = ans.num.size();
    short m = ans2.num.size();

    short data;
    short digit;
    short carry = 0;

    short j=0;
    for(; i < n; i++, j++){ 
        data = ans.num[i] + ans2.num[j] + carry; 
        digit = data % 10; 
        carry = data / 10; 
        ans.num[i] = digit;
    }

    for(; j < m; j++){
        data = ans2.num[j] + carry; 
        digit = data % 10; 
        carry = data / 10; 
        ans.num.push_back(digit);
    }

    if(carry){
        ans.num.push_back(1);
    }

    return ans;

}


PositiveBigInt PositiveBigInt::operator*(PositiveBigInt &obj){


    PositiveBigInt ans;
    short n = this->num.size();
    short m = obj.num.size();

    if( (m == 1 && obj.num[0] == 0) || (n == 1 && this->num[0] == 0)){
        return PositiveBigInt("0");
    }

    if(m > n){
        PositiveBigInt temp(*this);
        *this = obj;
        obj = temp;

        n = this->num.size();
        m = obj.num.size();
    }


    short multiply_data;
    short multiply_digit;
    short multiply_carry = 0;
    
    short i = 0;
    for(short j=0; j < n; j++){

        multiply_data = (obj.num[i] * this->num[j]) + multiply_carry; 
        multiply_digit = multiply_data % 10;
        multiply_carry = multiply_data / 10;

        ans.num.push_back(multiply_digit);

        if(multiply_carry > 0 && j == n-1){
            ans.num.push_back(multiply_carry);
        }
    }


    for(short i=1; i < m; i++){
        
        multiply_carry = 0;

        PositiveBigInt ans2;

        for(short j=0; j < n; j++){

            multiply_data = (obj.num[i] * this->num[j]) + multiply_carry; 
            multiply_digit = multiply_data % 10;
            multiply_carry = multiply_data / 10;

            ans2.num.push_back(multiply_digit);

            if(multiply_carry > 0 && j == n-1){
                ans2.num.push_back(multiply_carry);
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
    catch(short num){
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