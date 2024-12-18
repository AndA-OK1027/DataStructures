struct TreeNode
{
    int key;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

struct BinaryTree
{
    std::unique_ptr<TreeNode> root;

    void addNode(std::unique_ptr<TreeNode>& node, int key);

    std::unique_ptr<TreeNode>& findNode(std::unique_ptr<TreeNode>& node, int key);

    void deleteNode(std::unique_ptr<TreeNode>& node, int key);

    TreeNode* findMin(TreeNode* node);

    TreeNode* findMax(TreeNode* node);

    BinaryTree() : root(nullptr) {}

    void add(int key);

    void remove(int key);

    bool search(int key);

    int findMin();

    int findMax();
};