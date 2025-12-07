#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cmath>

using namespace std;


bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int main() {
    
    string filepath = "input_";
    string row;
    int dial = 50;
    int zeroes = 0;
    int allzeroes = 0;

    std::cout << "Start day 1 solver" << std::endl;

    if (fileExists(filepath)) {
        std::cout << "Found file!" << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }

    ifstream inputFile(filepath);

    while (getline (inputFile, row)) {
        char direction = row[0];
        row = regex_replace(row, regex(R"([\D])"), "");

        std::cout << "Row: " << row << std::endl;
        if (direction == 'L'){
            if(dial == 0){
                allzeroes += floor((stoi(row))/100);
            } else {
                allzeroes += floor((100 - dial + stoi(row))/100);
            }
            std::cout << "L add " << floor((100 - dial + stoi(row))/100) << std::endl;

            dial -= stoi(row);
        } else if(direction == 'R'){
            dial += stoi(row);
            allzeroes += floor(dial/100);
            std::cout << "R add " << floor(dial/100) << std::endl;

        } else {
            std::cout << "Found unexpected input data: " + row << std::endl;
        }
        
        
        if(dial > 99) {
            dial = dial % 100;
        }

        if (dial < 0) {
            dial = dial % 100;

            if (dial != 0){
                dial = 100 + dial;
            }
        }

        if(dial == 0) {
            zeroes++;
        }   
        std::cout << "DIAL: " << dial << std::endl;
    }

    inputFile.close(); 

    //1066 //6223
    std::cout << "Result: Day1:" << zeroes << " Day2:" << allzeroes << std::endl;
    std::cout << "Finished day 1 solver" << std::endl;
    return 0;
}