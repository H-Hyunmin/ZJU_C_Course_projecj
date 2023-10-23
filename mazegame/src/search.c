#include "../head/search.h"

/**
 * @brief 广度优先搜索函数，用于寻找迷宫中两点之间的最短路径
 * 
 * @param pointer 二维数组，表示迷宫地图
 * @param row 迷宫地图的行数
 * @param col 迷宫地图的列数
 * @param x1 起点的行坐标
 * @param y1 起点的列坐标
 * @param x2 终点的行坐标
 * @param y2 终点的列坐标
 * @return struct LinkStack* 返回一个指向栈的指针，存储从起点到终点的最短路径
 */
void access(struct posi_info *pointer){
	pointer->access=1;
}

void add(struct posi_info **position_list,struct posi_info *posi,struct posi_info *pre){
				access(posi);
				Enter_LinkQueue(position_list, *posi); // 将左边的位置入队
				posi->pre = pre;
};

void initsearch(struct posi_info** pointer){
		int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			pointer[i][j].access = 0; // 初始化每个位置的访问状态
			pointer[i][j].pre = NULL; // 初始化每个位置的前驱位置
		}
	}
}

void add_route(struct List_LinkStack_node** newhead, struct List_LinkStack** All_route,struct LinkStack** current_route){
	(*newhead)->value = **current_route;
	//将新节点插入到链表栈顶
	(*newhead)->next = (*All_route)->head;
	(*All_route)->head = *newhead;
	//链表栈大小加1
	(*All_route)->size++;

}


struct LinkStack* BFS_Search(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2) { // 广度优先搜索
	struct LinkStack* route = Init_LinkStack(); // 初始化栈，用于存储路径
	initsearch(pointer);

	//struct LinkQueue* position_list = generate_LinkQueue(); // 初始化队列，用于存储待访问的位置
	struct LinkQueue* position_list = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
	//初始化队列头、尾和大小
	position_list->head = NULL;
	position_list->tail = NULL;
	position_list->size = 0;
	//Enter_LinkQueue(position_list, pointer[x1][y1]); // 将起点入队
		if (position_list->head == NULL) {
		//分配内存空间
		position_list->head = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		position_list->tail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//将元素添加到队列头
		position_list->head->value = pointer[x1][y1];
		position_list->head->next = NULL;
		//队列尾指向队列头
		position_list->tail = position_list->head;
		//队列大小加1
		position_list->size++;
	}
	else {
		//分配内存空间
		struct LinkQueue_node* newtail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//将元素添加到队列尾
		newtail->value = pointer[x1][y1];
		newtail->next = NULL;
		position_list->tail->next = newtail;
		//队列尾指向新的队列尾
		position_list->tail = newtail;
		//队列大小加1
		position_list->size++;
	}

	access(&pointer[x1][y1]);
	//pointer[x1][y1].access = 1; // 标记起点已经被访问过
	while (!position_list->size==0) { // 当队列不为空时，继续遍历
		//struct posi_info temp = Exit_LinkQueue(position_list); // 取出队首元素
			//如果队列不为空
		struct posi_info temp;
	if (position_list->head != NULL) {
		//队列大小减1
		position_list->size--;
		//获取队列头元素
		temp = position_list->head->value;
		//队列头指向下一个元素
		position_list->head = position_list->head->next;
	
	}

		if (temp.row == x2 && temp.column == y2) { // 如果当前位置是终点，结束遍历
			Push_LinkStack(route, pointer[temp.row][temp.column]); // 将终点入栈
			while (pointer[temp.row][temp.column].pre != NULL) { // 从终点开始，依次将前驱位置入栈
				Push_LinkStack(route, *pointer[temp.row][temp.column].pre);
				temp = *pointer[temp.row][temp.column].pre;
			}
			break;
		} 

		else { // 如果当前位置不是终点，继续遍历
			if (temp.pass_direction[0] == 1 && pointer[temp.row][temp.column - 1].access != 1) { // 如果可以向左移动，且左边的位置没有被访问过
				add(position_list, &pointer[temp.row][temp.column - 1],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[1] == 1 && pointer[temp.row][temp.column + 1].access != 1) { // 如果可以向右移动，且右边的位置没有被访问过
				add(position_list, &pointer[temp.row][temp.column + 1],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[2] == 1 && pointer[temp.row - 1][temp.column].access != 1) { // 如果可以向上移动，且上面的位置没有被访问过
				add(position_list, &pointer[temp.row-1][temp.column],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[3] == 1 && pointer[temp.row + 1][temp.column].access != 1) { // 如果可以向下移动，且下面的位置没有被访问过
				add(position_list, &pointer[temp.row+1][temp.column],&pointer[temp.row][temp.column]);
			}
		}
	}
	return route; // 返回路径
}







/*
 * 深度优先搜索算法，用于寻找迷宫中两点之间的路径
 * 用一个栈保存每次路径的中间信息
 * 用一个队列的队列存储所有路径，全局变量
 * @param pointer 指向当前位置的指针
 * @param row 迷宫地图的行数
 * @param col 迷宫地图的列数
 * @param x1 起点的横坐标
 * @param y1 起点的纵坐标
 * @param x2 终点的横坐标
 * @param y2 终点的纵坐标
 * @param x 当前位置的横坐标
 * @param y 当前位置的纵坐标
 * @param deep 当前递归的深度，用于判断是否为第一次进入函数
 */

void DFS(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2, int x, int y, int deep) {
	// 如果deep为0，表示第一次进入dfs函数，需要初始化地图为未访问状态，清空中间栈和解栈
	if (deep == 0) {
		initsearch(pointer);
		while (current_stack->size!=0) { //清空中间栈
			Pop_LinkStack(current_stack); 
		}
		while (All_route->head !=NULL){//清空解栈
			All_route->head = All_route->head->next;
		}
		Push_LinkStack(current_stack, pointer[x1][y1]); //将起点入栈
		access(&pointer[x1][y1]);
		x = x1, y = y1;
	}

	if (x == x2 && y == y2) {
		int s = current_stack->size;  //当前栈的大小
		struct LinkStack* current_route = Init_LinkStack(); //新建一个栈，用于保存一条路径

		while (current_stack->size!=0) {
			struct posi_info temp=Pop_LinkStack(current_stack);//
			Push_LinkStack(current_route, temp); //将中间栈中的元素依次出栈并入解栈
		}

		struct LinkStack_node* h = current_route->head; //解栈头指针
		while (h != NULL) { 
			Push_LinkStack(current_stack, h->value); //将解栈中的元素依次出栈并入中间栈
			h = h->next;
		}


		pointer[x][y].access = 0; //将当前位置设置为未访问
	
		struct List_LinkStack_node* newhead = (struct LinkStack_node*)malloc(sizeof(struct LinkStack_node));
		add_route(&newhead,&All_route, &current_route);

	}
     int nextx,nexty;
	// 如果左侧可走且未访问过，将左侧位置入栈并递归
	if (pointer[x][y].pass_direction[0] == 1 && pointer[x][y - 1].access != 1) {
		 nextx = x, nexty = y - 1; 
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]); //将左侧位置入栈
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep); //递归
		Pop_LinkStack(current_stack); //回溯，将当前位置出栈
	}

	// 如果右侧可走且未访问过，将右侧位置入栈并递归
	if (pointer[x][y].pass_direction[1] == 1 && pointer[x][y + 1].access != 1) {
		 nextx = x, nexty = y + 1;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}

	// 如果上方可走且未访问过，将上方位置入栈并递归
	if (pointer[x][y].pass_direction[2] == 1 && pointer[x - 1][y].access != 1) {
		 nextx = x - 1, nexty = y;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}

	// 如果下方可走且未访问过，将下方位置入栈并递归
	if (pointer[x][y].pass_direction[3] == 1 && pointer[x + 1][y].access != 1) {
		 nextx = x + 1, nexty = y;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}	
	// 当前位置访问标记设为未访问
	// 在深度优先搜索（DFS）算法中，当遍历到一个节点时，需要将其标记为已访问，以避免重复访问。
	// 当DFS算法回溯到之前的节点时，需要将该节点的访问标记设为未访问，以便在后续的搜索中重新访问该节点。
	pointer[x][y].access = 0;
}

