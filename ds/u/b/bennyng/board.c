inherit BULLETIN_BOARD;
void create()
{
        set_name("�����y���O",({"board"}));
        set("location","/u/b/bennyng/workroom.c");
        set("board_id", "bennyng_b");
        set("long",
        "�o�O�����y���O �A�Ԥ���Q�n�b�W���d�U�A���_�Q��ĳ�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
