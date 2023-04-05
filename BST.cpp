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
    // 트리가 비어있지 않을 때 사용하는 삽입 함수
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
    // 재귀적 호출을 위한 함수 선언
    Node *_delete(T data, Node *node)
    {
    }

public:
    Node *root;
    Tree()
    {
        root = nullptr;
    }

    // 데이터 삽입 함수
    void insert(T data)
    {
        // 트리가 비어있을 경우 루트 노드에 데이터 삽입
        if (root == nullptr)
            root = new Node(data);
        // 트리가 비어있지 않을경우 사용하는 삽입 함수
        else
            _insert(data);
    }

    // 데이터 삭제 함수
    void delete(T data)
    {
        root = _delete(data, root);
    }
};