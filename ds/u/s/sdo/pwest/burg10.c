inherit ROOM;

void create()
{
	set("short", "村外山路");
	set("long", @LONG
你正站在一條山路上，往東邊看去，只見一片樹海，樹海的上頭
還籠罩著濃霧，看來就算是龍騎士，想飛越迷霧森林也是不太可能的
。北邊的山坡上有一塊台地。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"northup" : __DIR__"hill1",
  		"southeast" : __DIR__"burg5",
	]));

	setup();
	replace_program(ROOM);
}
