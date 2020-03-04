inherit ROOM;

void create()
{
	set("short", "洞窟內通道");
	set("long", @LONG
你站在這裡，發現地勢開始向下傾斜，但是相對的空間也就越來
越寬廣，而且依稀可以聽到水流聲，看來這附近有地下河流經過，而
越往前走水流聲越來越大。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gcave6",
  "west" : __DIR__"gcave8",
]));

	setup();
	replace_program(ROOM);
}
