#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"迪蘭斯大道"NOR);
        set ("long", @LONG
隨性的逛逛後，你眼前不遠處有一座皇宮，那裡
就是超龍軍團各幹部及分團的重鎮了。而在你西北方
，徐徐炊煙冉冉上昇，那裡大概就是兵營了，雖說只
是個軍團本部，但沒想到竟然規模如此的龐大！
LONG);
        
        set("exits", ([
        "south": __DIR__"dragon2",
        "north": __DIR__"dragon7",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
