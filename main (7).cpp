#include <iomanip>
#include <cstdlib>
#include <cmath>
// This program takes a set of grades provided by the user, and then 
// sorts them into different percentages and categories, depending on 
// the grade level specified by the grade integer.
// 
// Programmer:    Andrew Coviello
// Module 8
// Project 1
// Problem Statement: Write a program to read from the user a list of 
// exam scores (integer percentages in the range 0 to 100) and to output:
//
// the total number of grades entered
// the number of grades in each letter-grade category (90 - 100 = A, 80 - 
// 89 = B, 70 - 79 = C, 60 - 69 = D, and 0 - 59 = F)
// the percentage of the total grades each letter grade represents
// The end of the input is indicated by a negative score as a sentinel 
// value. 
// 
// 1. Establish integer values for the current grade being processed, 
// total number of grades and different grade category counters.
// 2. Initialize an if-else statement with conditions varying based on 
// the number of grades entered.
// 3. Prompt the user for exam scores, integers from 0 to 100.
// 4. Establish -1 as a sentinel value since grades can't be negative.
// This will be used to stop the input process and proceed with
// the associated calculations.
//
#include <iostream>
using namespace std;

int main() {

  // integers for grade values
  int currentGrade, totalNumberOfGrades,  numberOfGradesInEachLetterGradeCategory = 0, aCategory = 0, bCategory = 0, cCategory = 0, dCategory = 0, fCategory = 0, count = 0;
  bool gradeIsNegative = false;

  // beginning display shows choices and prompts user for character 
  cout << setw(30) << setprecision(1) << fixed << "****** Visualize Exam Scores ******\n" << endl;
  cout << setw(30) << "Enter each grade on a separate line" << endl;
  cout << setw(30) << "(A negative grade will end entry)" << endl;
  while(gradeIsNegative == false)
  { 
    count++;
    cout << setw(5) << "" << "Enter grade #" << count << ": " << endl;
    // prompt user
    cin >> currentGrade;
    if(currentGrade < 0)
    {
      gradeIsNegative = true;
    }
    else if(currentGrade >= 0 && currentGrade <= 59)
    {
      fCategory = fCategory + 1;
    }
    else if(currentGrade >= 60 && currentGrade <= 69)
    {
      dCategory = dCategory + 1;
    }
    else if(currentGrade >= 70 && currentGrade <= 79)
    {
      cCategory = cCategory + 1;
    }
    else if(currentGrade >= 80 && currentGrade <= 89)
    {
      bCategory = bCategory + 1;
    }
    else if(currentGrade >= 90 && currentGrade <= 100)
    {
      aCategory = aCategory + 1;
    }                 
    else if(currentGrade > 100)
    {
      cout << "This class doesn't offer extra credit." << endl;
      exit(0);
    }
  }

  totalNumberOfGrades = count - 1;
     
  double aPercentage = (((double) aCategory / (double) totalNumberOfGrades) * 100.0), bPercentage = (((double) bCategory / (double) totalNumberOfGrades) * 100.0), cPercentage = (((double) cCategory / (double) totalNumberOfGrades) * 100.0), dPercentage = (((double) dCategory / (double) totalNumberOfGrades) * 100.0), fPercentage = (((double) fCategory / (double) totalNumberOfGrades) * 100.0);

  if(totalNumberOfGrades == 0)
  {
    cout << setw(5) << "No grades were entered." << endl;
  }
  else if(totalNumberOfGrades == 1)
  {
    cout << setw(5) << "" << "One grade was entered." << endl;
  }
  else if(totalNumberOfGrades > 1)
  {
    cout << setw(5) << "" << "A total of " << totalNumberOfGrades << " grades were entered.\n" << endl;
  }

  cout << setw(5) << right << "A" << setw(10) << "B" << setw(10) << "C" << setw(10) << "D" << setw(10) << "F" << endl; 
  cout << setw(5) << right << "_" << setw(10) << "_" << setw(10) << "_" << setw(10) << "_" << setw(10) << "_" << endl; 
  cout << setw(5) << right << aCategory << setw(10) << bCategory << setw(10) << cCategory << setw(10) << dCategory << setw(10) << fCategory << endl; 
  cout << setw(5) << right << aPercentage << "%" << setw(9) << bPercentage << "%" << setw(9) << cPercentage << "%" << setw(9) << dPercentage << "%" << setw(9) << fPercentage << "%" << endl;
}