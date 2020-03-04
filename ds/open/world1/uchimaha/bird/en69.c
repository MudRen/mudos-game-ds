#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林﹝泥沼區﹞");
 set("long",@LONG
你來到東北澤林的森林泥沼區, 你看到地上有一條
大蛇爬過的痕跡, 痕跡非常的大, 應該是一種非常大的
蛇所留下的...

LONG
    );
 
 set("exits",(["south":__DIR__"en71",
               "northwest":__DIR__"en63",
               "north":__DIR__"en64",
              ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
