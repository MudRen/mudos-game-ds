#include <room.h>
#include <ansi.h>
inherit ROOM;
void create() 
{ 
                set("short", HIR"關人房"NOR);
                set("long",HIW"\n\t\t關關的聽話吧\n\n"NOR);

  set("no_quit",1);
  set("light",1);   
  set("valid_startroom", 1); 
set("exits", ([ /* sizeof() == 2 */
  "east" : "/u/p/promise/workroom",
])); 

                setup();
                replace_program(ROOM); 
}



