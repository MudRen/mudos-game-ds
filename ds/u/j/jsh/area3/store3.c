inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG
test

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"store1",
  "west" : __DIR__"store5",   
])); 
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


