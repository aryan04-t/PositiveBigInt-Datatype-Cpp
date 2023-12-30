# I created my own "Niche Datatype" in C++ to Solve a HackerRank Question: 


Well, calling it a "Niche Datatype" is just a fancy name that I liked when I 1<sup>st</sup> thought of it, but we all know that in Object Oriented Programming System (OOPS) a "class" is a user defined datatype.

So, basically I wrote a class called "PositiveBigInt" in C++ whose objects are capable of storing big positive integers, I have also converted this datatype into a `header file`, the header file is also present in this repository inside `00_Short Vector Implementation/` directory, you can check it out. 

The range of this datatype "PositiveBigInt" is theoretically `0 to +infinity.` 

Which means "PositiveBigInt" is a arbitrary precision integer datatype. 



# Story Time: 

- I encountered a question on HackerRank 2 months ago, it is known as "Fibonacci Modified". 

- Here is the link to that question: https://www.hackerrank.com/challenges/fibonacci-modified/problem 

- Although the question is really simple, it just requires 3-4 lines of code for main logic and its done, it will be solved, but this scenario is only possible with coding languages who have some support for handling positive integers which are way bigger than the range of a 64-bit integer. 

- Because the catch in this question is that, while calculating the n<sup>th</sup> term of "Modified Fibonacci Sequence" the value of output can far exceed the range of a 64-bit integer. 

- My primary language for doing DSA is C++, when I tried solving this question for the 1<sup>st</sup> time by using C++, I understood that with my current level of understanding of C++ and DSA, I cannot solve this question using C++, because C++ doesn't provide any direct standard support to handle positive integers more than the range of 2<sup>64</sup>-1.

- You can use a 64-bit unsigned int by including &lt;cstdint&gt; header file, this 64-bit unsigned int can attain a maximum possible value of 2<sup>64</sup>-1, C++ doesn't provide any direct standard support to store any positive integer value beyond 2<sup>64</sup>-1. 

- Although there is a C++ header file known as `<boost/multiprecision/cpp_int.hpp>` which offers multiple precision arithmetic types, and it lets us handle positive integers bigger than the range of 2<sup>64</sup>-1, and negative integers bigger than the range of -2<sup>63</sup>-1, but this is not a standard C++ library, I tried using it on HackerRank and I was not able to include it.
  - If you want to know more about <boost/multiprecision/cpp_int.hpp> header file, you can read this GFG article:  
    https://www.geeksforgeeks.org/advanced-c-boost-library/
    
  - You can also look into the code of this header file directly:  
    https://www.boost.org/doc/libs/1_75_0/boost/multiprecision/cpp_int.hpp
    
  - Or you can just visit their official GitHub repository:  
    https://github.com/boostorg/multiprecision 

- Coming back to the story; I also know Java pretty well and it has a datatype called "BigInteger" which can handle big numbers. 

- So, that day I solved this question in Java by just writing just 5 lines of main logic code, but I also wanted to solve this question using C++ because it is my primary programming language for doing DSA, but I knew that I cannot solve this question with my current skills of C++ and DSA, that's why I ignored this question that time.  
  > P.S.: I am still a newbie in C++ and DSA, but I am a little bit better then what I used to be 2 months ago. 



# Fastfoward to 4 days ago from Today: 

  ### Today is 30th Dec. 2023 when I am writing this README.md for the 1<sup>st</sup> time. 

  - 4 days ago when I was just about to sleep (26th Dec.'s Night), out of nowhere I started thinking about this question "Fibonacci Modified" and suddenly an approach to solve this question clicked in my mind.
  
  - The very next morning I woke up and I started implementing it, while implementing my approach I wrote this class "PositiveBigInt".
   
  - Next 2 days I just visualized, coded, dry runned and debugged my code and finally I was able to write a code which was functioning totally perfect. 
  
  - I submitted my code on HackerRank and my code was just able to pass 7 test cases out of 10, the rest 3 test cases failed due to TLE (Time Limit Exceeded) Error. 

  - Now another next 2 days I tried to optimize my code as much as I can, space and time complexity wise, but at the end I failed, I wasn't not able to pass those 3 test cases which failed earlier.

  - Although I tried my best and I got to learn a lot of new concepts and I got to revise a lot old concepts, that's why I don't have any regret for spending 4 whole days just on this question, even if I was not able to pass all the test cases of it. 

  - So, I am just done with this question for now, and that's why I am just documenting all this progress of mine, the code is open source, feel free to make improvements to this datatype's code.

  - And `I am moving on from this question now.` 


# Time and Space Complexity Optimizations: 


  ### Space Complexity: 
  
  - 1<sup>st</sup> Optimization: 
    - When we talk about space compexity optimizations, I have done enough of them I feel, Initially I used vector&lt;int&gt; under the hood to implement "PositiveBigInt" class, but then I realised that I am wasting space because I am only storing a single digit value at each index of this vector.
    - That's why I converted under the hood implementation of "PositiveBigInt" from `vector<int>` to `vector<short>`
  
  - 2<sup>nd</sup> Optimization: 
    - After that I again realised that I only need space for representing 0-9, 10 digits only per index. So, why not improve the space usage even more by using a "char", it is the smallest datatype that I can go down to if I need to store 10 possible values (0-9) at each index.
    - But I didn't used vecetor&lt;char&gt; for obvious reasons, because be have string datatype, why to use vector&lt;char&gt; then.
    - Then I converted under the hood implementation of "PositiveBigInt" from `vector<short>` to `"string"` 


    
  ### Time Complexity: 

  - I have overloaded \+ and \* both the operators for "PositiveBigInt" objects, and I have applied the logics of addition and multiplication using my "Naive Approach". 

  - \+ Operator:
    - The time complexity of \+ operator is `O(n)`, where n = the length of PositiveBigInt which has maximum number of digits.
    - And in my opinion it cannot be improved anymore (Although I can be wrong).
   
  - \* Operator:
    - The time complexity of \* operator is `O(n * m)`, where n = the length of PositiveBigInt which has maximum number of digits, and m = the length of PositiveBigInt which has minimum number of digits.
    - When I researched I got to know that there exists an algorithm known as `"Karatsuba's Multiplication Algorithm"`, and as far as I got to know, it has a better time complexity then "Naive Multiplication Algorithm".
    - I tried studying "Karatsuba's Algorithm", but I wasn't able to get a nice grasp over it, that's why I am not able to code it. 
      


 # My Opinion: 
  
  ### My closing note for this question is: 
  
  "Fibonacci Modified" is a nice and annoying question to solve as a intermediate coder in C++ and DSA. 

  ### If you want to solve this question from scratch on your own by building logic and by using C++, then my recommendation to you is that:   
  
  > Although it can be a real pain in ass to solve this question using C++, but you will for sure get to learn a lot of new things if you really try to solve this question on your own. 
  
