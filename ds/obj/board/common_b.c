// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("一般用途留言板", ({ "board" }) );
	set("location", "/d/snow/inn");
	set("board_id", "common_b");
	set("long",	"這是一個供人留言記事的留言板。\n" );
	setup();
	set("capacity", 50);

}
