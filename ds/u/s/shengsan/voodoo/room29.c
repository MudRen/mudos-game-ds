
inherit ROOM;

void create()
{
	set("short", "廂房");
	set("long", @LONG
這裡是給客人休息過夜的地方，不過並沒有太多的人在這住過，因為
巫毒教是不太喜歡受到打擾的。這裡的擺設簡單，還蠻算乾淨的，牆上掛
了幾件的字畫。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room21",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
