#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "�K�j�{");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"room4",   
  "northeast" : __DIR__"room8",]));
        set("no_clean_up", 0);

        setup();
}


