#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
這裡的地板比較不會濕滑了，但是相反的地面卻震動得更厲
害了。前面可以看到一個用石磚建造而成的小房間，不知道裡面
有什麼奇特的東西，或者是又有更危險的野獸？
LONG
    );

       set("exits",([        
       "north":__DIR__"s18", 
       "west":__DIR__"s16", 
       "east":__DIR__"s17",
       "south":__DIR__"s6",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

