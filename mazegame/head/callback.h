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
extern int GameTime;//单位是0.01s


// 处理键盘事件的函数，参数key表示按下的键，event表示事件类型（按下或释放）
void KeyboardEventProcess(int key, int event);

// 处理鼠标事件的函数，参数x和y表示鼠标的坐标，button表示按下的鼠标键，event表示事件类型（按下或释放）
void MouseEventProcess(int x, int y, int button, int event);

void CharEventProcess(char c);
#endif // !__CALLBACK__
