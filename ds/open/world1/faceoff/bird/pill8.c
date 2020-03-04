#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
從這裡往南走可以到天梟冶藥一派的藥材室, 往北則可以
回到大廳的中央部份, 不過這裡依然可以見到那根大大的柱子, 
不管怎麼樣, 還是去看看藥材室吧.
LONG
    );
 set("exits",([ "northwest":__DIR__"pill6",
		"northeast":__DIR__"pill12",
                "south":__DIR__"pill10",
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
