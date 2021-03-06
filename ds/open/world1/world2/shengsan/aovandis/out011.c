// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯城牆外");
	set("long", @LONG
你正站在高聳的城牆外，堅實的城牆已經在這保衛奧凡迪斯的子民數
千年了，雖然有戰火的痕跡，但是卻不減其威風。往遠處看可以看到幾棵
快要乾枯的樹木，往北就是一條平坦道路了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out012",
	    "south": __DIR__"out015",
	    "north": __DIR__"out008",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}