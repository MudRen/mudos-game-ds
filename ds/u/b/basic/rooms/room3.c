inherit ROOM;

void create()
{
        set("short", "���l�����");
        set("long", @LONG
�o�̬O���l����p���@�|���a��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "nouth" :"/u/b/basic/rooms/room4",
  "east" : "/u/b/basic/rooms/room2",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
