#include "../head/search.h"

/**
 * @brief ���������������������Ѱ���Թ�������֮������·��
 * 
 * @param pointer ��ά���飬��ʾ�Թ���ͼ
 * @param row �Թ���ͼ������
 * @param col �Թ���ͼ������
 * @param x1 ����������
 * @param y1 ����������
 * @param x2 �յ��������
 * @param y2 �յ��������
 * @return struct LinkStack* ����һ��ָ��ջ��ָ�룬�洢����㵽�յ�����·��
 */
void access(struct posi_info *pointer){
	pointer->access=1;
}

void add(struct posi_info **position_list,struct posi_info *posi,struct posi_info *pre){
				access(posi);
				Enter_LinkQueue(position_list, *posi); // ����ߵ�λ�����
				posi->pre = pre;
};

void initsearch(struct posi_info** pointer){
		int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			pointer[i][j].access = 0; // ��ʼ��ÿ��λ�õķ���״̬
			pointer[i][j].pre = NULL; // ��ʼ��ÿ��λ�õ�ǰ��λ��
		}
	}
}

void add_route(struct List_LinkStack_node** newhead, struct List_LinkStack** All_route,struct LinkStack** current_route){
	(*newhead)->value = **current_route;
	//���½ڵ���뵽����ջ��
	(*newhead)->next = (*All_route)->head;
	(*All_route)->head = *newhead;
	//����ջ��С��1
	(*All_route)->size++;

}


struct LinkStack* BFS_Search(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2) { // �����������
	struct LinkStack* route = Init_LinkStack(); // ��ʼ��ջ�����ڴ洢·��
	initsearch(pointer);

	//struct LinkQueue* position_list = generate_LinkQueue(); // ��ʼ�����У����ڴ洢�����ʵ�λ��
	struct LinkQueue* position_list = (struct LinkQueue*)malloc(sizeof(struct LinkQueue));
	//��ʼ������ͷ��β�ʹ�С
	position_list->head = NULL;
	position_list->tail = NULL;
	position_list->size = 0;
	//Enter_LinkQueue(position_list, pointer[x1][y1]); // ��������
		if (position_list->head == NULL) {
		//�����ڴ�ռ�
		position_list->head = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		position_list->tail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//��Ԫ����ӵ�����ͷ
		position_list->head->value = pointer[x1][y1];
		position_list->head->next = NULL;
		//����βָ�����ͷ
		position_list->tail = position_list->head;
		//���д�С��1
		position_list->size++;
	}
	else {
		//�����ڴ�ռ�
		struct LinkQueue_node* newtail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//��Ԫ����ӵ�����β
		newtail->value = pointer[x1][y1];
		newtail->next = NULL;
		position_list->tail->next = newtail;
		//����βָ���µĶ���β
		position_list->tail = newtail;
		//���д�С��1
		position_list->size++;
	}

	access(&pointer[x1][y1]);
	//pointer[x1][y1].access = 1; // �������Ѿ������ʹ�
	while (!position_list->size==0) { // �����в�Ϊ��ʱ����������
		//struct posi_info temp = Exit_LinkQueue(position_list); // ȡ������Ԫ��
			//������в�Ϊ��
		struct posi_info temp;
	if (position_list->head != NULL) {
		//���д�С��1
		position_list->size--;
		//��ȡ����ͷԪ��
		temp = position_list->head->value;
		//����ͷָ����һ��Ԫ��
		position_list->head = position_list->head->next;
	
	}

		if (temp.row == x2 && temp.column == y2) { // �����ǰλ�����յ㣬��������
			Push_LinkStack(route, pointer[temp.row][temp.column]); // ���յ���ջ
			while (pointer[temp.row][temp.column].pre != NULL) { // ���յ㿪ʼ�����ν�ǰ��λ����ջ
				Push_LinkStack(route, *pointer[temp.row][temp.column].pre);
				temp = *pointer[temp.row][temp.column].pre;
			}
			break;
		} 

		else { // �����ǰλ�ò����յ㣬��������
			if (temp.pass_direction[0] == 1 && pointer[temp.row][temp.column - 1].access != 1) { // ������������ƶ�������ߵ�λ��û�б����ʹ�
				add(position_list, &pointer[temp.row][temp.column - 1],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[1] == 1 && pointer[temp.row][temp.column + 1].access != 1) { // ������������ƶ������ұߵ�λ��û�б����ʹ�
				add(position_list, &pointer[temp.row][temp.column + 1],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[2] == 1 && pointer[temp.row - 1][temp.column].access != 1) { // ������������ƶ����������λ��û�б����ʹ�
				add(position_list, &pointer[temp.row-1][temp.column],&pointer[temp.row][temp.column]);
			}

			if (temp.pass_direction[3] == 1 && pointer[temp.row + 1][temp.column].access != 1) { // ������������ƶ����������λ��û�б����ʹ�
				add(position_list, &pointer[temp.row+1][temp.column],&pointer[temp.row][temp.column]);
			}
		}
	}
	return route; // ����·��
}







/*
 * ������������㷨������Ѱ���Թ�������֮���·��
 * ��һ��ջ����ÿ��·�����м���Ϣ
 * ��һ�����еĶ��д洢����·����ȫ�ֱ���
 * @param pointer ָ��ǰλ�õ�ָ��
 * @param row �Թ���ͼ������
 * @param col �Թ���ͼ������
 * @param x1 ���ĺ�����
 * @param y1 ����������
 * @param x2 �յ�ĺ�����
 * @param y2 �յ��������
 * @param x ��ǰλ�õĺ�����
 * @param y ��ǰλ�õ�������
 * @param deep ��ǰ�ݹ����ȣ������ж��Ƿ�Ϊ��һ�ν��뺯��
 */

void DFS(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2, int x, int y, int deep) {
	// ���deepΪ0����ʾ��һ�ν���dfs��������Ҫ��ʼ����ͼΪδ����״̬������м�ջ�ͽ�ջ
	if (deep == 0) {
		initsearch(pointer);
		while (current_stack->size!=0) { //����м�ջ
			Pop_LinkStack(current_stack); 
		}
		while (All_route->head !=NULL){//��ս�ջ
			All_route->head = All_route->head->next;
		}
		Push_LinkStack(current_stack, pointer[x1][y1]); //�������ջ
		access(&pointer[x1][y1]);
		x = x1, y = y1;
	}

	if (x == x2 && y == y2) {
		int s = current_stack->size;  //��ǰջ�Ĵ�С
		struct LinkStack* current_route = Init_LinkStack(); //�½�һ��ջ�����ڱ���һ��·��

		while (current_stack->size!=0) {
			struct posi_info temp=Pop_LinkStack(current_stack);//
			Push_LinkStack(current_route, temp); //���м�ջ�е�Ԫ�����γ�ջ�����ջ
		}

		struct LinkStack_node* h = current_route->head; //��ջͷָ��
		while (h != NULL) { 
			Push_LinkStack(current_stack, h->value); //����ջ�е�Ԫ�����γ�ջ�����м�ջ
			h = h->next;
		}


		pointer[x][y].access = 0; //����ǰλ������Ϊδ����
	
		struct List_LinkStack_node* newhead = (struct LinkStack_node*)malloc(sizeof(struct LinkStack_node));
		add_route(&newhead,&All_route, &current_route);

	}
     int nextx,nexty;
	// �����������δ���ʹ��������λ����ջ���ݹ�
	if (pointer[x][y].pass_direction[0] == 1 && pointer[x][y - 1].access != 1) {
		 nextx = x, nexty = y - 1; 
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]); //�����λ����ջ
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep); //�ݹ�
		Pop_LinkStack(current_stack); //���ݣ�����ǰλ�ó�ջ
	}

	// ����Ҳ������δ���ʹ������Ҳ�λ����ջ���ݹ�
	if (pointer[x][y].pass_direction[1] == 1 && pointer[x][y + 1].access != 1) {
		 nextx = x, nexty = y + 1;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}

	// ����Ϸ�������δ���ʹ������Ϸ�λ����ջ���ݹ�
	if (pointer[x][y].pass_direction[2] == 1 && pointer[x - 1][y].access != 1) {
		 nextx = x - 1, nexty = y;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}

	// ����·�������δ���ʹ������·�λ����ջ���ݹ�
	if (pointer[x][y].pass_direction[3] == 1 && pointer[x + 1][y].access != 1) {
		 nextx = x + 1, nexty = y;
		access(&pointer[nextx][nexty]);
		Push_LinkStack(current_stack, pointer[nextx][nexty]);
		DFS(pointer, row, col, x1, y1, x2, y2, nextx, nexty, ++deep);
		Pop_LinkStack(current_stack);
	}	
	// ��ǰλ�÷��ʱ����Ϊδ����
	// ���������������DFS���㷨�У���������һ���ڵ�ʱ����Ҫ������Ϊ�ѷ��ʣ��Ա����ظ����ʡ�
	// ��DFS�㷨���ݵ�֮ǰ�Ľڵ�ʱ����Ҫ���ýڵ�ķ��ʱ����Ϊδ���ʣ��Ա��ں��������������·��ʸýڵ㡣
	pointer[x][y].access = 0;
}

