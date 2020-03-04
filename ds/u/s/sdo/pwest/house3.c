inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
你正在一間普通的民房裡，眼前的樸素擺設讓你相信此間的主人
只是一個平凡的村民，看著牆腳的耕田工具和斧頭，看來這裡的主人
工作相當勤奮。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/random.c":1,
	]));

	setup();
	replace_program(ROOM);
}
