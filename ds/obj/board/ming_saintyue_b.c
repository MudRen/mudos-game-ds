inherit BULLETIN_BOARD;

void create()
{
        set_name("明教聖語錄", ({ "Saintyue board","board" }) );
        set("location", "/open/world1/baal/ming_club/gw");
        set("board_id", "ming_saintyue_b");
        set("long",
                "這是一個用來發問的留言板，當你有各種問題時請post，大家會幫你解決。\n" );
        setup();
        set("capacity", 99);
}

