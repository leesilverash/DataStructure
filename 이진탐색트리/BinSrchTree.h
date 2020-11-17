#include "BinaryTree.h"
class BinSrchTree : public BinaryTree
{
public:
    BinSrchTree(void) {}
    ~BinSrchTree(void) {}
    // 이진 탐색 트리의 탐색 연산
    BinaryNode *search(int key)
    {
        BinaryNode *node = searchRecur(getRoot(), key);
        if (node != NULL)
        {
            printf("탐색 성공: 키 값이 %d인 보드 = 0x%x\n", node->getData(), node);
        }
        else
        {
            printf("탐색 실패: 키 값이 %d인 보드 없음\n", key);
        }
        return node;
    }
    // 순환적인 탐색 함수
    BinaryNode *searchRecur(BinaryNode *n, int key)
    {
        if (n == NULL)
            return NULL;
        if (key == n->getData())
            return n;
        else if (key < n->getData())
            return searchRecur(n->getLeft(), key);
        else
            return searchRecur(n->getRight(), key);
    }

    // 반복으로 구현한 탐색 함수
    BinaryNode *searchIter(BinaryNode *n, int key)
    {
        while (n != NULL)
        {
            if (key == n->getData())
                return n;
            else if (key < n->getData())
            {
                n = n->getLeft();
            }
            else
            {
                n = n->getRight();
            }
        }
        return NULL;
    }
    // 이진 탐색 트리의 삽입 연산 (순환)
    void insert( BinaryNode* n){
        if (n == NULL) return;
        if( isEmpty() )setRoot(n);
        else{
            insertRecur(getRoot(), n);
        }
    }
    void insertRecur(BinaryNode *r, BinaryNode *n)
    {
        if (n->getData() == r->getData())
        {
            return;
        }
        else if (n->getData() < r->getData())
        {
            if (r->getLeft() == NULL)
            {
                r->setLeft(n);
            }
            else
            {
                insertRecur(r->getLeft(), n);
            }
        }
        else
        {
            if (r->getRight() == NULL)
            {
                r->setRight(n);
            }
            else
            {
                insertRecur(r->getRight(), n);
            }
        }
    }

    // 이진 탐색 트리의 삭제 연산
    void remove(int key){
        if( isEmpty() ) return;
        BinaryNode *parent = NULL;
        BinaryNode* node = getRoot();

        while( node != NULL && node -> getData() != key ){
            parent=node;
            node = (key < node->getData()) 
            ? node->getLeft() : node->getRight();
        }
        if (node==NULL){
            printf(" Error: key is not in the tree!\n");
            return;
        }
        else remove(parent, node);
    }
    void remove(BinaryNode *parent, BinaryNode *node)
    {
        // Case 1: 삭제하려는 노드가 단말 노드일 경우
        if (node->isLeaf())
        {
            if (parent == NULL)
            {
                setRoot(NULL);
            }
            else{
                if( parent ->getLeft() == node){
                    parent->setLeft(NULL);
                }
                else{
                    parent->setRight(NULL);
                }
            }
        }
        // Case 2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
        else if (node->getLeft() == NULL || node->getRight() == NULL)
        {
            // 삭제할 노드의 유일한 자식 노드 => child
            // 삼항식 : node의 왼쪽이 NULL이 아닌 경우가 참이면 node의 왼쪽 자식을 삭제하고 참이 아닌 경우 node의 오른쪽 자식을 삭제한다.
            BinaryNode *child = (node->getLeft() != NULL)
                                    ? node->getLeft()
                                    : node->getRight();
            // 삭제할 노드가 루트이면 child가 새로운 root가 됨.
            if (node == getRoot())
                setRoot(child);
            // 아니면 부모 노드의 자식으로 자식 노드 child를 직접 연결
            else
            {
                if (parent->getLeft() == node)
                {
                    parent->setLeft(child);
                }
                else
                {
                    parent->setRight(child);
                }
            }
        }
        // Case 3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우
        else
        {
            // 삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색
            // succ => 후계 노드: 오른쪽 서브트리에서 가장 key가 작은 노드
            // succp => 후게 노드의 부모 노드
            BinaryNode *succp = node;
            BinaryNode *succ = node->getRight();
            while (succ->getLeft() != NULL)
            {
                succp = succ;
                succ = succ->getLeft();
            }
            // 후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결
            if (succp->getLeft() == succ)
            {
                succp->setLeft(succ->getRight());
            }
            else
            {
                succp->setRight(succ->getRight());
            }
            // 후계 노드 정보를 삭제할 노드에 복사
            node->setData(succ->getData());
            //삭제할 노드를 후계 노드로 변경 : 실제로는 후계 노드가 제거됨
            node = succ;
        }
        delete node; // 메모리 동적 해제
    }
};