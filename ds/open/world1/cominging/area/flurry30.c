inherit ROOM;

void create()
{
	set("short", "走廊之間");
	set("long", @LONG
這裡是走廊之間，在你左右都各有房間，不過燈光卻很陰暗的樣子
，並不容易從外面看到裡面發生了什麼的情形，在從前在這附近就發生
過被人偷竊過的事，可是後來又加強了防衛，所以近來的事件就漸漸減
少了，這兒的空氣清新，大概是因為走道旁的小花草吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry29.c",
  "east" : __DIR__"flurry31.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
