#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",HIG"�j��Q�׫�"NOR);
     set("long",HIW"\n\n\t���j��Ҷ}���Q�׫�\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
"east" : "/u/j/jsh/workroom",
])); 
     setup(); 
     call_other("/obj/board/pwboard_b", "???");
}

