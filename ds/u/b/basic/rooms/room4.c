inherit ROOM;

void create()
{
        set("short", "���l����|");
        set("long", @LONG
�o�̬O���l����Ȫ����a��C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" :"/u/b/basic/rooms/room3",
  
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
