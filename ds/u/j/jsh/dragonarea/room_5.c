inherit ROOM;

void create()
{
        set("short", "���s���j�Q�r���u");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room_4",  
  "east" : __DIR__"room_6",]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

