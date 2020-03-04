inherit ROOM;

void create()
{
	set("short", "西走廊");
	set("long", @LONG
這裡是疾風門的側走郎，在這裡有許多的衛兵來回走動，在南方有
間房間，裡面並沒有燈火光明，似乎沒有人住的樣子，東邊是走廊，西
邊就是入口了。
LONG
	);
	set("light",1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry3.c",
  "east" : __DIR__"flurry5.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
