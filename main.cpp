/* 
 * File:   main.cpp
 * Author: Adam Claxton 
 * 
 * This is the main file for the Grade Calculation program. This program calculates
 * the final grade given each assignment score and their weights in percentages. 
 *
 * Created on September 25, 2020, 2:05 PM
 */

#include <cstdlib>
#include <string>
#include <cmath>
#include <iostream>


using namespace std;

bool getValidNumber(string prompt, double *value, const double min, const double max); 
string gradeFromMark(const double mark); 


// This function collects user input and determines if it is a valid input
 
bool getValidNumber(string prompt, double *value, const double min, const double max){
    bool loop = 1; 
    while(loop == 1){ // while loop to keep collecting data if the input isn't within the min and max
        cout << prompt;
        cin >> *value; 
        if(cin.good()== false){ // if the input is non-numerical, clear the input and return false
            cin.clear(); 
            cin.ignore(255, '\n');
            cout << "Data collection terminated\n"; 
            return false; 
        }
        if(*value < min || *value > max){ // if the input is not within the parameters display error message and go through loop again
            cout << "Entered Value is outside of parameters\nPlease Try Again\n"; 
        }
        else{ // if the value is valid exit loop and return true
            loop = 0; 
        }    
    }
    
    return true;           
} 

// This function takes a percentage between 0 and 100% and returns the letter grade;
string gradeFromMark(const double mark){ 
    string outputGrade; 
    if(mark < 50.0){
        outputGrade = "Grade is F\n";
        return outputGrade;
    }
    if(mark >= 50.0 && mark < 60.0){
        outputGrade = "Grade is D\n";
        return outputGrade;
    }
    if(mark >= 60.0 && mark < 65.0){
        outputGrade = "Grade is C\n";
        return outputGrade;
    }
    if(mark >= 65.0 && mark < 70.0){
        outputGrade = "Grade is C+\n";
        return outputGrade;
    }
    if(mark >= 70.0 && mark < 73.0){
        outputGrade = "Grade is B-\n";
        return outputGrade;
    }
    if(mark >= 73.0 && mark < 77.0){
        outputGrade = "Grade is B\n";
        return outputGrade;
    }
    if(mark >= 77.0 && mark < 80.0){
        outputGrade = "Grade is B+\n";
        return outputGrade;
    }
    if(mark >= 80.0 && mark < 85.0){
        outputGrade = "Grade is A-\n";
        return outputGrade;
    }
    if(mark >= 85.0 && mark < 90.0){
        outputGrade = "Grade is A\n";
        return outputGrade;
    }
    if(mark >= 90.0){
        outputGrade = "Grade is A+\n";
        return outputGrade;
    }
    else{
        outputGrade = "Failed to calculate grade\n";
        return outputGrade; 
    }
    

    
}

int main(){
    // Strings to ask for correct user input
    string gradePrompt = "Enter Assignment Grade\n";
    string weightPrompt = "Enter Assignment Weight\n";
    // double to hold appropriate current and total values 
    double value = 0.0; 
    double grade = 0.0; 
    double weight = 0.0; 
    double totalGrade = 0.0; 
    double totalWeight = 0.0; 
    // const doubles to hold the parameters of the function 
    const double gradeMax = 100.00; 
    const double gradeMin = 0.00;
    const double weightMax = 50.00; 
    const double weightMin = 1.00; 
    
    //intro that explains program to user 
    cout << "____________________________________________________________________\n";
    cout << "Please enter your grades and their weights to calculate final grade\nEnter non-numeric value to exit\nGrades can be between 0-100%\nWeights can be between 1-50% and must total 100%\n";
    cout << "____________________________________________________________________\n";

    while(1){
        
        // if the user enters a numeric grade value then make grade equal to that value 
        if(getValidNumber(gradePrompt, &value, gradeMin, gradeMax)==1){ 
            grade = value; 
        }
        else{ // if the user enters an non-numeric value exit the loop 
            cout << "Program Ended\n";
            cout << "Calculating...\n";
            break;  
        }
        
        // if the user enters a numeric weight value then make weight equal to that value/100.0
        if(getValidNumber(weightPrompt, &value, weightMin, weightMax)== 1){
            weight = (value/100.00);
            // removing this if statement will remove the 100% check
            if(totalWeight+weight > 1){ // if the total weight will be greater than 100% display error and skip the rest of the loop and try again 
                cout << "Total Weight Greater than 100%\n Please Try Again\n";
                continue; 
            }
            totalWeight = totalWeight + weight; // if the total weight is less than or equal to 100% then add the weight to totalWeight
            
                
        }
        else{ // if the user enters an non-numeric value exit the loop 
            cout << "Program Ended\n";
            cout << "Calculating...\n";
            break;  
        }
        
        totalGrade = totalGrade + (weight*grade); // calculate the current grade and add it to the total 
        // removing this if statement will remove auto exit 
        if(totalWeight == 1){ // if the totalWeight is equal to 100% exit the loop 
            cout << "Program Ended\n";
            cout << "Calculating...\n";
            break;
        }
          
    }
    
    if(totalWeight == 1.0){  // if the total weight is 100% calculate letter grade and print mark and grade 
        const double mark = totalGrade; 
        cout << "Your mark is " << mark << "\n";
        cout << gradeFromMark(mark);
        return 0; 
    }
    else{ // if the total weight doesn't equal 100% grade can't be calculated so display error and exit program 
        cout << "Weight was not equal to 100%\n"; 
        return 0; 
    }
   
    return 0;
}

