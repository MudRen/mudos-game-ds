inherit ROOM;

void create()
{
        set("short", "���s���j�Q�r�F�u");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room_11",
  "west" : __DIR__"room_9",
])); 
set("light",1); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/knight3" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

