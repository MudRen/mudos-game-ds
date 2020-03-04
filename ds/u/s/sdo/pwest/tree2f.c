inherit ROOM;

void create()
{
	set("short", "中空的樹幹內");
	set("long", @LONG
站在這裡，你感覺到了一股神聖而莊嚴的氣氛在這附近環繞著，
這股感覺就是你在森林內部感覺到的那股神秘力量，但是這裡強多了
，看來力量的源頭就在這棵神木裡。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"tree3f",
  		"down" : __DIR__"tree1f",
	]));

	setup();
	replace_program(ROOM);
}
