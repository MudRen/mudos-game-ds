// equip_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("裝備留言板", ({ "board" }) );
	set("location", "/d/wiz/hall_equip");
	set("board_id", "equip_b");
	set("long",
		"這是一個巫師們討論裝備的留言板。\n" );
	setup();
	set("capacity", 90);

}
