// Room: /u/s/slency/area/ugelan/wood2.c

inherit ROOM;

void create()
{
	set("short", "森林小徑");
	set("long", @LONG
這裡是密比斯森林的一條小徑，小路旁長滿了雜草，看起來很
久都沒人來過的樣子，此處的樹木高大濃密，愈往裡面走似乎愈來
愈陰暗，除了昆蟲偶爾吱吱地叫著，整座森林幾乎是萬籟俱靜, 你
不得不提起精神，專心注意身旁的變化，整座森林處在一片寧靜神
秘的氣氛中。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"secretwood1",
  "south" : __DIR__"wood3",
  "east" : __DIR__"wood1",
  "northwest" : __DIR__"wood8",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
