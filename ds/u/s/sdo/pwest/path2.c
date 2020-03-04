inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
從這裡開始就是一大片的森林了，而西邊是一大片草原。這裡的
樹木長的十分茂密，而且非常高大，看起來也非常蒼老的樣子。在這
個幾經戰亂的日昇大陸上，還真是不容易看見。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"northeast" : __DIR__"path3",
  		"west" : __DIR__"path1",
	]));

	setup();
	replace_program(ROOM);
}
