#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");
 set("long",@LONG
你終於走出了沼澤地帶, 你不禁心中放下一顆大石,
你環顧了四周, 樹林似乎沒有先前那樣茂密了, 你的東
方有一條泥土路, 好像有人們在那活動的樣子.
LONG
    );
 
 set("exits",(["north":__DIR__"en32",
               "east":__DIR__"village2",
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
