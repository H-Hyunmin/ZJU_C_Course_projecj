#include "../head/maze_generate.h"
#include "../head/draw_gui.h"
#include "../head/draw_map.h"
//�Թ���ͼ������Ϣ
int row, col;
int start_x, start_y;
int end_x, end_y;

int current_x, current_y;//��ǰλ��

struct posi_info** MAZE;//�Թ���ͼ



void initmap(posi_info***  pointer){
	int i = 0, j = 0;
		for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			(*pointer)[i][j].access = 0; // ��λ���Ƿ񱻷��ʹ�
			(*pointer)[i][j].pre = NULL; // ��λ�õ�ǰ��λ��
			(*pointer)[i][j].row = i; // ��λ�����ڵ�����
			(*pointer)[i][j].column = j; // ��λ�����ڵ�����
			(*pointer)[i][j].pass_direction[0] = 0; // ��ʼ��ǽ
			(*pointer)[i][j].pass_direction[1] = 0;
			(*pointer)[i][j].pass_direction[2] = 0;
			(*pointer)[i][j].pass_direction[3] = 0;

		}
	}
}
void initblankmap(posi_info***  pointer){
	int i = 0, j = 0;
		for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			(*pointer)[i][j].access = 0; // ��λ���Ƿ񱻷��ʹ�
			(*pointer)[i][j].pre = NULL; // ��λ�õ�ǰ��λ��
			(*pointer)[i][j].row = i; // ��λ�����ڵ�����
			(*pointer)[i][j].column = j; // ��λ�����ڵ�����
			(*pointer)[i][j].pass_direction[0] = 1; // ��ʼ��ǽ
			(*pointer)[i][j].pass_direction[1] = 1;
			(*pointer)[i][j].pass_direction[2] = 1;
			(*pointer)[i][j].pass_direction[3] = 1;
		}
	}
		for (i=0;i<row;i++){
				(*pointer)[i][0].pass_direction[0]=0;
				(*pointer)[i][col-1].pass_direction[1]=0;
		}
		for (j=0;j<col;j++){
				(*pointer)[0][j].pass_direction[2]=0;
				(*pointer)[row-1][j].pass_direction[3]=0;
		}
}
// �ú�����������һ��ָ����С���Թ���ͼ
// ���� row: �Թ���ͼ������
// ���� col: �Թ���ͼ������
// ����ֵ: ���ɵ��Թ���ͼ
struct posi_info** produce_init_maze(int row, int col) {
	int i = 0;
	// Ϊ�Թ���ͼ�����ڴ�ռ�
	struct posi_info**  pointer = (struct posi_info**)malloc(row * sizeof(struct posi_info*));
	for (; i < row; i++) {
		pointer[i] = (struct posi_info*)malloc(col * sizeof(struct posi_info));
	}
    initmap(&pointer);
	return pointer; // �������ɵ��Թ���ͼ
}

struct posi_info** produce_blank_maze(int row, int col){
	int i;
	// Ϊ�Թ���ͼ�����ڴ�ռ�
	struct posi_info**  pointer = (struct posi_info**)malloc(row * sizeof(struct posi_info*));
	for (; i < row; i++) {
		pointer[i] = (struct posi_info*)malloc(col * sizeof(struct posi_info));
	}
	initblankmap(&pointer);
	return pointer; // �������ɵ��Թ���ͼ
}
/*
��δ���ʹ�� Prim �㷨�����Թ���Prim �㷨��һ�ֻ���̰�Ĳ��Ե���С�������㷨�������ڼ�Ȩ��ͨͼ������һ����С��������
 ������Թ������㷨�У��������ѡ��һ����㣬Ȼ�󽫸������Ϊ�ѷ��ʡ�
 ���ţ��ӵ�ǰλ�ÿ�ʼ�����ѡ��һ��δ���ʵ�����λ�ã�����ͨ����λ��֮���ǽ����������λ�ñ��Ϊ�ѷ��ʡ�
 �����ǰλ��û��δ���ʵ�����λ�ã������ѡ��һ���ѷ��ʵ�λ����Ϊ��ǰλ�á��ظ�������̣�ֱ������λ�ö������ʹ���
 ����㷨�ĺ���˼���ǣ���һ����㿪ʼ��������չ�Թ���ֱ������λ�ö������ʹ���
 ����չ�Թ��Ĺ����У����ѡ��һ��δ���ʵ�����λ�ã�����ͨ����λ��֮���ǽ����������λ�ñ��Ϊ�ѷ��ʡ�
 ��������ȷ���Թ�������������ģ�����ÿ��λ�ö��л��ᱻ���ʵ����������ɵ��Թ���һ����ͨ��ͼ������ÿ��λ�ö�����ͨ�����ڵ�λ�õ��
*/ 
// �ú���ʹ�� Prim �㷨�����Թ�
// ���� pointer: �Թ���ͼ
// ���� row: �Թ���ͼ������
// ���� col: �Թ���ͼ������
void prim_creatmaze(struct posi_info** pointer, int row, int col) {
    // ���嵱ǰλ��ָ����ѷ��ʵ�λ������
	srand((unsigned int)time(NULL));//�������������
	// ���ѡ��һ�����
	int x = (int)(rand() % row);//�����������
	int y = (int)(rand() % col);//�����������
	int max = (int)rand() % (row/3 + col/3);
	if (max < 1)
		max = 1;
	if (max > 15)
		max = 15;
	int cnt = 0;

	struct posi_info* curPosi = (struct posi_info*)malloc(sizeof(struct posi_info));//��ǰλ��ָ��
	struct posi_info* adjPosi;//����λ��ָ��
	int access_cout = 1;//�ѷ��ʵ�λ������
	curPosi = &(pointer[x][y]);//��ǰλ��ָ��ָ��������ɵ�λ��
	curPosi->access = 1;//����ǰλ�ñ��Ϊ�ѷ���


	// ���ѷ��ʵ�λ������С���Թ���ͼ��Сʱ�����������Թ�
	while (access_cout < row * col) {
		// �����ǰλ����δ���ʵ�����λ�ã������ѡ��һ������λ�ò���ͨ����λ��֮���ǽ
		//has_adj_node�жϵ�ǰλ���Ƿ���δ���ʵ�����λ��
		if (unaccessed_adjacentnode(pointer, row, col, curPosi->row, curPosi->column)) {
			adjPosi = random_adjacentnode(pointer, row, col, curPosi->row, curPosi->column);//���ѡ��һ������λ��
			if (adjPosi->access != 1) {//���������λ��δ������
				eliminate_wall(pointer, curPosi->row, curPosi->column, adjPosi->row, adjPosi->column);//��ͨ����λ��֮���ǽ
				curPosi = adjPosi;//����ǰλ��ָ��ָ�����ѡ�������λ��
				curPosi->access = 1;//����ǰλ�ñ��Ϊ�ѷ���
				access_cout++;//�ѷ��ʵ�λ��������һ
			}
		}
		// �����ǰλ��û��δ���ʵ�����λ�ã������ѡ��һ���ѷ��ʵ�λ����Ϊ��ǰλ��
		
		else{
			x = (int)(rand() % row);
			y = (int)(rand() % col);
			while (pointer[x][y].access != 1) {
			x = (int)(rand() % row);
			y = (int)(rand() % col);
	}
		curPosi=&(pointer[x][y]);
			//curPosi = random_accessed_adjacentnode(pointer, row, col);
		}
	}


	// ��������¼�Ѿ��򿪵�ǽ������
	while (cnt < max) {
		if (y - 1 >= 0) {
				if (pointer[x][y].pass_direction[0] != 1 && pointer[x][y - 1].pass_direction[1] != 1) {
					eliminate_wall(pointer, x, y, x, y - 1);
					cnt++;
				}
			//}
		}
	
		// �����λ���ұ���ǽ�ڣ���򿪸�ǽ��
		if (y + 1 < col) {
				if (pointer[x][y].pass_direction[1] != 1 && pointer[x][y + 1].pass_direction[0] != 1) {
					eliminate_wall(pointer, x, y, x, y + 1);
					cnt++;
				}
			//}
		}
	
		// �����λ��������ǽ�ڣ���򿪸�ǽ��
		if (x - 1 >= 0) {
				if (pointer[x][y].pass_direction[2] != 1 && pointer[x - 1][y].pass_direction[3] != 1) {
					eliminate_wall(pointer, x, y, x - 1, y);
					cnt++;
				}
			//}
		}
	
		// �����λ��������ǽ�ڣ���򿪸�ǽ��
		if (x + 1 < row) {
				if (pointer[x][y].pass_direction[3] != 1 && pointer[x + 1][y].pass_direction[2] != 1) {
					eliminate_wall(pointer, x, y, x + 1, y);
					cnt++;
				}
			//}
		}

		// ���ѡ��һ���µ�λ��
		x = (int)(rand() % row);
		y = (int)(rand() % col);
	}



}




// �Ӹ���λ�õ�����λ�������ѡ��һ��λ��
// ���� pointer: �Թ���ͼ
// ���� row: �Թ���ͼ������
// ���� col: �Թ���ͼ������
// ���� x: ����λ�õ�����
// ���� y: ����λ�õ�����
// ����ֵ: ���ѡ�������λ�õ�ָ��
// ��Ҫ���Ǹ���λ���ڵ�һ�С����һ�С���һ�к����һ�е����
struct posi_info* random_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y) {

	// ���ѡ��һ������
	int rand_direction = (int)(rand() % 4);//dir����ĸ����� 0 ��, 1 ��, 2 ��, 3 ��
	

	// �������λ���ڵ�һ��
	if (x == 0) {
		// �������λ���ڵ�һ��
		if (y == 0) {
			if (rand_direction == 2 || rand_direction == 0) rand_direction =3- rand_direction;

		}
		// �������λ�������һ��
		else if (y == col - 1) {
			if (rand_direction == 2 || rand_direction == 1) rand_direction = 0;

		}
		// �������λ�ò��ڵ�һ�к����һ��֮��
		else {
			if (rand_direction == 2) rand_direction =3- rand_direction;

		}
	}

	// �������λ�������һ��
	else if (x == row - 1) {
		// �������λ���ڵ�һ��
		if (y == 0) {
			if (rand_direction == 3 || rand_direction == 0) rand_direction =rand_direction%2+1;

		}
		// �������λ�������һ��
		else if (y == col - 1) {
			if (rand_direction == 3 || rand_direction == 1) rand_direction =3-rand_direction;

		}
		// �������λ�ò��ڵ�һ�к����һ��֮��
		else {
			if (rand_direction == 3) rand_direction =rand_direction%2;

		}
	}
	
	// �������λ�ò��ڵ�һ�к����һ��֮��
	else {
		// �������λ���ڵ�һ��
		if (y == 0) {
			 if (rand_direction == 0) rand_direction =1+(int)(rand() % 3);

		}
		// �������λ�������һ��
		if (y == col - 1) {
			if (rand_direction == 1) rand_direction =2+(int)(rand() % 2);

		}
	}

	// �������ѡ��ķ��򷵻���Ӧ������λ�õ�ָ��
	switch (rand_direction) {
		case 0: return &pointer[x][y - 1];
		case 1: return &pointer[x][y + 1];
		case 2: return &pointer[x - 1][y];
		case 3: return &pointer[x + 1][y];
	}
}


// ���������������Թ�����������λ��֮���ǽ�ڡ�
// ������һ��λ�õĶ�ά���������λ�õ�������Ϊ������
// ����ȷ������λ������ڱ˴˵ķ��򣬲��ڸ÷������������֮���ǽ�ڡ�
// ������
// - arr��λ�õĶ�ά����
// - x1����һ��λ�õ�x����
// - y1����һ��λ�õ�y����
// - x2���ڶ���λ�õ�x����
// - y2���ڶ���λ�õ�y����
void wall(struct posi_info *pointer,int direction){
	(*pointer).pass_direction[direction]=1;
}
void eliminate_wall(struct posi_info** pointer, int x1, int y1, int x2, int y2) {

	// ����ڶ���λ���ڵ�һ��λ�õ���ߣ�
	// �����һ��λ����ߵ�ǽ�ں͵ڶ���λ���ұߵ�ǽ�ڡ�
	if (y2 < y1) {
		wall(&pointer[x1][y1],0);
		wall(&pointer[x2][y2],1);
	}
	else if (y2 > y1) {
		wall(&pointer[x1][y1],1);
		wall(&pointer[x2][y2],0);
	}
	else if (x2 < x1) {
		wall(&pointer[x1][y1],2);
		wall(&pointer[x2][y2],3);

	}
	else if (x2 > x1) {
		wall(&pointer[x1][y1],3);
		wall(&pointer[x2][y2],2);
	}
}






void define_generate_maze(int define_row,int define_col) {
	int mode=1;
	row=define_row;
	col=define_col;
	if (mode == 1) {
		All_route = generate_List_LinkStack();//��ʼ���������ջ
		current_stack = Init_LinkStack();//��ʼ���м�ջ

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		//��ʼ���������Թ�
		MAZE = produce_init_maze(row, col);
		prim_creatmaze(MAZE, row, col);
		Draw_Maze(MAZE, row, col);
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}


void define_generateblank_maze(int define_row,int define_col) {
	int mode=1;
	row=define_row;
	col=define_col;
	if (mode == 1) {
		All_route = generate_List_LinkStack();//��ʼ���������ջ
		current_stack = Init_LinkStack();//��ʼ���м�ջ
		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		 MAZE = produce_blank_maze(row,col);
		//���Ƶ�ͼ
		Draw_Maze(MAZE, row, col);
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}
//maze
void generate_maze(int mode,int difficulty) {
	if (mode == 1) {
	if (difficulty == 1) {
		row = 10, col = 10;
	}
	if (difficulty == 2) {
		row = 20, col = 20;
	}
	if (difficulty == 3) {
		row = 30, col = 30;
	}

		All_route = generate_List_LinkStack();//��ʼ���������ջ
		current_stack = Init_LinkStack();//��ʼ���м�ջ

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		//��ʼ���������Թ�
		MAZE = produce_init_maze(row, col);
		prim_creatmaze(MAZE, row, col);

		//���Ƶ�ͼ
		Draw_Maze(MAZE, row, col);
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}

//
void generate_blank_maze(int mode,int difficulty) {
	
	if (mode == 1) {
		All_route = generate_List_LinkStack();//��ʼ���������ջ
		current_stack = Init_LinkStack();//��ʼ���м�ջ

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		  MAZE = produce_blank_maze(row,col);
		//���Ƶ�ͼ
		Draw_Maze(MAZE, row, col);
		//��������
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}


void export_map(struct posi_info** pointer, int row, int col,int cx, int cy, double time, int mode, int difficulty,int mode2_guan) {
	OPENFILENAME ofn;
	char szFile[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Text Files (*.m)\0*.m\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&ofn) == TRUE)
	{
		char filePath[MAX_PATH];
		strcpy(filePath, szFile);
		const char *fileExtension = ".m";
		size_t extensionPos = strlen(filePath) - 4;
		if (extensionPos == 0 || strcmp(filePath + extensionPos, fileExtension) != 0)
		{
			strcat(filePath, fileExtension);
		}
		strcpy(szFile, filePath);
		FILE *fp = fopen(szFile, "wb");
		if (fp == NULL){
		printf("Error opening!\n");
		exit(1);
		}

		}

}






struct posi_info** open_map(int* row, int* col,int* cx, int* cy, double* time, int* mode, int* difficulty,int* mode2_guan){

		OPENFILENAME ofn;

	char szFile[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Text Files (*.m)\0*.m\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
		FILE *fp = fopen(szFile, "rb");
	if (fp == NULL) { // ����ļ������ڣ��򷵻�NULL
		printf("Error opening!\n");
		exit(1);
	}

	
	}
}