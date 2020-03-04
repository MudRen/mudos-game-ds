#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "惡靈沙漠") ;
   set ("long", "這裡就是惡靈沙漠，也就是相傳天妖被封於此處..\n") ;
   set ("exits", ([
                    "east":__DIR__"infinite3.c",
                    "north":__DIR__"infinite2.c",
                    "south":__DIR__"infinite2.c",
                    "west":__DIR__"infinite3.c",
   ])  ) ;
       
        set("outdoors","desert");
        set("no_clean_up", 0);
        set("light", -1); 

        setup();
        replace_program(ROOM);
}

