// https://iudex.io/problem/617be03b97713f0001037521/statement

#include <iostream>

using namespace std;

class BinaryTree
{
public:
    int val;
    int height = 666;
    int bf;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

BinaryTree *bstInsert(BinaryTree *&root, int val)
{
    if (root == NULL)
    {
        BinaryTree *newTree = new BinaryTree(val);
        root = newTree;
        return root;
    }
    if (val < root->val)
    {
        bstInsert(root->left, val);
        return root;
    }
    else
    {
        bstInsert(root->right, val);
        return root;
    }
}

int height(BinaryTree *root)
{
    if (!root)
        return 0;

    int HL = height(root->left);
    int HR = height(root->right);

    return 1 + max(HL, HR);
}

void balanceFactor(BinaryTree *root, bool &flag)
{
    int HR = 0, HL = 0;
    if (root->right)
    {
        if (root->right->height == 666)
            root->right->height = height(root->right);

        HR = root->right->height;
    }

    if (root->left)
    {
        if (root->left->height == 666)
            root->left->height = height(root->left);

        HL = root->left->height;
    }

    root->bf = HR - HL;

    if (root->bf > 1 || root->bf < -1)
    {
        flag = false;
        return;
    }

    if (root->left)
        balanceFactor(root->left, flag);
    if (root->right)
        balanceFactor(root->right, flag);
}

BinaryTree *rotateLeft(BinaryTree *&root, int &left_count)
{
    BinaryTree *R = root->right;
    BinaryTree *RL = R->left;

    R->left = root;
    root->right = RL;
    left_count++;

    return R;
}

BinaryTree *rotateRight(BinaryTree *&root, int &right_count)
{
    BinaryTree *L = root->left;
    BinaryTree *LR = L->right;

    L->right = root;
    root->left = LR;
    right_count++;

    return L;
}

void igualaEsq(BinaryTree *&S, BinaryTree *&T, int &right_count)
{
    while (S->val != T->val)
        S = rotateRight(S, right_count);
}

void igualaDir(BinaryTree *&S, BinaryTree *&T, int &left_count)
{
    while (S->val != T->val)
        S = rotateLeft(S, left_count);
}

void iguala(BinaryTree *&S, BinaryTree *&T, int &right_count, int &left_count)
{
    if (S && T)
    {
        igualaEsq(S, T, right_count);
        BinaryTree *root = S;

        if (root->left && T->left)
            igualaEsq(S->left, T->left, right_count);

        if (root->right && T->right)
            igualaDir(S->right, T->right, left_count);

        iguala(root->left, T->left, right_count, left_count);
        iguala(root->right, T->right, right_count, left_count);
    }
}

void pos_order(BinaryTree *&root, int &N)
{
    if (root == NULL)
        return;

    pos_order(root->left, N);
    pos_order(root->right, N);

    cout << root->val << ((--N) > 0 ? " " : "");
}

int main(void)
{
    int i, N, elto;

    while (cin >> N)
    {
        BinaryTree *S = NULL;
        BinaryTree *T = NULL;
        BinaryTree *rootS = NULL, *rootNow = NULL;
        bool flag = 0;
        int left_count = 0, right_count = 0;

        for (i = 0; i < N; i++)
        {
            cin >> elto;
            bstInsert(S, elto);
        }

        for (i = 0; i < N; i++)
        {
            cin >> elto;
            bstInsert(T, elto);
        }

        // Tornar S uma espinha à esquerda
        while (S->right || S->left)
        {
            if (S->right != NULL)
            {
                S = rotateLeft(S, left_count);

                if (flag)
                    rootNow->left = S;
            }

            else // if (S->left != NULL)
            {
                if (!flag)
                {
                    rootS = S;
                    flag = true;
                }

                rootNow = S;
                S = S->left;
            }
        }

        S = rootS;

        // Transformar S em T
        iguala(S, T, right_count, left_count);

        cout << left_count << " " << right_count << endl;
        pos_order(T, N);
        cout << endl;

        flag = 1;
        balanceFactor(T, flag);
        cout << (flag ? "true" : "false") << endl
             << endl;

        delete S;
        delete T;
    }

    return 0;
}
