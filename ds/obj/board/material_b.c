// equip_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("材質討論板", ({ "board" }) );
	set("location", "/d/wiz/hall_material");
	set("board_id", "material_b");
	set("long",
		"這是一個巫師們討論材質的留言板。\n" );
	setup();
	set("capacity", 90);

}
