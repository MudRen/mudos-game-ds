// Room: /u/l/lestia/area/sn7.c

inherit ROOM;

void create()
{
	set("short", "北方大森林");
	set("long", @LONG
你觸目所及的，只有一棵棵高聳的綠樹，綠樹的葉子長的非常茂盛，使
得陽光無法照進來，也使得森林裡的氣氛有點陰冷。綠樹上，長滿了青苔，
看起來有點噁心，不僅如此，地面上的石頭也都是青苔，所以你每一步都要
小心的走，才不會沾上那些噁心的青苔。而森林中的空氣充滿了一股異味，
為了不要聞那種噁心的味道，你不由得把呼吸放小了。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/wolf":2,
	__DIR__"npc/troll2":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sn8w",
  "north" : __DIR__"sn6w",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
