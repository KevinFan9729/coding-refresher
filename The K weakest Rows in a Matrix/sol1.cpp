class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int num_rows  = mat.size();
        int num_people = mat[0].size();
        vector<int> strength_vec(num_rows);
        vector<int> result(k);
        for (int i = 0; i<num_rows; i++){
            int temp = 0;
            for (int j = 0; j<num_people; j++){
                if(mat[i][j]==0){
                    break;
                }
                temp+=1;
            }
            strength_vec[i] = temp;
        }
        for(int i=0; i<k; i++){
            vector<int>::iterator temp = find(strength_vec.begin(),strength_vec.end(),*(min_element(strength_vec.begin(),strength_vec.end())));
            int indx = temp - strength_vec.begin();
            result[i] = indx;
            strength_vec[indx] = INT_MAX;
        }
        return result;
    }
};
