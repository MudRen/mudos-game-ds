#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡依然可以見到那根大的離譜的柱子, 你同時也發現到
南方傳來一陣藥香味, 似乎南方是天梟冶藥一派的藥材室, 也
許你可以去那要點藥材.
LONG
    );
 set("exits",([ "north":__DIR__"pill4",
		"southeast":__DIR__"pill8",
    ]));
 set("item_desc",([
        "柱子":"一根大大的柱子, 你發現上面有一些字:\n"
	          	HIY"四神歸位, 四物浮現.\n"NOR
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
