// room_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("房間討論板", ({ "board" }) );
	set("location", "/d/wiz/hall_room");
	set("board_id", "room_b");
	set("long",
		"這是一個巫師們討論房間寫法的留言板。\n" );
	setup();
	set("capacity", 90);

}
