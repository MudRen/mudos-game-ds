inherit ROOM;

void create()
{
        set("short", "�Z�D��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room-9", 
  "north" : __DIR__"room-5",
  "west" : __DIR__"room-7",   ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

