#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞內"NOR);
 set("long",@LONG 
這裡的地上十分凹凸不平，而且天花板又十分狹窄，一不小
心就會撞到頭。在這裡，你開始遇到了一些看起來十分弱小的野
獸，一不注意，牠就會衝過來偷襲你，請務必小心！
LONG
    );

       set("exits",([        
       "northeast":__DIR__"f1",       "southeast":__DIR__"f4",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

