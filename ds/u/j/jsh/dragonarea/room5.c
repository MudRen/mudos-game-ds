inherit ROOM;

void create()
{
        set("short", "�Y�s��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room7",
  "east" : __DIR__"room6",
  "south" : __DIR__"room4",   ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

