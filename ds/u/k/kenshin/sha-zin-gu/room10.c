// Room: /u/k/kenshin/sha-zin-gu/room10.c

inherit ROOM;

void create()
{
	set("short", "朝聖之路");
	set("long", @LONG
這條路被暇日谷的居民所定為朝聖之路，每逢佳節或者初一十五
，當地居民都會向前參拜，來表達心中對神明的愛戴與尊敬。除了佳
節會前往，其實最主要的原因是那座寺廟的住持─法璇太師的道行特
別的高，所以在暇日谷居民的心中，他的地位是居次於寧采和之下的
崇高。
LONG
	);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room19",
  "east" : __DIR__"room8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
