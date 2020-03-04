inherit MOBROOM;
void create()
{
	set("short", "練武場");
	set("long", @LONG
這裡是疾風門的練武場，這的幅員廣大，一眼望去，盡是練武場，
練武場上有許多的疾風門弟子在練武或者練內功，抑或在研究招式，其
中也包含了他派弟子來請教，有不乏武功高強之士，練武場旁邊都有一
個擺著劍的架子，上面放著許多斷掉或壞掉的劍類武器。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flurry45.c",
  "west" : __DIR__"flurry39.c",
  "south" : __DIR__"flurry35.c",
  "eastup" : __DIR__"flurry41.c",
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
