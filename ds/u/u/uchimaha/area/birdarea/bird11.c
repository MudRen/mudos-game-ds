#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石頭路");

 set("long",@LONG
這是一條用石頭打造的路, 雖然說是石頭做的, 但
是走起來卻比平地還要平, 你看看四周, 發現路邊有一
個巨石碑(sign), 上面還有一些你從來沒有看過的鳥,
石頭路往東方延伸出去。

LONG
    );
 set("item_desc",([
        "sign":"你朝這石碑上看了看  "HIR"天
                    梟"NOR"        
你心想終於到了!     "HIR"教\n"NOR
     ]));
 set("exits",(["east":__DIR__"bird12",
               "southdown":__DIR__"bird10",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
