#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS集團時空管理處通道"NOR);
        set ("long", @LONG
你來到了十字路口，四周空蕩蕩的，一股寒意
湧上了心頭。東邊往武器室，西邊則是通往時空管
理處大廳，而南邊，則是一條相當黑暗的通道。
LONG);  
        set("exits", ([
        "north" : __DIR__"time3",
        "south" :__DIR__"tunnel",
        "east" : __DIR__"weapon",
        "west" : __DIR__"roadx",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
