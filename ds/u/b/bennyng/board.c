inherit BULLETIN_BOARD;
void create()
{
        set_name("黑瞳流言板",({"board"}));
        set("location","/u/b/bennyng/workroom.c");
        set("board_id", "bennyng_b");
        set("long",
        "這是黑瞳流言板 你忍不住想要在上面留下你的寶貴建議。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
