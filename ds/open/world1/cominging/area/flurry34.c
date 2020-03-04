inherit ROOM;
void create()
{
	set("short", "練武場入口");
	set("long", @LONG
這裡是練武場的入口，練武場主要是給疾風門的弟子練武功所需，
當然也可以供給外來旅客使用，當有重大決鬥時，都會到這裡來舉行，
地上有著一片片的樹葉。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flurry39.c",
  "west" : __DIR__"flurry33.c",
  "east" : __DIR__"flurry35.c",
  "southup" : __DIR__"flurry32.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("mob_amount", 2);
	set("mob_object",({
  __DIR__"npc/apprentice",
}));
	set("outdoors","land");
	setup();
}
