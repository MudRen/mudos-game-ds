#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"藥舖"NOR);
 set("long",@LONG
這裡是村裡唯一的一家藥店，農們可就可以維到濃濃的藥草
大夫就站在前面磨藥粉，需要什麼草藥的話可以自己選喔！
但是大夫看起來好像有煩惱...

LONG
    );

       set("exits",([
       "east":__DIR__"town18",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
 set("light", 1);
}     


