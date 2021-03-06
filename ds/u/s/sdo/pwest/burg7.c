inherit ROOM;

void create()
{
	set("short", "迷霧森林之徑");
	set("long", @LONG
從這裡開始就是迷霧森林的範圍了。相較於各種危險的結界，迷
霧森林是最溫和的結界，因為進入迷霧森林的人都能夠平安的出來，
只是目前為止沒有聽說什麼人穿越過森林，到達另一邊。不過根據幽
遮蘭城的紀錄，另一邊應該就是『妖精國度』，因為他們曾經和由妖
精國度派出來的代表簽訂過雙方互不干擾的約定。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"burg8",
  		"west" : __DIR__"burg6",
	]));

	setup();
	replace_program(ROOM);
}
