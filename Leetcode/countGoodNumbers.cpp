#include <iostream>
using namespace std;

class Solution {
public:
    //method for prime
    bool isPrime(int num){
        if(num <=3 && (num == 1 || num == 2 || num == 3)){
            return true;
        }

        for(int i = 2; i<num; i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }

    int countGoodNumbers(long long n) {
        
        //how to calculate each numbers of having digit n
        return n;
    }
};

int main() {
    Solution solution;
    long long n;
    cout << "Enter the length of the number: ";
    cin >> n;
    cout << "Count of good numbers: " << solution.countGoodNumbers(n) << endl;
    return 0;
}
