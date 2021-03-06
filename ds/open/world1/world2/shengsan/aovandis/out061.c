// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "山麓");
	set("long", @LONG
山勢明顯地由西往南升高許多，還是有許多植物在這邊生長，有許多
的碎石及大石頭散佈的不太均勻，其間還有一些枯木在上面。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out062",
	    "west" : __DIR__"out060",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}