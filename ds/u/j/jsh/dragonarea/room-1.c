inherit ROOM;

void create()
{
        set("short", "�Z�D��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room-4",
  "east" : __DIR__"room-2",
   ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

