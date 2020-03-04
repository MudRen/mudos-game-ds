// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
這是一條不算小也稱不上大的馬路，往東就是聞名遐邇的奧凡迪斯了
。來來往往的車輛經常透過這條馬路對外聯絡，方便的交通也是奧凡迪斯
繁榮的原因之一。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out006",
	    "west" : __DIR__"out004",
	    "north": __DIR__"out002",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}