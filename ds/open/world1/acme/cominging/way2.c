inherit ROOM;

void create()
{
	set("short", "長道");
	set("long", @LONG
一條長長的長道，地上由一塊塊的瓷花盆，種著一株株的花草，有
些花甚至連你都沒有看過，通道可以往北，南，東，西，似乎是個十字
口。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"way4",
  "north" : __DIR__"way3",
  "south" : __DIR__"way1",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
