inherit ROOM;

void create()
{
        set("short", "���l���Z��");
        set("long", @LONG
�o�̬O���l����ҥΪ��Z�ҡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/b/basic/rooms/room1",
  "west" : "/u/b/basic/rooms/room3",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
