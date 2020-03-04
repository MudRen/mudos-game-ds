// Room: /u/s/slency/area/ugelan/road8.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這裡是一條人潮來往熙攘的街道，你看到身旁有一個大招牌，上面
寫著【幽遮蘭銀行】，看來是一間供旅行者提錢或存款的銀行，這條街
道上有不少的流浪動物，你看了不禁有些心疼，同情心使你不忍再看到
這些可憐的動物。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road9",
  "north" : __DIR__"bank",
  "east" : __DIR__"road1",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
