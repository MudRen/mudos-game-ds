#include <room.h>
inherit ROOM;
void create()
{
 set("short","樹叢中");
 set("long",@LONG
這邊十分的安靜, 你仔細一聽, 只有樹葉被微風撥動的
細小聲音. 這邊十分的黑暗, 不過北邊似乎要比較亮些, 你
可以往那邊走過去. 旁邊有條小溪.
LONG
    );
 set("exits",(["southwest":__DIR__"outroom12",
               "north":__DIR__"outroom14",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}