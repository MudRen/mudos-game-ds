#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"街道"NOR);
 set("long",@LONG 
這裡十分熱鬧，到處充滿了熱鬧的吵雜聲，有小孩的草雜聲
，也有從市集傳來的叫賣聲，前面不遠處有一口井，那裡也聚集
很多人，也許有什麼有趣的事••

LONG
    );

       set("exits",([
       "north":__DIR__"town13",
       "east":__DIR__"town32",
       "west":__DIR__"town5",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

