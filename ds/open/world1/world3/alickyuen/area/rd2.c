// Room: /u/a/alickyuen/area/rd2.c

inherit ROOM;

void create()
{
	set("short", "ST。Road＠Path");
	set("long", @LONG
來到這條寬闊的道路，發現你剛看到的救護車都停在這�堙A原來西邊
便是SAINT的醫院。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "northeast" : __DIR__"rd3", 可能改通往future的主城
 "west" : __DIR__"dr1",
  "south" : __DIR__"rd1",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
