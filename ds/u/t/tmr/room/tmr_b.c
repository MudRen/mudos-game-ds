
inherit BULLETIN_BOARD;

void create()
{
    set_name("有面留言版", ({ "tmr board", "board" }) );
        set("location", "/u/t/tmr/room/square");
        set("board_id", "tmr_b");
        set("long","一張破舊的大木板，如你想在上面留言，倒也勉強可行。\n" );        setup();
        set("capacity", 50);
}
string query_save_file()
{
	return "/u/t/tmr/"+query("board_id");
}
