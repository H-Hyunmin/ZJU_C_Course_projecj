#include "../head/draw_map.h"



double zsjx(int row ,int col){
	double zsx;
       if (col % 2 == 0) {
        zsx=Centerx-col*1.0/2*Boxlength;
	   }
	   else {
	    zsx=Centerx-(col-1)*1.0/2*Boxlength-0.5*Boxlength;
	   }
	   return zsx;
}


double zsjy(int row ,int col){
	double zsy;
	if (row % 2 == 0) {
		zsy=10-Centery-row*1.0/2*Boxwidth;
	   }
	   else {
	    zsy=10-Centery-(row-1)*1.0/2*Boxwidth-0.5*Boxwidth;
	   }
	   return zsy;
}
double curzsjx(int y, int row, int col) {
	return Centerx - col * 1.0 / 2 * Boxlength + y * Boxlength;
}
double curzsjy(int x, int row, int col) {
	return Centery + row * 1.0 / 2 * Boxwidth - x * Boxwidth;
}
double txzsjy(int x, int row, int col) {
	return 10-Centery - row * 1.0 / 2 * Boxwidth + x * Boxwidth;
}


//(x,y)是左下角


void Draw_Maze(struct posi_info** pointer, int row, int col) {
	int i, j;	
	double curx, cury;
	//画迷宫背景
	double x=zsjx(row, col);
	double y=zsjy(row, col);
    draw_bmp("./picture/gameground.bmp",x ,y,col*Boxwidth,row*Boxlength);
	SetPenSize(0.8);
	SetPenColor("green");
	//遍历迷宫
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			curx = curzsjx(j, row, col); //当前格子左上角横坐标 
			cury = curzsjy(i, row, col);  //当前格子左上角纵坐标 
			if (pointer[i][j].pass_direction[0] == 0) {
                MovePen(curx-0.01, cury);
                DrawLine(0, -Boxwidth);
                MovePen(curx+0.01, cury);
                DrawLine(0, -Boxwidth);
                MovePen(curx, cury);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx, cury-Boxwidth/4);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx, cury-Boxwidth/2);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx, cury-Boxwidth*3/4);
                DrawLine(0, -Boxwidth/8);
            }


            if (pointer[i][j].pass_direction[1] == 0 && (i!=row-1 || j!=col-1)) {//终点不画右边
                MovePen(curx+ Boxlength-0.01, cury);
                DrawLine(0, -Boxwidth);
                MovePen(curx+ Boxlength+0.01, cury);
                DrawLine(0, -Boxwidth);
                MovePen(curx+ Boxlength, cury);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx+ Boxlength, cury-Boxwidth/4);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx+ Boxlength, cury-Boxwidth/2);
                DrawLine(0, -Boxwidth/8);
                MovePen(curx+ Boxlength, cury-Boxwidth*3/4);
                DrawLine(0, -Boxwidth/8);
            }
			if (pointer[i][j].pass_direction[2] == 0) {
                MovePen(curx, cury-0.01);
				DrawLine(Boxlength, 0);
                MovePen(curx, cury+0.01);
				DrawLine(Boxlength, 0);
                MovePen(curx, cury);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength/4, cury);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength/2, cury);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength*3/4, cury);
				DrawLine(Boxlength/8, 0);			
			}
			if (pointer[i][j].pass_direction[3] == 0) {
                MovePen(curx, cury- Boxwidth-0.01);
				DrawLine(Boxlength, 0);
                MovePen(curx, cury- Boxwidth+0.01);
				DrawLine(Boxlength, 0);
                MovePen(curx, cury- Boxwidth);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength/4, cury- Boxwidth);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength/2, cury- Boxwidth);
				DrawLine(Boxlength/8, 0);
                MovePen(curx+ Boxlength*3/4, cury- Boxwidth);
				DrawLine(Boxlength/8, 0);		
			}
		}
	}
}


/**
 * @brief 在迷宫中画出人物矩形
 * 
 * @param x 人物所在格子的行坐标
 * @param y 人物所在格子的列坐标
 * @param row 迷宫的行数
 * @param col 迷宫的列数
 * 
 * @details 该函数根据人物所在的格子坐标和迷宫的行列数，计算出人物矩形在图形界面上的位置，并在该位置画出人物.
 */
void Draw_Robot(int x, int y, int row, int col) {
	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = txzsjy(x, row, col);
	draw_bmp("./picture/robot.bmp",curx ,cury,0.9*Boxwidth,0.9*Boxlength);
}




//画终点
//x,y为格子的坐标 
void Draw_Destination(int x, int y, int row, int col) {

	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = txzsjy(x, row, col);
	draw_bmp("./picture/end.bmp",curx ,cury,0.9*Boxwidth,0.9*Boxlength);
}

//画轨迹
void Draw_Routine(struct LinkStack* LinkStack, int row, int col) {
	double curx, cury;
	double nextx, nexty;
	struct posi_info temp ; 

	if(!LinkStack->size==0){
		temp = Pop_LinkStack(LinkStack);
		curx = curzsjx(temp.column, row, col);
		cury = curzsjy(temp.row, row, col);
	}
	while (!LinkStack->size==0) {
		 temp = Pop_LinkStack(LinkStack);
		nextx = curzsjx(temp.column, row, col);
		nexty = curzsjy(temp.row, row, col);
		if (curx == nextx) {
			if (cury < nexty) {
				//向下
				draw_bmp("./picture/down.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//向上
				draw_bmp("./picture/up.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		else {
			if (curx > nextx) {
				//向左
				draw_bmp("./picture/left.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//向右
				draw_bmp("./picture/right.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		curx = nextx;
		cury = nexty;
	}
}


/**
 * @brief 在编辑模式下，将指定格子
 * 
 * @param x 格子的行坐标
 * @param y 格子的列坐标
 * @param row 迷宫的行数
 * @param col 迷宫的列数
 * 
 * 
 * @note 该函数只在编辑模式下使用。
 * 
 * 
 * @note 该函数使用了全局变量 Boxlength 和 Boxwidth
 * 
 * @note 该函数使用了迷宫坐标系和图形坐标系之间的转换函数 curzsjy 和 curzsjx。
 * 
 * @note 该函数没有返回值。
 */
void draw_selected(int x, int y, int row, int col) {
	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = curzsjy(x, row, col);
	// 画一个矩形，表示该格子被选中
	draw_bmp("./picture/selectblock.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);

}

// 判断给定位置的四周是否有未访问的相邻位置
// 参数 pointer: 迷宫地图
// 参数 row: 迷宫地图的行数
// 参数 col: 迷宫地图的列数
// 参数 x: 给定位置的行数
// 参数 y: 给定位置的列数
// 返回值: 如果给定位置的四周有未访问的相邻位置，则返回 1，否则返回 0
// 需要考虑给定位置在第一行、最后一行、第一列和最后一列的情况
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y) {
	// 如果给定位置在第一行
	if (x == 0) {// 如果给定位置在第一列
		if (y == 0) {
			return pointer[x + 1][y].access == 0 || pointer[x][y + 1].access == 0;// 判断给定位置的下方和右方是否有未访问的相邻位置
		}

		else if (y == col - 1) {// 如果给定位置在最后一列
			return pointer[x + 1][y].access == 0 || pointer[x][y - 1].access == 0;// 判断给定位置的下方和左方是否有未访问的相邻位置
		}

		else {// 如果给定位置不在第一列和最后一列之间
			return pointer[x + 1][y].access == 0 || pointer[x][y - 1].access == 0 || pointer[x][y + 1].access == 0;// 判断给定位置的下方、左方和右方是否有未访问的相邻位置
		}
	}
	
	else if (x == row - 1) {// 如果给定位置在最后一行
		
		if (y == 0) {// 如果给定位置在第一列
			return pointer[x - 1][y].access == 0 || pointer[x][y + 1].access == 0;// 判断给定位置的上方和右方是否有未访问的相邻位置
		}

		else if (y == col - 1) {// 如果给定位置在最后一列
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0;// 判断给定位置的上方和左方是否有未访问的相邻位置
		}
		
		else {// 如果给定位置不在第一列和最后一列之间
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x][y + 1].access == 0;// 判断给定位置的上方、左方和右方是否有未访问的相邻位置
		}
	}
	else {// 如果给定位置不在第一行和最后一行之间
		if (y == 0) {// 如果给定位置在第一列
			return pointer[x - 1][y].access == 0 || pointer[x][y + 1].access == 0|| pointer[x + 1][y].access == 0;// 判断给定位置的上方、右方和下方是否有未访问的相邻位置
		}
		
		if (y == col - 1) {// 如果给定位置在最后一列
			
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x + 1][y].access == 0;// 判断给定位置的上方、左方和下方是否有未访问的相邻位置
		}
		
		else {// 如果给定位置不在第一列和最后一列之间
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x + 1][y].access == 0 || pointer[x][y + 1].access == 0;// 判断给定位置的上方、左方、右方和下方是否有未访问的相邻位置
		}
	}
}

