inherit ROOM;
void create()
{
          set("short","住宅區小路");
          set("long",@LONG
這裡是穿過住宅區的一條小路，亦都是通往住宅區的唯一的通道。這
裡的住宅設計未見突出，可能只是用來給礦工們住的吧，雖然如此，但是
看來生活設施都一一俱備。
LONG
          );
               set("world", "future");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"digging_street2",
  "east" : __DIR__"digging_street4",
]));

	setup();
	replace_program(ROOM);
}
