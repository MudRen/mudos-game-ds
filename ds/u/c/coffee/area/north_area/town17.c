#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"防具店"NOR);
 set("long",@LONG
來到這裡，兩旁的牆壁上掛著許多防具，金光閃閃，前面就
是櫃檯，老闆正站再那裡，如果你缺少防具的話，就買幾件防具
穿，捧場一下吧！！要看價目表請打(list)。

LONG
    );

       set("exits",([
       "southeast":__DIR__"town16",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

