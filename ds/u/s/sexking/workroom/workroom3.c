#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"��g�j�U�U"NOR);
        set("long", @LONG
�o�D�@�Ӥj�U....�ܴ��q��....
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"workroom4",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
call_other( "/obj/board/sexking_b.c", "???" );
}

