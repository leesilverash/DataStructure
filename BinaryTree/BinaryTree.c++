#include "BinaryTree.h"

int main()
{
    BinaryTree tree;
    BinaryNode *h = new BinaryNode('H', NULL, NULL);
    BinaryNode *g = new BinaryNode('G', NULL, NULL);
    BinaryNode *e = new BinaryNode('E', g, h);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);
    BinaryNode *d = new BinaryNode('D', NULL, NULL);
    BinaryNode *c = new BinaryNode('C', e, f);
    BinaryNode *b = new BinaryNode('B', d, NULL);
    BinaryNode *a = new BinaryNode('A', b, c);
    tree.setRoot(a);

    tree.preorder();
    tree.inorder();
    tree.postorder();
    tree.levelorder();
    printf("\n");

    printf("전체 노드 갯수 = %d개\n", tree.getCount());
    printf("단말 노드 갯수 = %d개\n", tree.getLeafCount());
    printf("트리의 높이는 = %d개\n", tree.getHeight());
}