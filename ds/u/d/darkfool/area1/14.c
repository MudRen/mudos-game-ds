// Room: /u/d/darkfool/area1/14.c

inherit ROOM;

void create()
{
	set("short", "北住宅區街道");
	set("long", @LONG
這裡是鎮北面的住宅區，大片的速成屋整齊地排列著，你仔細的
觀察了一下，發現有幾間房子跟鎮上其他地方的不太一樣，雖然同樣
都是速成屋，但是那些感覺像是較為華麗。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"16",
  "west" : __DIR__"15",
  "south" : __DIR__"12",
]));

	setup();
	replace_program(ROOM);
}
