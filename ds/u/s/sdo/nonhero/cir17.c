inherit ROOM;

void create()
{
	set("short", "無相法環通道");
	set("long", @LONG
看著牆上多又密的經文，你的心裡開始感覺到一些不太對勁，刻
那麼多的經文究竟是為了什麼？避邪？鎮魔？還是在保護些什麼東西
？你懷著一絲絲不安的心情繼續往前走。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"south" : __DIR__"cir21",
  		"north" : __DIR__"cir12",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
