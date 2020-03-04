inherit ROOM;

void create()
{
	set("short", "六道外");
	set("long", @LONG
你抬頭看見你的上頭有塊較凸出的石塊，上面寫著：『六道外，
紅塵中。』而在靠近牆邊的地方，有一張石桌，石桌上有著一隻十字
金剛杵，其中有約一半卡在石桌當中，看來要拔出來是不可能的了。
不過好像常常有人握過，因為把柄的部分亮晶晶的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"cir11",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
