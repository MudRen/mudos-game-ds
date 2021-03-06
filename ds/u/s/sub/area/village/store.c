// Room: /u/s/sub/area/village/store.c

inherit ROOM;

void create()
{
	set("short", "雜貨店");
	set("long", @LONG
這裡的擺設雜亂，各式各樣的貨物隨意堆置。有的物品上片還蒙上一
層薄薄的灰，看來這裡貨品的流通率相當的低，應該是因為這裡較少跟外
界接觸的關係。不過這裡的老闆可是相當的講信用的，絲毫沒有因為生意
不好而有任何的改變。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi06",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_shoper_20" : 1,
]));
	set("room_type", "shop");
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
