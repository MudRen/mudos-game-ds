#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","森林");

 set("long",@LONG
你彎下身鞠了幾口身前的清泉, 只覺神清氣爽, 精神百倍, 
似乎效果不比天梟聖泉差! 你舉頭一望, 只見有許多動物正在
此處生活, 四處祥和平凡, 這裡實與仙境相差無幾! 
LONG
    );
set("exits",([ "southeast":__DIR__"tree2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("objects", ([__DIR__"npc/deer" : 4
    ]));

 setup();
 replace_program(ROOM);
}
