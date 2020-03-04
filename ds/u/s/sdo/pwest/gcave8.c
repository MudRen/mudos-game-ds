inherit ROOM;

void create()
{
	set("short", "洞窟內通道");
	set("long", @LONG
這裡的地勢又歸於平坦，而且很明顯的前面有較明亮的光源，因
為在這裡可以看見光線照在牆壁上一半亮一半暗的情況。而且地下河
水所造成的水流聲變的有點響，還帶有點回音。看來，前面是一個頗
大的空間。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"gcave9",
  "east" : __DIR__"gcave7",
]));

	setup();
	replace_program(ROOM);
}
