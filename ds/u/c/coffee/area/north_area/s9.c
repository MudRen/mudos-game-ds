#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG
這裡的地面都是泥沼，只要你一不小心，腳就會陷入泥巴中
，讓你行動十分困難。又面對數隻怪獸的追趕，還是小心一點吧
。
LONG
    );

       set("exits",([        
       "east":__DIR__"s5", 
       "south":__DIR__"s3",
       "west":__DIR__"s8",
           ]));        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

