inherit ROOM;

void create()
{
        set("short", "神龍的大十字東臂");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room_10", 
]));
set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

