#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG
這裡的右邊是村長家的門口，聽說村長為人很善良，但是最
近卻好像有什麼煩惱的事情，到處再找人幫忙。左邊是一口井，
如果你有需要的話，可以去那裡飲水。

LONG
    );

       set("exits",([
       "north":__DIR__"town15",
       "west":__DIR__"town6",
       "east":__DIR__"town20",
       "south":__DIR__"town11",           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

