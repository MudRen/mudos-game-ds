inherit BULLETIN_BOARD;
void create()
{
        set_name("�d����", ({ "board" }) );
        set("location","/u/f/formation/workroom.c");
        set("board_id", "formation_b");
        set("long",
        "²²��檺�d�����A�Ψӯd�����C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}

