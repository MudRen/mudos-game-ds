#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你站在一棵擁有茂密枝葉的大樹底下, 強烈的陽光
讓你睜不開眼, 你的旁邊有一個小販, 他正在整理他的
東西, 你如果覺得肚子餓, 可以買點東西來吃, 再往東
走就是無人的森林深處了。
LONG
    );
 
 set("exits",(["east":__DIR__"en6",
               "south":__DIR__"en3",
     ]));
 set("objects",([__DIR__"npc/waiter3" : 1,
     ]));
 set("no_fight", 1);
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           
