#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"武器店"NOR);
 set("long",@LONG
來到這裡，你發現牆上掛著許多武器，刀、槍、劍等等都有
，旁邊有一團火焰，老闆正在那裡打鐵，如果你有需要的話，可
以跟老闆說唷！要看價目表的話請打(list)。

LONG
    );

       set("exits",([
       "southwest":__DIR__"town26",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     


