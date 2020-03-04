// Room: /u/a/acme/area/pass10.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你正走在一條筆直的山路上，路上舖了石板階梯，讓人覺得如履平地
，絲毫不覺得是在爬山，拾級而上，可望見天城的城門，向南望去有個小
黃沙丘。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"pass9",
  "southwest" : __DIR__"pathway8",
  "northwest" : __DIR__"farm1",
]));
   set("no_map",1);
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
