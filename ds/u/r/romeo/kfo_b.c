inherit BULLETIN_BOARD;
void create()
{
        set_name("２０００年", ({ "board" }) );
        set("location", "/u/k/kfo/workroom");
        set("board_id", "kfo_b");
        set("long",
                "這是一個供人留言記事的留言板。\n" );
        setup();
        set("capacity", 99);
}

