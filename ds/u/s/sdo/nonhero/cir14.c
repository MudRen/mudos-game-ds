inherit ROOM;

void create()
{
	set("short", "破輪迴");
	set("long", @LONG
一走進這裡，就看到了右手邊有一根石柱，上面刻著幾個大字：
『觀自在悟破輪迴  聽如意超脫俗外』。走到柱子後面，看見了一個
蓮花座，剛剛好可以容納一個人盤腿坐上去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"cir13",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
