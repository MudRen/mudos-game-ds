// Room: /u/s/sevil/1f/11.c

inherit ROOM;

void create()
{
	set("short", "百貨公司的大門");
	set("long", @LONG
這裡是百貨公司的大門，一踏進這裡，迎面傳來「歡迎光臨」的聲音，;
不禁讓你感到一陣光榮，往裡面走去，豪華的裝潢和明亮的光線，讓你有一
種身在皇宮的感覺，使你不禁懷疑這是否只是一間百貨公司。

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"6.c",
  "west" : __DIR__"12.c",
  "north" : __DIR__"16.c",
  "east" : "/u/s/sevil/workroom.c",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miss-door.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
