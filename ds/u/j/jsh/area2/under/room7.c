#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
test�C

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"room-7",
  "northwest" : __DIR__"room_7", 
  "north" : __DIR__"room8", 
  "south" : __DIR__"room6",])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

