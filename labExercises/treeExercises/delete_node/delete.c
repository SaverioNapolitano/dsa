#include "tree.h"
#include <stdint.h>

Node* GetNodeWithMaximumKey(Node* n) {
    while (!TreeIsEmpty(TreeRight(n))) {
        n = TreeRight(n);
    }
    return n;
}

Node* DeleteBstNodeRec(Node* n, const ElemType* key) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
        n->left = DeleteBstNodeRec(TreeLeft(n), key);
    }
    else if (ElemCompare(key, TreeGetRootValue(n)) > 0) {
        n->right = DeleteBstNodeRec(TreeRight(n), key);
    }
    else {
        if (TreeIsLeaf(n)) {
            TreeDelete(n);
            return NULL;
        }
        else if (TreeLeft(n) && TreeRight(n)) {
            Node* predecessor = GetNodeWithMaximumKey(TreeLeft(n));
            ElemDelete(&n->value);
            n->value = ElemCopy(TreeGetRootValue(predecessor));
            n->left = DeleteBstNodeRec(TreeLeft(n), TreeGetRootValue(predecessor));
            return n;
        }
        else {
            Node* child = (TreeLeft(n)) ? TreeLeft(n) : TreeRight(n);
            Node* curr = n;

            n = child;

            ElemDelete(&curr->value);
            free(curr);
            return n;
        }
    }
    return n;
}

Node* DeleteBstNode(Node* n, const ElemType* key) {
    return DeleteBstNodeRec(n, key);
}