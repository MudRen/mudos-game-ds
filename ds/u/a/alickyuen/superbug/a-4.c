// Room: /u/s/superbug/train/a-4.c

inherit ROOM;

void create()
{
	set("short", "貧民區[北街]");
	set("long", @LONG
這裡是貧民區的北街路口，一踏進這裡你粉難相信在未來的世界裡還
有這樣的地方，黑暗的街道和滿地的垃圾令你感覺彷彿來到了另一個世界
，你急忙的加快腳步希望能趕緊離開這裡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"a-3.c",
]));
set("objects", ([
__DIR__"npc/guard" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
