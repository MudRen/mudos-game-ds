// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡是奧凡迪斯的郊區，幾株的小樹在這邊生長，在小樹的旁邊還有
一些草本科的植物，還有一些小花也在這邊生長著。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out028",
	    "south": __DIR__"out036",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}