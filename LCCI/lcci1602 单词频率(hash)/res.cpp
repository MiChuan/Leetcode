class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        size_t size = book.size();
        for(int i = 0; i < size; i++){
            hash[book[i]]++;
        }
    }
    
    int get(string word) {
        if(hash.count(word))
            return hash[word];
        return 0;
    }
private:
    unordered_map<string, int> hash;
};