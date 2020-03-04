// Room: /u/t/truewind/Minetown/area/workerroom1.c

inherit ROOM;

void create()
{
	set("short", "工寮中");
	set("long", @LONG
破舊的牆壁，漏風的屋頂，潮濕的空氣。這裡的環境讓你很難想
像這會是各星球的礦工所居住的地方。既來之則安之，你就順著走廊
的方向繼續走下去，希望多了解這個地方的情形。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown5",
  "south" : __DIR__"workerroom2",
]));

	setup();
	replace_program(ROOM);
}
