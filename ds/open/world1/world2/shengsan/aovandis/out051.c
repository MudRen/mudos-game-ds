// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
許多的高大的樹木在你的四周爭著往上生長，你看到細細長長的光線
從繁茂的樹葉間射下來。地上都被巨大的樹根以錯綜複雜的姿態所盤據，
使得你都沒有立足之地。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out052",
	    "north": __DIR__"out043",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}