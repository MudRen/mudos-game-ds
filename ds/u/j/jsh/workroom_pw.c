#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",HIG"古西討論室"NOR);
     set("long",HIW"\n\n\t為古西所開的討論室\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
"east" : "/u/j/jsh/workroom",
])); 
     setup(); 
     call_other("/obj/board/pwboard_b", "???");
}

