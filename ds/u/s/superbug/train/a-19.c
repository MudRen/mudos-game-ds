// Room: /u/s/superbug/train/a-19.c

inherit ROOM;

void create()
{
	set("short", "糜爛酒把");
	set("long", @LONG
這裡是一間破舊的酒吧，吧台只有一個老舊的機器人在服務著， 
整間店也只有稀稀疏疏的幾個酒客在喝酒，舞台上有著一群機器樂隊正在
演奏著，也許你可以點幾首歌來聽。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-3.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
