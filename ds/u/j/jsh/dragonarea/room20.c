inherit ROOM;

void create()
{
        set("short", "�Y�s��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1",
  "west" : __DIR__"room21", ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

