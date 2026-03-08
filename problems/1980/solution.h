#pragma once

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums);
};

class BinaryTrieNode {
public:
    unique_ptr<BinaryTrieNode> child[2];
};
