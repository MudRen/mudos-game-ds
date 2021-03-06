// Room: /u/a/acme/area/st.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你正走在一條寬廣的街道，約可容兩輛馬車並駕而行。這裡人聲鼎沸
，車水馬龍，熱鬧非凡。往東可往廣場，南邊可看到一間客棧，門口掛著
一張紅木金字招牌，上頭寫著「天香客棧」。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street2",
  "south" : __DIR__"hotel.c",
  "east" : __DIR__"plaza",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
