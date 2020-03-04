// Room: /u/a/alickyuen/area/dr11.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Liftdoor");
	set("long", @LONG
這裡是二樓的北邊出口，是傳送機的入口，這部機能來往所有的層數
和主要的地方，使到所有的病人，都在最快的時間得到治療，令到這間醫
院的死亡率是所有醫院之中最低的一間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr13",
  "enter" : __DIR__"dr9",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
