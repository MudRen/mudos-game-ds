// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區農田");
	set("long", @LONG
有一排防風林設在這邊，在防風林的對面你可以看到一片一片的農田
在大地之上，清風微微的吹著稻子，就彷彿是海上的浪一般上下擺動著，
這裡是奧凡迪斯的郊區。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out025",
	    "west" : __DIR__"out023",
	    "south": __DIR__"out031",
	    "north": __DIR__"out016",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}