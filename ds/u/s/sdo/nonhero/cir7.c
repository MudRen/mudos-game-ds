inherit ROOM;

void create()
{
	set("short", "無相法環通道");
	set("long", @LONG
走在長長的通道裡，兩旁的經文完全沒有間斷過，密密麻麻的佈
滿了整片牆壁，不但牆上有，連大理石的地板上，每格一小段距離就
出現了七朵小蓮花為一組的圖案，看起有點像是一種陣法。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"south" : __DIR__"cir12",
  		"north" : __DIR__"cir3",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
