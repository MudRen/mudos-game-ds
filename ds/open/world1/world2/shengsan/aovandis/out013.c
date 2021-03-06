// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
一些雜草及一些碎石是這裡地上的主要景物，一片荒蕪的平地在這邊
已經很久很久了。偶而會有幾架民航機從空中的雲端裡飛過，或是到了傍
晚十分會有幾隻飛鳥在空中飛翔。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out014",
	    "south": __DIR__"out016",
	    "north": __DIR__"out010",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}