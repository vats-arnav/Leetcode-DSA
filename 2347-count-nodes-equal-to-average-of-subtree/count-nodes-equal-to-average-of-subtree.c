int traversal(struct TreeNode * node, int * count, int * result)
{
    if(node)
    {

        int l_subtree_nodes = 0;
        int l_sum = traversal(node->left, &l_subtree_nodes, result);

        int r_subtree_nodes = 0;
        int r_sum = traversal(node->right, &r_subtree_nodes, result);

        int average = (l_sum + r_sum + node->val) / (1 + l_subtree_nodes + r_subtree_nodes);
        if(average == node->val)
        {
            *result += 1;
        }

        *count = (1 + l_subtree_nodes + r_subtree_nodes);
        return (node->val + l_sum + r_sum);
    }
    else
    {
        *count = 0;
    }
    return 0;
}

int averageOfSubtree(struct TreeNode* root) 
{
    int count = 0;
    int result = 0;
    traversal(root, &count, &result);
    return result;
}