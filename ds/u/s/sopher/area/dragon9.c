#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"超龍第一分部入口前"NOR);
        set ("long", @LONG
由此再往西走就是軍團分部了，你隱隱約約
聽到陣陣吆喝聲與兵器鏗鏗鏘鏘的接觸聲，有點
恐怖.....
LONG);  
        
        set("exits", ([
        "west" : __DIR__"warrior1",
        "east" : __DIR__"dragon7",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
