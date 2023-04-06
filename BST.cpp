#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(const T &data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree
{
private:
    // Ʈ���� ������� ���� �� ����ϴ� ���� �Լ�
    void _insert(const T &data, Node<T> *node)
    {
        if (data > node->data)
        {
            if (node->left == nullptr)
                node->left = new Node<T>(data);
            else
                _insert(data, node->left);
        }
        else
        {
            if (node->right == nullptr)
                node->right = new Node<T>(data);
            else
                _insert(data, node->right);
        }
    }

    // ����Ʈ���� ���� ���� ��带 ã�� �Լ�
    Node<T> *findMin(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // ����� ȣ���� ���� �Լ� ����
    Node<T> *_remove(const T &data, Node<T> *node)
    {
        if (node == nullptr)
            return nullptr;

        if (data < node->data)
            node->left = _remove(data, node->left);
        else if (data > node->data)
            node->right = _remove(data, node->right);
        else
        {
            if (node->left == nullptr)
            {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node<T> *temp = findMin(node->right);
                node->data = temp->data;
                node->right = _remove(node->data, node->right);
            }
            return node;
        }
    }

    void _inorderPrint(const Node<T> *node)
    {
        if (node == nullptr)
            return;

        _inorderPrint(node->left);
        std::cout << node->data << " ";
        _inorderPrint(node->right);
    }

    void _destroy(Node<T> *node)
    {
        if (node == nullptr)
            return;

        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

public:
    Node<T> *rootNode;

    Tree()
        : rootNode(nullptr) {}

    // ������ ���� �Լ�
    void insert(const T &data)
    {
        // Ʈ���� ������� ��� ��Ʈ ��忡 ������ ����
        if (rootNode == nullptr)
            rootNode = new Node<T>(data);
        // Ʈ���� ������� ������� ����ϴ� ���� �Լ�
        else
            _insert(data, rootNode);
    }

    // ������ ���� �Լ�
    void remove(const T &data)
    {
        if (rootNode == nullptr)
        {
            cout << "Tree is empty" << std::endl;
            return;
        }

        rootNode = _remove(data, rootNode);
    }

    // ������ȸ�ϸ� �����͸� ����ϴ� �Լ�
    void inorderPrint()
    {
        _inorderPrint(rootNode);
    }

    // Ʈ�� ��ü�� �����ϴ� �Լ�
    void destroy()
    {
        _destroy(rootNode);
    }
};
