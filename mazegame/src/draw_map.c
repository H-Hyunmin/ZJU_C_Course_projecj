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


//(x,y)�����½�


void Draw_Maze(struct posi_info** pointer, int row, int col) {
	int i, j;	
	double curx, cury;
	//���Թ�����
	double x=zsjx(row, col);
	double y=zsjy(row, col);
    draw_bmp("./picture/gameground.bmp",x ,y,col*Boxwidth,row*Boxlength);
	SetPenSize(0.8);
	SetPenColor("green");
	//�����Թ�
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			curx = curzsjx(j, row, col); //��ǰ�������ϽǺ����� 
			cury = curzsjy(i, row, col);  //��ǰ�������Ͻ������� 
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


            if (pointer[i][j].pass_direction[1] == 0 && (i!=row-1 || j!=col-1)) {//�յ㲻���ұ�
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
 * @brief ���Թ��л����������
 * 
 * @param x �������ڸ��ӵ�������
 * @param y �������ڸ��ӵ�������
 * @param row �Թ�������
 * @param col �Թ�������
 * 
 * @details �ú��������������ڵĸ���������Թ�������������������������ͼ�ν����ϵ�λ�ã����ڸ�λ�û�������.
 */
void Draw_Robot(int x, int y, int row, int col) {
	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = txzsjy(x, row, col);
	draw_bmp("./picture/robot.bmp",curx ,cury,0.9*Boxwidth,0.9*Boxlength);
}




//���յ�
//x,yΪ���ӵ����� 
void Draw_Destination(int x, int y, int row, int col) {

	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = txzsjy(x, row, col);
	draw_bmp("./picture/end.bmp",curx ,cury,0.9*Boxwidth,0.9*Boxlength);
}

//���켣
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
				//����
				draw_bmp("./picture/down.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//����
				draw_bmp("./picture/up.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		else {
			if (curx > nextx) {
				//����
				draw_bmp("./picture/left.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//����
				draw_bmp("./picture/right.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		curx = nextx;
		cury = nexty;
	}
}


/**
 * @brief �ڱ༭ģʽ�£���ָ������
 * 
 * @param x ���ӵ�������
 * @param y ���ӵ�������
 * @param row �Թ�������
 * @param col �Թ�������
 * 
 * 
 * @note �ú���ֻ�ڱ༭ģʽ��ʹ�á�
 * 
 * 
 * @note �ú���ʹ����ȫ�ֱ��� Boxlength �� Boxwidth
 * 
 * @note �ú���ʹ�����Թ�����ϵ��ͼ������ϵ֮���ת������ curzsjy �� curzsjx��
 * 
 * @note �ú���û�з���ֵ��
 */
void draw_selected(int x, int y, int row, int col) {
	double curx, cury;
	curx = curzsjx(y, row, col);
	cury = curzsjy(x, row, col);
	// ��һ�����Σ���ʾ�ø��ӱ�ѡ��
	draw_bmp("./picture/selectblock.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);

}

// �жϸ���λ�õ������Ƿ���δ���ʵ�����λ��
// ���� pointer: �Թ���ͼ
// ���� row: �Թ���ͼ������
// ���� col: �Թ���ͼ������
// ���� x: ����λ�õ�����
// ���� y: ����λ�õ�����
// ����ֵ: �������λ�õ�������δ���ʵ�����λ�ã��򷵻� 1�����򷵻� 0
// ��Ҫ���Ǹ���λ���ڵ�һ�С����һ�С���һ�к����һ�е����
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y) {
	// �������λ���ڵ�һ��
	if (x == 0) {// �������λ���ڵ�һ��
		if (y == 0) {
			return pointer[x + 1][y].access == 0 || pointer[x][y + 1].access == 0;// �жϸ���λ�õ��·����ҷ��Ƿ���δ���ʵ�����λ��
		}

		else if (y == col - 1) {// �������λ�������һ��
			return pointer[x + 1][y].access == 0 || pointer[x][y - 1].access == 0;// �жϸ���λ�õ��·������Ƿ���δ���ʵ�����λ��
		}

		else {// �������λ�ò��ڵ�һ�к����һ��֮��
			return pointer[x + 1][y].access == 0 || pointer[x][y - 1].access == 0 || pointer[x][y + 1].access == 0;// �жϸ���λ�õ��·����󷽺��ҷ��Ƿ���δ���ʵ�����λ��
		}
	}
	
	else if (x == row - 1) {// �������λ�������һ��
		
		if (y == 0) {// �������λ���ڵ�һ��
			return pointer[x - 1][y].access == 0 || pointer[x][y + 1].access == 0;// �жϸ���λ�õ��Ϸ����ҷ��Ƿ���δ���ʵ�����λ��
		}

		else if (y == col - 1) {// �������λ�������һ��
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0;// �жϸ���λ�õ��Ϸ������Ƿ���δ���ʵ�����λ��
		}
		
		else {// �������λ�ò��ڵ�һ�к����һ��֮��
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x][y + 1].access == 0;// �жϸ���λ�õ��Ϸ����󷽺��ҷ��Ƿ���δ���ʵ�����λ��
		}
	}
	else {// �������λ�ò��ڵ�һ�к����һ��֮��
		if (y == 0) {// �������λ���ڵ�һ��
			return pointer[x - 1][y].access == 0 || pointer[x][y + 1].access == 0|| pointer[x + 1][y].access == 0;// �жϸ���λ�õ��Ϸ����ҷ����·��Ƿ���δ���ʵ�����λ��
		}
		
		if (y == col - 1) {// �������λ�������һ��
			
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x + 1][y].access == 0;// �жϸ���λ�õ��Ϸ����󷽺��·��Ƿ���δ���ʵ�����λ��
		}
		
		else {// �������λ�ò��ڵ�һ�к����һ��֮��
			return pointer[x - 1][y].access == 0 || pointer[x][y - 1].access == 0|| pointer[x + 1][y].access == 0 || pointer[x][y + 1].access == 0;// �жϸ���λ�õ��Ϸ����󷽡��ҷ����·��Ƿ���δ���ʵ�����λ��
		}
	}
}

