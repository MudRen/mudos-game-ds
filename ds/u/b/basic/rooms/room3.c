inherit ROOM;

void create()
{
        set("short", "晴子的寢室");
        set("long", @LONG
這裡是晴子平日小歇一會的地方。
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
