class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum =0;
        for (const string& s : operations) {

            if (s == "+") {
                int a = st.top(); st.pop();
                int b = st.top();
                st.push(a); 
                st.push(a + b);
                sum+= a;
                sum+=b;

            } else if (s == "D") {
                st.push(2 * st.top());
                sum+=st.top();

            } else if (s == "C") {
                sum-=st.top();
                st.pop();

            } else {
                st.push(stoi(s));
                sum+=st.top();
            }
        }
        return sum;
    }
};
