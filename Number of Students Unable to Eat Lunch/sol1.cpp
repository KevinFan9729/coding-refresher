class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> student_q;
        // std::queue<int> sandwich_q;
        int re_org_step = 0;
        int temp;
        int indx=0;
        for(int i=0; i<students.size(); i++){
            student_q.push(students[i]);
            // sandwich_q.push(sandwiches[i]);
        }
        while(student_q.size()!=0){
            if(student_q.front()==sandwiches[indx]){
                student_q.pop();
                re_org_step=0;
                indx++;//move the front index of the sandwiches vector
            }else{
                temp = student_q.front();
                student_q.pop();
                student_q.push(temp);
                re_org_step++;
            }
            //if re-organization step is larger or equal to the queue size
            //that means we loop through the students queue completely 
            //and we cannot reduce the size of the student queue further
            if(re_org_step>=student_q.size()){
                break;
            }
        }
        return student_q.size();
    }
};

