#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"市集"NOR);
 set("long",@LONG
這裡賣著許多物品，附近有許多人在排隊買東西，這裡的東 
西雖然蠻便宜的，但品質卻不錯唷！如果你想買東西，告訴你，
可以偷偷的插隊喔！

LONG
    );

       set("exits",([
       "east":__DIR__"town12",
       "west":__DIR__"town19",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
}     


