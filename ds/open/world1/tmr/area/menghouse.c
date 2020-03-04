// Room: /u/t/tmr/area/menghouse.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "村長家");
        set("long", @LONG
這就是孟村村長的住處了，屋內擺設簡單，向陽處的牆壁皆開了扇窗
戶，照得滿室明亮，令人神清氣爽，牆上還掛了一幅書法。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"vroad1",
	]));
        set("item_desc", ([
	"書法" : "一幅看來豪氣干雲的書法，上頭寫著「劈掛參八極，英雄歎莫及」。\n",
	]));
	create_door("north","木板門","south",DOOR_CLOSED);
	set("objects",([
		__DIR__"npc/meng" : 1 ,
	]) );
	set("light",1);
        set("no_clean_up", 0);
        setup();
}
