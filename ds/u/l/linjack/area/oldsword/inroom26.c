#include <room.h>
inherit ROOM;
void create()
{
 set("short","八極門賓室");
 set("long",@LONG
這邊就是最近才開始漸漸名聲大噪起來的八極門賓室, 裡邊的
牆上掛了幾把短槍短矛, 大至上擺設都還沒有動過, 裡面只有兩名
八極門的弟子在此休息, 他們對這個環境似乎不是很滿意. 桌上擺
了一些酒菜和幾本書.
LONG
    );
 set("exits",(["north":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
