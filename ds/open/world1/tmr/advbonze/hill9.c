// Room: /open/world1/tmr/advbonze/hill9.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
你正走在凌雲峰名勝「上天梯」上，你可以看到延著往北而通往
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，現在才走了
十幾梯而已，看樣子如果要放棄爬上峰頂的話，就只有趁現在往南回
去山腳了。不過，你似乎感覺得到走這座上天梯時，心中一直有股舒
適的感覺。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill10",
  "southdown" : __DIR__"hill8",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
