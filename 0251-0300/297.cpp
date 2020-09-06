#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        // string ans = "";
        // rserialize(root,ans);

        if (root == NULL)
            return "";
        string ans;
        queue<TreeNode *> q;
        q.push(root);
        int vaild = 1;

        while (vaild > 0)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL)
            {
                ans += "X,";
            }
            else
            {
                vaild--;
                ans += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
                if (cur->left != NULL)
                    vaild++;
                if (cur->right != NULL)
                    vaild++;
            }
        }
        ans.pop_back();
        return ans;
    }

    void split(const string &s, vector<string> &tokens, const string &delimiters)
    {
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos)
        {
            tokens.push_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delimiters, pos);
            pos = s.find_first_of(delimiters, lastPos);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> arr;
        split(data, arr, ",");

        //int i = 0;
        //return rdeserialize(arr,i);

        queue<TreeNode *> q;
        if (arr[0] == "X")
            return NULL;
        TreeNode *root = new TreeNode(stoi(arr[0]));
        q.push(root);
        int index = 1;
        while (true)
        {

            TreeNode *cur = q.front();
            q.pop();
            if (index >= arr.size())
                break;
            if (arr[index] != "X")
            {
                TreeNode *nn = new TreeNode(stoi(arr[index]));
                q.push(nn);
                cur->left = nn;
            }
            index++;
            if (index >= arr.size())
                break;
            if (arr[index] != "X")
            {
                TreeNode *nn = new TreeNode(stoi(arr[index]));
                q.push(nn);
                cur->right = nn;
            }
            index++;
        }
        return root;
    }

    void rserialize(TreeNode *root, string &str)
    {
        if (root == NULL)
            str += "X,";
        else
        {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    TreeNode *rdeserialize(vector<string> &arr, int &index)
    {
        if (arr[index] == "X")
        {
            index++;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(arr[index]));
        index++;
        root->left = rdeserialize(arr, index);
        root->right = rdeserialize(arr, index);
        return root;
    }
};