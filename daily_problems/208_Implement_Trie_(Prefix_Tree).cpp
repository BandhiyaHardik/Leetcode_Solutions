class Trie {
public:
    set<string> st;

    Trie(){}

    void insert(string word) {
        st.insert(word);
    }

    bool search(string word) {
        return st.find(word) != st.end();
    }
    
    bool startsWith(string prefix) {

        auto it = st.lower_bound(prefix);
        if(it == st.end()) 
            return false;
        for(int i = 0;i<prefix.size();i++){
            if(prefix[i] != (*it)[i]){
                return false;
            }
        }
        return true;
    }
};