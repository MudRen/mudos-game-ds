// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯正城門外");
	set("long", @LONG
這是條奧凡迪斯連接外界的道路之一，車輛的來來去去相當的繁忙，
北邊就是奧凡迪斯的正城門了。進去(enter)奧凡迪斯之後請務必不要打
擾奧凡迪斯的正常生活。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out019",
	    "south": __DIR__"out028",
	    "enter": __DIR__"room009",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
