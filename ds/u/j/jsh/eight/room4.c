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
  "northwest" : __DIR__"room2",   
  "southeast" : __DIR__"room6",]));
        set("no_clean_up", 0);

        setup();
}


