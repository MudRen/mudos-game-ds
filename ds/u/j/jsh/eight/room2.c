#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "�K�j�{");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room1",   
  "southeast" : __DIR__"room4",
  "southwest" : __DIR__"room3",]));
        set("no_clean_up", 0);

        setup();
}


