#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;
NODE *create_bst(NODE *root)
{
    int i, n, num;
    NODE *newnode, *temp, *parent;
    printf("Enter how many nodes you want to create\n");
    scanf("%d", &n);
    printf("Enter data in node\n");
    for (i = 0; i < n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        scanf("%d", &num);
        newnode->data = num;
        newnode->left = newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (num < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    return root;
}
void preorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        printf("%d\t\n", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d\t\n", temp->data);
        inorder(temp->right);
    }
}
void postorder(NODE *root)
{
    NODE *temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t\n", temp->data);
    }
}
NODE *search(NODE *root, int key)
{
    NODE *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;
        else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}
void main()
{
    NODE *root = NULL;
    NODE *t;
    int ch, k;
    do
    {
        printf("1. Create\n2. Search\n3. Inorder \n4. Preorder\n5. Postorder\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                root = create_bst(root);
                break;
            case 2: 
                printf("Enter a node you want to search\n");
                scanf("%d", &k);
                t = search(root, k);
                if (t == NULL)
                    printf("Not found\n");
                else
                    printf("Found\n");
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                exit(0);
        }
    } while (ch != 6);
}
