inherit BULLETIN_BOARD;

void create()
{
        set_name("陰陽聖火追殺令", ({ "board" }) );
        set("location", "/open/world1/baal/ming_club/darkfire");
        set("board_id", "ming_inyang_b");
        set("long",
                "o是一個用來通緝別人的留言板，當你要通緝他人時，請post名單和罪行長老將會表決是否通緝。\n" );
        setup();
        set("capacity", 99);
}

