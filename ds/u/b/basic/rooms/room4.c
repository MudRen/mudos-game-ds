inherit ROOM;

void create()
{
        set("short", "晴子的後院");
        set("long", @LONG
這裡是晴子平日溜狗的地方。
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
