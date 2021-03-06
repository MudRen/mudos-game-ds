// Room: /tmr/garea/forest14.c

inherit ROOM;

void create()
{
	set("short", "綠沼小路");
	set("long", @LONG
你正走在一條泥濘小路，不時傳來惡臭難聞的沼氣，抵抗力稍低的人
，只怕早已昏迷身亡。往南不遠處可看到一處深綠色的沼澤。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest12",
	  "northeast" : __DIR__"forest16",
	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
