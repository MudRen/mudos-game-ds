// Room: /open/world1/tmr/advbonze/hill8.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯路口");
	set("long", @LONG
你正站在凌雲峰名勝「上天梯」梯口，你可以看到延著往北而通
往山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，赫然發現
石梯約有數百梯，蜿蜒而順著峰頂高聳入雲，看樣子腳力較虛的人，
是無法爬上峰頂的。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill9",
  "south" : __DIR__"hill7",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
