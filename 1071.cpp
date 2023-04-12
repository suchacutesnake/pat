//1071 Speech Patterns
#include <iostream>
#include <vector>

using namespace std;

int max_frequency = 0;
string most_common_word;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool is_end_of_word;
    int frequency;

    TrieNode() {
        is_end_of_word = false;
        frequency = 0;
        children.resize(128);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current_node = root;
        for (char c : word) {
            if (current_node->children[c] == nullptr) {
                current_node->children[c] = new TrieNode();
            }
            current_node = current_node->children[c];
        }
        current_node->is_end_of_word = true;
        current_node->frequency += 1;
        if (current_node->frequency > max_frequency) {
            max_frequency = current_node->frequency;
            most_common_word = word;
        }
    }
};

int main() {
    string text;
    getline(cin, text);
    Trie trie;
    string word;
    for (char c : text) {
        c = tolower(c);
        if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a')) {
            word += c;
        } else if (!word.empty()) {
            trie.insert(word);
            word.clear();
        }
    }
    trie.insert(word);
    cout << most_common_word << ' ' << max_frequency;
    return 0;
}

//another solution, HashMap
/*


//1071 Speech Patterns
#include <iostream>
#include <unordered_map>

using namespace std;

int max_frequency = 0;
string most_common_word;

int main() {
    string text;
    getline(cin, text);
    unordered_map<string ,int> um;
    string word;
    for (char c : text) {
        c = tolower(c);
        if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a')) {
            word += c;
        } else if (!word.empty()) {
            um[word]++;
            if (um[word] > max_frequency) {
                max_frequency = um[word];
                most_common_word = word;
            }
            word.clear();
        }
    }
    if (!word.empty() && ++um[word] > max_frequency) {
        max_frequency = um[word];
        most_common_word = word;
    }
    cout << most_common_word << ' ' << max_frequency;
    return 0;
}



*/