#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int main() {
    string filepath("input");
    int Part1_result = 0;
    long Part2_result = 0;

    if (fileExists(filepath)) {
        std::cout << "Found file!" << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }

    string row = "9";
    ifstream inputFile(filepath);

    while(getline(inputFile, row)){
        int position;
        string number;

        for(int i = 9; i > 0; i--){
            //find first
            if(number.size() == 0){
                for(int j = 0; j < row.size() -1; j++){
                    if((int)row[j] - '0' == i){
                        std::cout << "Found largest: " << i << std::endl;
                        number += to_string(i);
                        position = j;
                        i = 9;
                        break;
                    }
                    
                }
            }
            
            if(number.size() == 1){
                //shortcut
                if(row.size() - position == 1){
                    number += i;
                }

                //find second
                for(int j = position + 1; j <= row.size(); j++){
                    if((int)row[j] - '0' == i){
                        std::cout << "Found second largest: " << i << std::endl;
                        number += to_string(i);
                        break;
                    }
                }

                if(number.size() == 2){             
                    break;
                }
            }
        }
        Part1_result += stoi(number);

        string result;
        int indent = 0;
        for(int i = 12; i > 0; i--){
            for(int j = 9; j > 0; j--){
                string compare = result;
                for(int k = indent; k < row.size() - (i -1); k++){
                    if((int)row[k] - '0' ==  j){
                        result += to_string(j);
                        std::cout << "found: " << row[k] << " at position: " << k << std::endl;
                        indent = k + 1;
                        break;
                    }
                }
                if(compare.size() != result.size()){
                    break;
                }
            }
            
        }
        Part2_result += stol(result);
    
    }

    // 17085
    std::cout << "Part 1: " << Part1_result << std::endl;

    //169408143086082
    std::cout << "Part 2: " << Part2_result << std::endl;
}