inherit ROOM;

void create()
{
        set("short", "�Y�s��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room5",
  "northwest" : __DIR__"room25",
  "northeast" : __DIR__"room8",]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

