#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", HIC"DREAMCAST'S"HIG"-"HIM"WORKROOM"NOR) ;
   set ("long", "這裡一切都是謎。\n") ;
        set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"livingroom", 
]));
        set("stroom",1);
        call_other( "/obj/board/dreamcast_b", "???" );



}

