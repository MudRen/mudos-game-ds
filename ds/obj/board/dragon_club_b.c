// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("狂龍幫專用留言版", ({ "board" }) );
	set("location", "/open/world1/cominging/area/dragon/dragon");
	set("board_id", "dragon_club_b");
	set("long",
		"這是一個供幫眾們留言或是交換意見用的留言板。\n" );
	setup();
	set("capacity", 99);
}
