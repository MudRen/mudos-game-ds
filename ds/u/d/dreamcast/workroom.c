#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", HIC"DREAMCAST'S"HIG"-"HIM"WORKROOM"NOR) ;
   set ("long", "�o�̤@�����O���C\n") ;
        set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"livingroom", 
]));
        set("stroom",1);
        call_other( "/obj/board/dreamcast_b", "???" );



}

