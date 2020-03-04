// Room: /u/l/lestia/area/map_5_3.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-廂房");
	set("long", @LONG

這裡是靈幻教專門用來招待貴賓的廂房，裡面的擺設幽雅脫俗，很顯然
這是有專門的人設計的，讓人一走進去就可以感到一股溫暖的感覺，讓所有
來到這裡的貴賓都能感受到賓至如歸的待遇，牆上掛著許許多多出自名家之
手的詩詞文章和畫作。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"map_5_2",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
