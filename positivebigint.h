// I have converted my "PositiveBigInt" niche datatype into a header file 

// I call it a niche datatype, because it's not a full fledged data type, and calling it a "Incomplete Datatype" doesn't sounds cool to me ;) 
// XD But jokes aside, this datatype just has few specific fucntions written for itself and few operators overloaded as per requirement for convenience that's why I call it a "Niche Datatype", because agreed, it is an incomplete datatype when it comes to the range of operators it can work with, but it serves a really amazing purpose in my opinion 



#ifndef POSITIVEBIGINT_H              // Include guards to prevent multiple inclusions of this header file 
#define POSITIVEBIGINT_H


#include<iostream> 
#include<vector> 
#include<string> 
using namespace std; 


class PositiveBigInt{
    private:
        vector<int> num; 
        PositiveBigInt() {}

    public:

        PositiveBigInt(string s){ 

            int n = s.length(); 
            int digit; 

            for(int i = n-1; i >= 0; i--){
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
            
            int n = copy.num.size();

            while(!(this->num.empty())){
                this->num.pop_back();
            }

            for(int i=0; i < n; i++){
                this->num.push_back(copy.num[i]);
            }

        }


        string toString();
        PositiveBigInt betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, int i);

        friend ostream& operator<<(ostream& os, const PositiveBigInt &obj);
        void operator=(const PositiveBigInt& obj);
        PositiveBigInt operator+(PositiveBigInt &obj);
        PositiveBigInt operator*(PositiveBigInt &obj);
};


string PositiveBigInt::toString(){

    string ans = "";
    int n = this->num.size();

    for(int i=n-1; i >= 0; i--){
        ans.push_back(this->num[i] + '0');
    }

    return ans;

}


ostream& operator<<(ostream& os, const PositiveBigInt &obj){

    int n = obj.num.size();
    
    for(int i=n-1; i >= 0; i--){
        os << (obj.num[i]);
    }

    return os;
}


void PositiveBigInt::operator=(const PositiveBigInt& copy){ 
    
    int n = copy.num.size();

    while(!(this->num.empty())){
        this->num.pop_back();
    }

    for(int i=0; i < n; i++){
        this->num.push_back(copy.num[i]); 
    }

}


PositiveBigInt PositiveBigInt::operator+(PositiveBigInt &obj){

    PositiveBigInt ans; 
    int n = this->num.size(); 
    int m = obj.num.size(); 
    
    if(m > n){
        PositiveBigInt temp(*this);
        *this = obj;
        obj = temp;

        n = this->num.size();
        m = obj.num.size();
    }

    int data;
    int digit;
    int carry = 0;
    
    for(int i=0; i < m; i++){
        data = this->num[i] + obj.num[i] + carry; 
        digit = data % 10;
        carry = data / 10;
        ans.num.push_back(digit);
    }

    int i = m;
    int temp = n;
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


PositiveBigInt PositiveBigInt::betweenMultiplicationAdd(PositiveBigInt& ans, PositiveBigInt& ans2, int i){

    int n = ans.num.size();
    int m = ans2.num.size();

    int data;
    int digit;
    int carry = 0;

    int j=0;
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
    int n = this->num.size();
    int m = obj.num.size();

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


    int multiply_data;
    int multiply_digit;
    int multiply_carry = 0;
    
    int i = 0;
    for(int j=0; j < n; j++){

        multiply_data = (obj.num[i] * this->num[j]) + multiply_carry; 
        multiply_digit = multiply_data % 10;
        multiply_carry = multiply_data / 10;

        ans.num.push_back(multiply_digit);

        if(multiply_carry > 0 && j == n-1){
            ans.num.push_back(multiply_carry);
        }
    }


    for(int i=1; i < m; i++){
        
        multiply_carry = 0;

        PositiveBigInt ans2;

        for(int j=0; j < n; j++){

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


#endif 



/*


# What are #ifndef, #define, and #endif: 

--> #ifndef, #define, and #endif are include guards. 
--> They prevent the contents of the header file from being included more than once in the same source file.


*/



// - - - - - - - - - - 



/*


# How to use this header file: 

--> Download this header file first 

--> If you have downloaded this header file locally, then keep it you folder where your .cpp file exists, in which you want to use this header file 

--> Include this header file into your program using #include directive like this: #include"positivebigint.h" 

--> Don't use angular brackets while using your you own defined header file which is present in your current working directory, because: 
    -> When you use angle brackets, the compiler only searches through the standard system directories and does not look in the current directory. 
    -> When you use double quotes, the compiler searches for the header file in the current directory first. If it doesn't find the file there, it searches through the standard system directories. 

--> Now, when you have included the header file, and it is also present in the your current wroking directory, then open the terminal in your working directory and compile and run your C++ program noramlly 


*/