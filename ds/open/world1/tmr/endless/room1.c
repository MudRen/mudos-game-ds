// Room: /open/world1/tmr/endless/room1.c

inherit ROOM;

void create()
{
        set("short", "�L�����~");
        set("long", @LONG

                
                �L�����~�A�_�L���]
                
                
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"enter",
]));
        set("current_light", 1);
        set("objects",([
        __DIR__"npc/master":1,
        ]) );

        setup();
        replace_program(ROOM);
}

