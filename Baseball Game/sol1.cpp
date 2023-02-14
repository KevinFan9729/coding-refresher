class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        int sum=0;
        for(auto i : operations){
            if(i=="C"){
                score.pop_back();
            }else if(i=="D"){
                score.push_back(score.back()*2);//vector.back return direct reference
            }else if(i=="+"){
                // auto test1 = *(score.end()-1);//last element
                // auto test2 = *(score.end()-2);//second last element
                score.push_back(*(score.end()-1)+*(score.end()-2));
            }else{
                score.push_back(std::stoi(i));//std::stoi(string) convert string to int
            }
        }
        
        for(int i: score){
            sum+=i;
        }
        return sum;
    }
    
};
