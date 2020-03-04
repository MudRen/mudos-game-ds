// Room: /u/a/acme/area/h.c

inherit ROOM;

void create()
{
	set("short", "破敗的小屋");
     set("light",1);
	set("long", @LONG
這裡是一個想當破舊的屋子，已生了蜘蛛網，地上積滿厚厚的灰塵
還有張被蛀蟲蝕了坑坑洞洞的木椅，似乎輕輕碰就垮了，眼前有一位老
道正愁眉不展的坐在長凳上。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"pathway6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/taoist" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
