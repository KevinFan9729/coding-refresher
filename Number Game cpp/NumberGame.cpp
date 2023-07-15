#include <algorithm> // std::find, std::min_element
#include <cmath> // std::abs
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

//function prototypes
int randMultiplier();
std::vector<int> promptUser();
std::vector<int> generateNum(int start, int num, int multiplier);

int randMultiplier(){

    std::random_device rd;   // non-deterministic generator
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    // std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(2,4); // distribute results between 2 and 4 inclusive.
    // int multiplier = 2 + (rand() % 4);
    int multiplier = dist(mt);
    return multiplier;
}

std::vector<int> promptUser(){
    int start{};
    int numofNumbers{};
    std::cout<<"let me know where to start: ";
    std::cin>>start;
    std::cout<<"How many numbers? ";
    std::cin>>numofNumbers;
    
    int multiplier = randMultiplier();

    return generateNum(start,numofNumbers,multiplier);


}

std::vector<int> generateNum(int start, int num, int multiplier){
    std::vector<int> sqNumVect{};
    for(int i = start; i<=num; i++){
        sqNumVect.push_back(i*i*multiplier);
    }
    return sqNumVect;

}



int main(){

    
    int a = randMultiplier();
    std::cout<<a;
}



// #include <random>
// #include <iostream>

// using namespace std;

// int main()
// {
//     random_device rd;   // non-deterministic generator
//     mt19937 gen(rd());  // to seed mersenne twister.
//     uniform_int_distribution<> dist(1,6); // distribute results between 1 and 6 inclusive.

//     for (int i = 0; i < 5; ++i) {
//         cout << dist(gen) << " "; // pass the generator to the distribution.
//     }
//     cout << endl;
// }
