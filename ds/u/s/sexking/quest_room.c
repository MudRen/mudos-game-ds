#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"�g�D�m�߫�"NOR);
        set("long", @LONG
�o�D�@��sexking�m�߼gquest���ж�..
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"workroom3",
        ]));
        set("objects",([
       __DIR__"child" : 1,
       ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1); 
        setup();
}
