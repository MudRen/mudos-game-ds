#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIG"�j�F�Q�׫�"NOR);
set("long",HIW"\n\n\t���j�F�Ҷ}���Q�׫�\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
"west":"/u/j/jsh/workroom",
])); 
     setup(); 
call_other("/obj/board/peboard_b","???");
}

