inherit ROOM;

void create()
{
        set("short", "���s���j�Q�r�n��");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room_18", 
  "north" : __DIR__"room_6",  ]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

