#include <bits/stdc++.h>
using namespace std;

// height of binary tree from inorder and lvlorder traversal
//used unorderedmap for storing indexe of inorder traversal
//by using queue we can compute height


int heightOfTheTree(vector<int> &inorder, vector<int> &levelorder, int N)
{
    queue<vector<int>> q; // start,end ,height
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    if (mp.find(levelorder[0]) != mp.end())
    {
        // no right subtree
        if (mp[levelorder[0]] == inorder.size() - 1)
        {
            q.push({0, inorder.size() - 2, 1});
            // no left subtree
        }
        else if (mp[levelorder[0]] == 0)
        {
            q.push({1, (int)inorder.size() - 1, 1});
        }
        else
        {
            q.push({0, mp[levelorder[0]] - 1, 1});                  // left subtree
            q.push({mp[levelorder[0]] + 1, inorder.size() - 1, 1}); // right subtree
        }
    }

    int k = 1;//k for traversing in lvlorder
    int ans = 0;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        ans = max(ans, curr[2]);
        if (mp.find(levelorder[k]) != mp.end())
        {
            // if it is the leaf node then no left subtree and right subtree
            if (curr[0] == curr[1])
            {
                ans = max(ans, curr[2] + 1);
                // root is the last element in inorder traversal then it has no right subtree
            }
            else if (mp[levelorder[k]] == curr[1])
            {
                q.push({curr[0], curr[1] - 1, curr[2] + 1});
                // root is the first element in inorder traversal then it has no left subtree
            }
            else if (mp[levelorder[k]] == curr[0])
            {
                q.push({curr[0] + 1, curr[1], curr[2] + 1});
            }
            else
            {
                // left subtree
                q.push({curr[0], mp[levelorder[k]] - 1, curr[2] + 1});
                // right subtree
                q.push({mp[levelorder[k]] + 1, curr[1], curr[2] + 1});
            }
        }
        k++;
    }
    return ans - 1;
}
