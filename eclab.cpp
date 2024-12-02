#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <set>
#include <cmath>

using namespace std;

double extractNumeric(const string& str){
    int i = 0;
    bool period = false, sign = false, digit = false, errorfound = false;
    double result = 0.0;
    int posneg = 1, divider = 1;
    
    char target = '.';
    int dotpos = str.find(target);
    if(dotpos > 0){
        period = true;
    }

    if(i < str.size() && (str[i] == '+' || str[i] == '-')){
        sign = true;
        if(str[i] == '-'){
            posneg = posneg * -1;
        }
        i++;
    }
    
    while(i < str.size()){
        char spot = str[i];
        
        if(isdigit(spot)){
            if(period){
                result = result + ((spot - '0') * pow(10, dotpos-i));
            }
            else{
                result = result + ((spot - '0') * pow(10, str.size() - i - 1));
            }
            
        } else if(spot == '.'){
            if(dotpos != i){
                errorfound = true;
            }
            }else{
            errorfound = true;
        }
        i++;
    }
    

    if(errorfound){
        return -999999.99;
    }
    if(period){
        int ten_times_result = result;
        int int_new_result = ten_times_result/10;
        double final_result = int_new_result + (result- ten_times_result);
        return final_result * posneg;
    } else{
        return result * posneg;
    }
    
}


int main(){
    string input;
    
    while(true){
        cout << "Enter a sring (or 'END' to quit): ";
        cin >> input;

        if(input == "END"){
            break;
        }

        double number = extractNumeric(input);
        
        if(number != -999999.99){
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }else{
            cout << "The input is invalid" << endl;
        }
        
    }

    return 0;
}