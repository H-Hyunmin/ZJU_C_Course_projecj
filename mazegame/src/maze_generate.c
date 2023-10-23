#include "../head/maze_generate.h"
#include "../head/draw_gui.h"
#include "../head/draw_map.h"
//迷宫地图基本信息
int row, col;
int start_x, start_y;
int end_x, end_y;

int current_x, current_y;//当前位置

struct posi_info** MAZE;//迷宫地图



void initmap(posi_info***  pointer){
	int i = 0, j = 0;
		for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			(*pointer)[i][j].access = 0; // 该位置是否被访问过
			(*pointer)[i][j].pre = NULL; // 该位置的前驱位置
			(*pointer)[i][j].row = i; // 该位置所在的行数
			(*pointer)[i][j].column = j; // 该位置所在的列数
			(*pointer)[i][j].pass_direction[0] = 0; // 初始化墙
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
			(*pointer)[i][j].access = 0; // 该位置是否被访问过
			(*pointer)[i][j].pre = NULL; // 该位置的前驱位置
			(*pointer)[i][j].row = i; // 该位置所在的行数
			(*pointer)[i][j].column = j; // 该位置所在的列数
			(*pointer)[i][j].pass_direction[0] = 1; // 初始化墙
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
// 该函数用于生成一个指定大小的迷宫地图
// 参数 row: 迷宫地图的行数
// 参数 col: 迷宫地图的列数
// 返回值: 生成的迷宫地图
struct posi_info** produce_init_maze(int row, int col) {
	int i = 0;
	// 为迷宫地图分配内存空间
	struct posi_info**  pointer = (struct posi_info**)malloc(row * sizeof(struct posi_info*));
	for (; i < row; i++) {
		pointer[i] = (struct posi_info*)malloc(col * sizeof(struct posi_info));
	}
    initmap(&pointer);
	return pointer; // 返回生成的迷宫地图
}

struct posi_info** produce_blank_maze(int row, int col){
	int i;
	// 为迷宫地图分配内存空间
	struct posi_info**  pointer = (struct posi_info**)malloc(row * sizeof(struct posi_info*));
	for (; i < row; i++) {
		pointer[i] = (struct posi_info*)malloc(col * sizeof(struct posi_info));
	}
	initblankmap(&pointer);
	return pointer; // 返回生成的迷宫地图
}
/*
这段代码使用 Prim 算法生成迷宫。Prim 算法是一种基于贪心策略的最小生成树算法，用于在加权连通图中生成一棵最小生成树。
 在这个迷宫生成算法中，首先随机选择一个起点，然后将该起点标记为已访问。
 接着，从当前位置开始，随机选择一个未访问的相邻位置，并打通两个位置之间的墙，将该相邻位置标记为已访问。
 如果当前位置没有未访问的相邻位置，则随机选择一个已访问的位置作为当前位置。重复这个过程，直到所有位置都被访问过。
 这个算法的核心思想是，从一个起点开始，不断扩展迷宫，直到所有位置都被访问过。
 在扩展迷宫的过程中，随机选择一个未访问的相邻位置，并打通两个位置之间的墙，将该相邻位置标记为已访问。
 这样可以确保迷宫的生成是随机的，并且每个位置都有机会被访问到。最终生成的迷宫是一个连通的图，其中每个位置都可以通过相邻的位置到达。
*/ 
// 该函数使用 Prim 算法生成迷宫
// 参数 pointer: 迷宫地图
// 参数 row: 迷宫地图的行数
// 参数 col: 迷宫地图的列数
void prim_creatmaze(struct posi_info** pointer, int row, int col) {
    // 定义当前位置指针和已访问的位置数量
	srand((unsigned int)time(NULL));//设置随机数种子
	// 随机选择一个起点
	int x = (int)(rand() % row);//随机生成行数
	int y = (int)(rand() % col);//随机生成列数
	int max = (int)rand() % (row/3 + col/3);
	if (max < 1)
		max = 1;
	if (max > 15)
		max = 15;
	int cnt = 0;

	struct posi_info* curPosi = (struct posi_info*)malloc(sizeof(struct posi_info));//当前位置指针
	struct posi_info* adjPosi;//相邻位置指针
	int access_cout = 1;//已访问的位置数量
	curPosi = &(pointer[x][y]);//当前位置指针指向随机生成的位置
	curPosi->access = 1;//将当前位置标记为已访问


	// 当已访问的位置数量小于迷宫地图大小时，继续生成迷宫
	while (access_cout < row * col) {
		// 如果当前位置有未访问的相邻位置，则随机选择一个相邻位置并打通两个位置之间的墙
		//has_adj_node判断当前位置是否有未访问的相邻位置
		if (unaccessed_adjacentnode(pointer, row, col, curPosi->row, curPosi->column)) {
			adjPosi = random_adjacentnode(pointer, row, col, curPosi->row, curPosi->column);//随机选择一个相邻位置
			if (adjPosi->access != 1) {//如果该相邻位置未被访问
				eliminate_wall(pointer, curPosi->row, curPosi->column, adjPosi->row, adjPosi->column);//打通两个位置之间的墙
				curPosi = adjPosi;//将当前位置指针指向随机选择的相邻位置
				curPosi->access = 1;//将当前位置标记为已访问
				access_cout++;//已访问的位置数量加一
			}
		}
		// 如果当前位置没有未访问的相邻位置，则随机选择一个已访问的位置作为当前位置
		
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


	// 计数，记录已经打开的墙壁数量
	while (cnt < max) {
		if (y - 1 >= 0) {
				if (pointer[x][y].pass_direction[0] != 1 && pointer[x][y - 1].pass_direction[1] != 1) {
					eliminate_wall(pointer, x, y, x, y - 1);
					cnt++;
				}
			//}
		}
	
		// 如果该位置右边有墙壁，则打开该墙壁
		if (y + 1 < col) {
				if (pointer[x][y].pass_direction[1] != 1 && pointer[x][y + 1].pass_direction[0] != 1) {
					eliminate_wall(pointer, x, y, x, y + 1);
					cnt++;
				}
			//}
		}
	
		// 如果该位置上面有墙壁，则打开该墙壁
		if (x - 1 >= 0) {
				if (pointer[x][y].pass_direction[2] != 1 && pointer[x - 1][y].pass_direction[3] != 1) {
					eliminate_wall(pointer, x, y, x - 1, y);
					cnt++;
				}
			//}
		}
	
		// 如果该位置下面有墙壁，则打开该墙壁
		if (x + 1 < row) {
				if (pointer[x][y].pass_direction[3] != 1 && pointer[x + 1][y].pass_direction[2] != 1) {
					eliminate_wall(pointer, x, y, x + 1, y);
					cnt++;
				}
			//}
		}

		// 随机选择一个新的位置
		x = (int)(rand() % row);
		y = (int)(rand() % col);
	}



}




// 从给定位置的相邻位置中随机选择一个位置
// 参数 pointer: 迷宫地图
// 参数 row: 迷宫地图的行数
// 参数 col: 迷宫地图的列数
// 参数 x: 给定位置的行数
// 参数 y: 给定位置的列数
// 返回值: 随机选择的相邻位置的指针
// 需要考虑给定位置在第一行、最后一行、第一列和最后一列的情况
struct posi_info* random_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y) {

	// 随机选择一个方向
	int rand_direction = (int)(rand() % 4);//dir随机四个方向 0 左, 1 右, 2 上, 3 下
	

	// 如果给定位置在第一行
	if (x == 0) {
		// 如果给定位置在第一列
		if (y == 0) {
			if (rand_direction == 2 || rand_direction == 0) rand_direction =3- rand_direction;

		}
		// 如果给定位置在最后一列
		else if (y == col - 1) {
			if (rand_direction == 2 || rand_direction == 1) rand_direction = 0;

		}
		// 如果给定位置不在第一列和最后一列之间
		else {
			if (rand_direction == 2) rand_direction =3- rand_direction;

		}
	}

	// 如果给定位置在最后一行
	else if (x == row - 1) {
		// 如果给定位置在第一列
		if (y == 0) {
			if (rand_direction == 3 || rand_direction == 0) rand_direction =rand_direction%2+1;

		}
		// 如果给定位置在最后一列
		else if (y == col - 1) {
			if (rand_direction == 3 || rand_direction == 1) rand_direction =3-rand_direction;

		}
		// 如果给定位置不在第一列和最后一列之间
		else {
			if (rand_direction == 3) rand_direction =rand_direction%2;

		}
	}
	
	// 如果给定位置不在第一行和最后一行之间
	else {
		// 如果给定位置在第一列
		if (y == 0) {
			 if (rand_direction == 0) rand_direction =1+(int)(rand() % 3);

		}
		// 如果给定位置在最后一列
		if (y == col - 1) {
			if (rand_direction == 1) rand_direction =2+(int)(rand() % 2);

		}
	}

	// 根据随机选择的方向返回相应的相邻位置的指针
	switch (rand_direction) {
		case 0: return &pointer[x][y - 1];
		case 1: return &pointer[x][y + 1];
		case 2: return &pointer[x - 1][y];
		case 3: return &pointer[x + 1][y];
	}
}


// 这个函数用于清除迷宫中两个相邻位置之间的墙壁。
// 它接受一个位置的二维数组和两个位置的坐标作为参数。
// 函数确定两个位置相对于彼此的方向，并在该方向上清除它们之间的墙壁。
// 参数：
// - arr：位置的二维数组
// - x1：第一个位置的x坐标
// - y1：第一个位置的y坐标
// - x2：第二个位置的x坐标
// - y2：第二个位置的y坐标
void wall(struct posi_info *pointer,int direction){
	(*pointer).pass_direction[direction]=1;
}
void eliminate_wall(struct posi_info** pointer, int x1, int y1, int x2, int y2) {

	// 如果第二个位置在第一个位置的左边，
	// 清除第一个位置左边的墙壁和第二个位置右边的墙壁。
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
		All_route = generate_List_LinkStack();//初始化解决方案栈
		current_stack = Init_LinkStack();//初始化中间栈

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		//初始化和生成迷宫
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
		All_route = generate_List_LinkStack();//初始化解决方案栈
		current_stack = Init_LinkStack();//初始化中间栈
		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		 MAZE = produce_blank_maze(row,col);
		//绘制地图
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

		All_route = generate_List_LinkStack();//初始化解决方案栈
		current_stack = Init_LinkStack();//初始化中间栈

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		//初始化和生成迷宫
		MAZE = produce_init_maze(row, col);
		prim_creatmaze(MAZE, row, col);

		//绘制地图
		Draw_Maze(MAZE, row, col);
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}

//
void generate_blank_maze(int mode,int difficulty) {
	
	if (mode == 1) {
		All_route = generate_List_LinkStack();//初始化解决方案栈
		current_stack = Init_LinkStack();//初始化中间栈

		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		current_x = start_x, current_y = start_y;
		  MAZE = produce_blank_maze(row,col);
		//绘制地图
		Draw_Maze(MAZE, row, col);
		//绘制其它
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
	if (fp == NULL) { // 如果文件不存在，则返回NULL
		printf("Error opening!\n");
		exit(1);
	}

	
	}
}