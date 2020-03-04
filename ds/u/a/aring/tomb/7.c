// Room: /u/a/aring/tomb/7.c

inherit ROOM;

void create()
{
	set("short", "大墓園－小樹林");
	set("long", @LONG
這裡是墓園裡的小樹林，樹林中瀰漫著濃濃的霧氣，樹枝上只有
烏鴉棲息，感覺起來死氣沉沉地。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"9.c",
  "northwest" : __DIR__"5.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
