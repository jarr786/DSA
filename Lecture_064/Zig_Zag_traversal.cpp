class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> final;
        if (root == NULL)
            return final;

        queue<Node *> q;
        q.push(root);

        bool lefttoright = true; // from tracking direction

        while (!q.empty())
        {
            int n = q.size();
            // making temp array
            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                Node *front = q.front();
                q.pop();
                int element = front->data;
                if (lefttoright == true)
                {
                    ans[i] = element;
                }
                else
                {
                    ans[n - i - 1] = element;
                }
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            // reversing direction
            lefttoright = !lefttoright;
            // coping temp aray into final aray
            for (auto i : ans)
            {
                final.push_back(i);
            }
        }
        return final;
    }
};