
inherit BULLETIN_BOARD;

void create()
{
    set_name("�����d����", ({ "tmr board", "board" }) );
        set("location", "/u/t/tmr/room/square");
        set("board_id", "tmr_b");
        set("long","�@�i�}�ª��j��O�A�p�A�Q�b�W���d���A�ˤ]�j�j�i��C\n" );        setup();
        set("capacity", 50);
}
string query_save_file()
{
	return "/u/t/tmr/"+query("board_id");
}
