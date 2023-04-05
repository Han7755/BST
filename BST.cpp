#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node()
    {
        data = T();
        left = nullptr;
        right = nullptr;
    }
    Node(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class Tree
{
private:
    // Ʈ���� ������� ���� �� ����ϴ� ���� �Լ�
    void _insert(T data, Node *node)
    {
        if (data > node->data)
        {
            if (node->left == nullptr)
                node->left = new Node(data);
            else
                _insert(data, node->left);
        }
        else
        {
            if (node->right == nullptr)
                node->right = new Node(data);
            else
                _insert(data, node->right);
        }
    }
    // ����� ȣ���� ���� �Լ� ����
    Node *_delete(T data, Node *node)
    {
    }

public:
    Node *root;
    Tree()
    {
        root = nullptr;
    }

    // ������ ���� �Լ�
    void insert(T data)
    {
        // Ʈ���� ������� ��� ��Ʈ ��忡 ������ ����
        if (root == nullptr)
            root = new Node(data);
        // Ʈ���� ������� ������� ����ϴ� ���� �Լ�
        else
            _insert(data);
    }

    // ������ ���� �Լ�
    void delete(T data)
    {
        root = _delete(data, root);
    }
};