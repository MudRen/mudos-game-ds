// skill_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("區域留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_area");
	set("board_id", "area_b");
	set("long",
		"這是一個巫師們討論區域的留言板。\n" );
	setup();
	set("capacity", 90);

}
