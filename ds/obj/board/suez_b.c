inherit BULLETIN_BOARD;

void create()
{
        set_name("���O��", ({ "notebook","board" }) );
        set("location", "/u/s/suez/workroom.c");
        set("board_id", "suez_b");
        set("long",
                "�@��²�檺���O���A���F�@�Ƕ�~�~�O���ťժ��A
�n�d����Ĭ�l�_�i�H�g�b�W����I\n" );
        setup();
        set("capacity", 99);
        replace_program(BULLETIN_BOARD);
}
