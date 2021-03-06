// Room: /open/world1/tmr/advbonze/hill14.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
你正走在凌雲峰名勝「上天梯」上，你可以看到延著往北而通往
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，看樣子只剩
下不到三十來階的石梯路。由於接近了山頂，你不時可看到一捲白雲
似的薄霧聚了過來。
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill15",
  "southdown" : __DIR__"hill13",
]));

	setup();
	replace_program(ROOM);
}
