inherit ROOM;

void create()
{
        set("short", "�n�j��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"room1", 
  "south" : __DIR__"room3",
]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

