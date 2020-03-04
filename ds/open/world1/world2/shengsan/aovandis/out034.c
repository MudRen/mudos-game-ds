// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "商業道路");
	set("long", @LONG
這是條相當大的馬路，沿著北邊行走就可以到達奧凡迪斯了。來往的
車輛在你身旁呼嘯而過，使得你有些驚心膽跳的感覺。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out035",
	    "west" : __DIR__"out033",
	    "north": __DIR__"out026",
            ]));
	set("light",1);
	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}