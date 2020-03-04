// Room: /u/l/lestia/area/sn3.c

inherit ROOM;

void create()
{
 set("short", "北方大森林");
	set("long", @LONG

眼前是一片白楊木森林，森林瀰慢著淡淡的霧氣，添加了幾許神秘氣息
，而空氣飄盪著森林的芳香，奶油色的陽光照耀大地，一陣清爽的微風吹了
過來，你身邊一棵棵濃密的大樹好像忽然醒過來似的，樹葉發出沙沙的聲響
，像是和藹的長者在為你祝福。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sn2",
  "south" : __DIR__"sn4",
  "north" : __DIR__"sn5",
]));
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
