inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
這裡的空間大的令人驚訝！平坦無障礙物的地面、上頭大約離地
兩人高，簡直可以媲美一個小型的集會所。不知道這一個巨大的地下
孔穴是怎麼造成的。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"gcave11",
  "southeast" : __DIR__"gcave12",
  "south" : __DIR__"gcave10",
  "northeast" : __DIR__"gcave8",
]));

	setup();
	replace_program(ROOM);
}
