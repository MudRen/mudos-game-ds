inherit BULLETIN_BOARD;

void create()
{
        set_name("明教大事板", ({ "Ming board","board" }) );
        set("location", "/open/world1/baal/ming_club/saintming");
        set("board_id", "ming_club_b");
 set("long", "這是一個用來post教中大事的留言板\n" );
        setup();
        set("capacity", 99);
}

