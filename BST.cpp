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
    // 트리가 비어있지 않을 때 사용하는 삽입 함수
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

    // 서브트리의 가장 작은 노드를 찾는 함수
    Node<T> *findMin(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // 재귀적 호출을 위한 함수 선언
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

    // 데이터 삽입 함수
    void insert(const T &data)
    {
        // 트리가 비어있을 경우 루트 노드에 데이터 삽입
        if (rootNode == nullptr)
            rootNode = new Node<T>(data);
        // 트리가 비어있지 않을경우 사용하는 삽입 함수
        else
            _insert(data, rootNode);
    }

    // 데이터 삭제 함수
    void remove(const T &data)
    {
        if (rootNode == nullptr)
        {
            cout << "Tree is empty" << std::endl;
            return;
        }

        rootNode = _remove(data, rootNode);
    }

    // 중위순회하며 데이터를 출력하는 함수
    void inorderPrint()
    {
        _inorderPrint(rootNode);
    }

    // 트리 전체를 삭제하는 함수
    void destroy()
    {
        _destroy(rootNode);
    }
};
