#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內-二層"NOR);
 set("long",@LONG 
這裡是古洞的第二層，真沒想到，這個黑暗的古洞，竟然還
有分層，而且這裡似乎更恐怖了。耳邊傳來陣陣的野獸的慘叫聲
，似乎是野獸在互相自殘的聲音。
LONG
    );

       set("exits",([        
       "north":__DIR__"s2", 
//       "up":__DIR__"f12",  以免mob跑上去
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

