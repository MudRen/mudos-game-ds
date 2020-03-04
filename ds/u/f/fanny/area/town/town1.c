// Room: /u/f/fanny/area/town/town1.c

inherit ROOM;

void create()
{
	set("short", "進村小路");
	set("long", @LONG
經過長途跋涉終於橫過【不歸草原】，映入眼廉的，是一幅出奇
祥和的畫面，放眼望去土地平曠，居舍儼然，雖沒有大城的繁華，卻
也不失為這殺戮江湖的另一片樂土。
LONG
	);
	set("world", "undefine");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
