class WordDictionary {
public:
    struct Node{
        bool isEndOfWord;
        Node* links[26];
        Node(){
            isEndOfWord = false;
            for(int i = 0; i < 26; i++)
                links[i] = nullptr;
        }
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        bool isEnd(){
            return isEndOfWord;
        }
        void setEnd(){
            isEndOfWord = true;
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }
    bool dfs(int idx, string& word, Node* node) {
        if(idx == word.size())
            return node->isEnd();

        char ch = word[idx];

        // normal character
        if(ch != '.') {
            if(!node->containsKey(ch))
                return false;

            return dfs(idx + 1, word, node->get(ch));
        }

        // '.' can represent any character
        for(int i = 0; i < 26; i++) {
            if(node->links[i] != nullptr) {
                if(dfs(idx + 1, word, node->links[i]))
                    return true;
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */