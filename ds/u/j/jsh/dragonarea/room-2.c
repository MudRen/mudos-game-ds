inherit ROOM;

void create()
{
        set("short", "�Z�D��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room-5",
  "east" : __DIR__"room-3",
  "west" : __DIR__"room-1", ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

