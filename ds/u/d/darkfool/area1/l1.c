// Room: /u/d/darkfool/area1/l1.c

inherit ROOM;

void create()
{
	set("short", "街道-往圖書館");
	set("long", @LONG
這條街道通往鎮上的圖書館，也就是你往南直直望過去看到的那
幢有點灰白的建築物，而其並非速成屋，而是以一種類似大理石的材
質建成，它應該和鎮門口的石柱一樣是屬於古鎮的一部份。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"32",
  "south" : __DIR__"l2",
]));

	setup();
	replace_program(ROOM);
}
