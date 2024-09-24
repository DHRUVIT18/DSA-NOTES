struct Node{
    unordered_map<int,Node*> umc;
    bool is_end = false;
};

class trie{
private:
    Node *root;
public:
    trie(){
        root = new Node();
    }

    // inserting values in trie
    void insert(int a){
        Node *cur = root;
        string tmp = to_string(a);
        for(int i=0;i<tmp.size();i++){
            int num = tmp[i]-'0';
            if(cur->umc.find(num)==cur->umc.end()){
                cur->umc[num] = new Node();
            }

            cur = cur->umc[num];
        }

        cur->is_end = true; // denotes no node after this
        return;
    }

    // matching the prefixes of a string/ number
    int prefix_match(int b){
        Node *cur = root;
        string tmp = to_string(b); // converting to string for easy traversal
        int len=0;
        for(int i=0;i<tmp.size();i++){
            int num = tmp[i]-'0';
            // if no match found break
            if(cur->umc.find(num)==cur->umc.end()){
                break;
            }
            cur = cur->umc[num];
            len++;
        }

        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie t;
        for(auto& val:arr1){
            t.insert(val);
        }

        int mx=INT_MIN;
        for(auto& val:arr2){
            mx = max(mx, t.prefix_match(val));
        }

        return mx;
    }
};