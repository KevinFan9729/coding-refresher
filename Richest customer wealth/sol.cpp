
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int num_customer = accounts.size();//num_customer is the number of customers, num_bank is how many banks
        int num_bank = accounts[0].size();
        vector<int> wealth_vect(num_customer,0); //1d wealth vector of size of # of customers to keep track of the wealth of customers
        for (int i= 0; i<num_customer; i++){
            for (int j=0; j<num_bank; j++){
                wealth_vect[i]+=accounts[i][j];
            }
        }  
        std::vector<int>::iterator max_wealth;
        max_wealth = std::max_element(wealth_vect.begin(),wealth_vect.end());
        return *max_wealth;

    }
};