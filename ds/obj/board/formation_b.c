inherit BULLETIN_BOARD;
void create()
{
        set_name("留言版", ({ "board" }) );
        set("location","/u/f/formation/workroom.c");
        set("board_id", "formation_b");
        set("long",
        "簡簡單單的留言版，用來留言的。\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

