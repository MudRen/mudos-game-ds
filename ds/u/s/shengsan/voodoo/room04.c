inherit ROOM;

void create()
{
	set("short", "竹林步道");
	set("long", @LONG
除了竹葉聲之外，你還聽到斯斯的聲音，好像是林中有蛇像你逼近了
，你不由自主的提高警覺心，以應付隨時突來的狀況。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "east" : __DIR__"room03",
            "west" : __DIR__"room05",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
