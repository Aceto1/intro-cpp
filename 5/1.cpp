#include <string>
#include <iostream>

typedef struct Node
{
  Node *left;
  Node *right;
  std::string key;

  explicit Node(const std::string newKey)
  {
    left = NULL;
    right = NULL;
    key = newKey;
  }
} Node;

void insert(Node * & node, const std::string key)
{
  if (node == NULL)
  {
    node = new Node(key);
  }
  else
  {
    int comparison = node->key.compare(key);

    if (comparison < 0)
      insert(node->right, key);
    else if (comparison > 0)
      insert(node->left, key);
    else
      return;
  }
}

void list(Node *node)
{
  if (node->left != NULL)
    list(node->left);

  std::cout << node->key + " ";

  if (node->right != NULL)
    list(node->right);
}

void free(Node *node)
{
  if (node)
  {
    free(node->left);
    free(node->right);
    delete node;
  }
}

int main()
{
  Node* root = NULL;

  while (true)
  {
    std::cout << "Geben Sie einen Schlüssel ein:\n";

    std::string key;
    std::cin >> key;

    if (key.compare(".") == 0)
      break;

    insert(root, key);
  }

  list(root);
  free(root);

  return 0;
}