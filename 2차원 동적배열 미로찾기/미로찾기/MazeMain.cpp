#include "Maze.h"

int main(void)

{
    Maze maze; //미로 탐색 객체 생성
    maze.load("Maze.txt");
    maze.print();
    maze.searchExit(); //미로를 탐색해 출구를 찾음
    maze.print();
    return 0;
}
