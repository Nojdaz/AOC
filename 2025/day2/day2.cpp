#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

bool allCharsSame(string input) {
    char letter = input[0];

    for (int i = 1; i < input.length(); i++) {
        if (input[i] != letter)
            return false;
    }

    return true;
}

bool repeatpattern(int size, string input){
    string pattern;

    for(int i = 0; i < size; i++){
        pattern += input[i];
    }
    
    //std::cout << "Pattern: " << pattern << std::endl;

    for (int i = 0; i < (input.size() / size); i++) {
        if (input.substr(i*size, size) != pattern ) {
            return false;
        }
    }

    return true;
}

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    using std::chrono::duration_cast;
    using std::chrono::duration;

    string filepath("input");
    string row;
    std::vector<std::string> list = {};

    if (fileExists(filepath)) {
        std::cout << "Found file!" << std::endl;
    } else {
        std::cout << "File does not exist." << std::endl;
    }

    ifstream inputFile(filepath);

    long totalday1 = 0;
    long totalday2 = 0;

    auto startTime = high_resolution_clock::now();

    while(getline(inputFile, row, ',')){
            string firstid = row.substr(0,row.find('-'));
            string lastid = row.substr(row.find('-') + 1,row.size());

            // Day 1
            for(long i = stoll(firstid); i <= stoll(lastid); i++){

                string id = to_string(i);

                if(id.size() % 2 != 0){
                    continue;
                }

                //Check if the twohalfs are the same.
                if(id.substr(0,id.size() / 2) == id.substr(id.size() / 2, id.size())){
                    totalday1 += i;
                }
            }
            
            //Day 2 
            for(long i = stoll(firstid); i <= stoll(lastid); i++){

                string id = to_string(i);

                for(int j=1; j <= floor(id.size()/2); j++){
                    if(id.size() % j == 0 and repeatpattern(j, id)){
                        totalday2 += i;
                        break;
                    
                }
            }
        }
    }

    using namespace std::chrono_literals;
    //38437576669
    std::cout << "Part 1 result: " << totalday1 << std::endl;
                                            
    //49046150754
    std::cout << "Part 2 result: " << totalday2 << std::endl;

    auto endTime = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(endTime - startTime);
    std::cout << "Execution time: " << ms_int.count() << "ms";

    return 0;
}