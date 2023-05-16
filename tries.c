#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26];
    int flag; // 1 if the string is in our trie, 0 otherwise
} TrieNode;

typedef struct TrieNode2 {
    struct TrieNode2* children[26];
    int flag; // 1 if the string is in the trie, 0 otherwise
    int numwords; // the total # of words stored in this sub-trie.
} TrieNode2;

int newNodeCount(TrieNode* root, char* str) {
    if (root == NULL) {
        return 0;
    }
    int count = 0, len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (root->children[str[i] - 'a'] == NULL) {
            count++;
            root = root->children[str[i] - 'a'];
        }
    }
    return count;
}

int numWordsWithPrefix(TrieNode2* root, char* prefix) {
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        if (root->children[prefix[i] - 'a'] == NULL) {
            return 0;
        }
        root = root->children[prefix[i] - 'a'];
    }
    return root->numwords;
}

int countStringsWithLetter(TrieNode2* root, char alpha) {
    if (root == NULL || root->children == NULL) {
        return 0;
    }
    if (root->children[alpha - 'a'] == alpha) {
        return 0;
    }
    //do the thing
    int count = 0;
    count += countStringsWithLetter(root->children[alpha - 'a'], alpha);
    return count;
}
