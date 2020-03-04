
inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
這個前廳的裝潢很有復古的味道，你所看到的家具都是用上等的木材
加上精湛的刻工所做成的，桌椅都排放得整齊，地上更有大紅色的地毯鋪
著。你看到前方有個檔牆，牆上掛了許多名家的字畫。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room23",
	    "west" : __DIR__"room27",
	    "south": __DIR__"room10",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
