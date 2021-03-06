// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊樹林");
	set("long", @LONG
幾棵高大的樹木在這邊生長，還有幾棵小樹伴隨在大樹的旁邊。因為
南邊有一座湖泊，使得這裡的土地有點鬆軟。有時會有毒蛇和虎頭蜂在這
出沒，有許多遊客曾經在這受到虎頭蜂的攻擊，所以還是小心的好。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out050",
	    "west" : __DIR__"out048",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}