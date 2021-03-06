// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "迷人的山麓");
	set("long", @LONG
這裡是迷人的山麓，這裡的高度剛好可以看到西方「依莉莎湖」的半
面景色，也可以看到北面樹林的樹海。幾棵植物生長在這，使得這山麓也
有綠色的陪襯，無盡天空中的白雲留給你一些想像的空間。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out061",
	    "north": __DIR__"out056",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}