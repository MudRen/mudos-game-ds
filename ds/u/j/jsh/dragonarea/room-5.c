inherit ROOM;

void create()
{
        set("short", "�Z�D��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room-2",
  "west" : __DIR__"room-4",
  "east" : __DIR__"room-6",
  "south" : __DIR__"room-8",   ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

