// Room: /open/world1/dragoncity/west_din.c

inherit ROOM;

void create()
{
	set("short", "丁字街");
	set("long", @LONG
這裡是磐龍城西城的丁字街口。向西一直通向白虎門，
北面和南面是一條筆直的青石大街，通向城內。東面是一堵
上蓋紅色琉璃瓦的高牆，裡面是少帥軍統帥寇仲的府邸。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"westgate1",
  "south" : __DIR__"westroad2",
  "north" : __DIR__"westroad",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
