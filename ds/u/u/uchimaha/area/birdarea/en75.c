#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你往東北走了過來, 你看了看四周, 除了平常的巨大
樹木以外, 什麼也沒有, 你感覺到這條路越來越小, 好像
快走到小路的盡頭了.

LONG
    );
 
 set("exits",(["southwest":__DIR__"en74",
               "north":__DIR__"en76",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
