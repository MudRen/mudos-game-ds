#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
test�C

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"room-10",
  "northwest" : __DIR__"room_10", 
  "south" : __DIR__"room9",])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

