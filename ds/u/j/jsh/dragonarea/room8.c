inherit ROOM;

void create()
{
        set("short", "�Y�s��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room9",
  "southwest" : __DIR__"room7",
]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

