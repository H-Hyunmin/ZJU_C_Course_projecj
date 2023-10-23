#ifndef __CALLBACK__
#define __CALLBACK__
#pragma comment (lib, "winmm.lib")
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <conio.h>


#include "../libgraphics/graphics.h"
#include "../libgraphics/extgraph.h"
#include "../libgraphics/genlib.h"
#include "../libgraphics/simpio.h"
#include "../libgraphics/strlib.h"
#include "../libgraphics/linkedlist.h"
#include "../libgraphics/imgui.h"
#include "../libgraphics/boolean.h"

#include "../libgraphics/gcalloc.h"
#include "../libgraphics/random.h"

#include "draw_gui.h"


extern int GameOn;
extern int GameTime;//��λ��0.01s


// ��������¼��ĺ���������key��ʾ���µļ���event��ʾ�¼����ͣ����»��ͷţ�
void KeyboardEventProcess(int key, int event);

// ��������¼��ĺ���������x��y��ʾ�������꣬button��ʾ���µ�������event��ʾ�¼����ͣ����»��ͷţ�
void MouseEventProcess(int x, int y, int button, int event);

void CharEventProcess(char c);
#endif // !__CALLBACK__
