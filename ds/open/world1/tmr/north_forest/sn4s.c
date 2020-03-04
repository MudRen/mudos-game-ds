// Room: /u/l/lestia/area/sn4.c

inherit ROOM;

void create()
{
 set("short", "北方大森林-地底洞穴入口");
	set("long", @LONG
你走在一片長楊木樹的林子裡，抬頭看見的是濃密的枝葉，低頭看到的
是地氈一般厚厚的落葉。你注意到前面有一個地底洞穴。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sn4",
  "enter" : __DIR__"cave1",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
