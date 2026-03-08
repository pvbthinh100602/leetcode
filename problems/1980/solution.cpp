#include "solution.h"
#include <iostream>
#include <queue>

void insert(BinaryTrieNode* root, const string& s) {
    BinaryTrieNode* cur = root;

    for (char c : s) {
        int bit = c - '0';

        if (!cur->child[bit])
            cur->child[bit] = make_unique<BinaryTrieNode>();

        cur = cur->child[bit].get();
    }
}

string Solution::findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();

    auto root = make_unique<BinaryTrieNode>();

    for (const string& s : nums)
        insert(root.get(), s);

    queue<pair<BinaryTrieNode*, string>> q;
    q.push({root.get(), ""});

    while (!q.empty()) {
        auto [node, prefix] = q.front();
        q.pop();

        if (prefix.size() == n)
            continue;

        if (!node->child[0])
            return prefix + "0" + string(n - prefix.size() - 1, '0');

        if (!node->child[1])
            return prefix + "1" + string(n - prefix.size() - 1, '0');

        q.push({node->child[0].get(), prefix + "0"});
        q.push({node->child[1].get(), prefix + "1"});
    }

    return "";
}