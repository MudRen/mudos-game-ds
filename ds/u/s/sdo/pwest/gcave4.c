inherit ROOM;

void create()
{
	set("short", "洞窟內叉路");
	set("long", @LONG
這裡相較於洞口似乎寬闊了點，不過大概是因為走到較裡面的地
方了，所以感覺溼氣開始便重，空氣中那股濃濁的味道也變的越來越
明顯。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"northeast" : __DIR__"gcave6",
  		"south" : __DIR__"gcave2",
	]));

	setup();
	replace_program(ROOM);
}
