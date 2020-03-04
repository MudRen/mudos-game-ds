// Room: /open/world1/tmr/north_bar/town27.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－武器店");
	set("long", @LONG
來到這裡，你發現牆上掛著許多武器，刀、槍、劍等等都有
，旁邊的打鐵爐正閃著熾熱的火焰，有兩個學徒正在那裡敲著塊
燒熱的生鐵，叮叮咚咚的十分吵囃。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"town26",
]));
	set("current_light", 1);
        
        set("objects", ([
                "/open/world1/wilfred/newbie/eq_master.c" : 1,
        ]) );
        


	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
