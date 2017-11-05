    #include <bits/stdc++.h>
    using namespace std;
    bool is_greater(vector<int> box, int k){
        for(int i = 0; i < box.size(); ++i){
            if(box[i] < k)
                return false;
        }
        return true;
    }
    bool is_less(vector<int> box, int k){
        for(int i = 0; i < box.size(); ++i)
            if(box[i] > k)
                return false;
        return true;
    }
    bool is_bst(vector<int> box){
        int n = box.size(), i;
        if(n <= 2)
            return true;
        for(i = 1; i < n; ++i){
            if(box[i] > box[0])
                break;
        }
        vector<int> right = vector<int>(box.begin() + i, box.end());
        vector<int> left = vector<int>(box.begin() + 1, box.begin() + i);
        bool check = is_greater(right, box[0]) and is_less(left, box[0]);
        if(check)
            return is_bst(left) and is_bst(right);
        else
            return false;
    }
    void post(vector<int> box){
        int n = box.size(), i;
        if(n == 0)
            return;
        if(n == 1){
            cout << box[n - 1] << " ";
            return;
        }
        for(i = 1; i < n; ++i){
            if(box[i] > box[0])
                break;
        }
        vector<int> left = vector<int> (box.begin() + 1, box.begin() + i);
        vector<int> right = vector<int> (box.begin() + i, box.end());
        post(left);
        post(right);
        cout << box[0] << " ";
        return;
    }
    int main() {
    	//code
    	int t;
    	cin >> t;
    	while(t--){
    	    int n;
    	    cin >> n;
    	    vector<int> box(n);
    	    for(int j = 0; j < n; ++j)
    	        cin >> box[j];
    	    bool check = is_bst(box);
    	    if(check){
    	        post(box);
    	        cout << endl;
    	    }
    	    else
    	        cout << "NO" << endl;
    	}
    	return 0;
    }
