#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("�����s���G�i��",({"board"}));
        set("location","/u/s/shrick/rooms/center.c");
        set("board_id", "center_b");
        set("long",
        "�o�O�Sù�������s���W�ҩ�m���G�i��A
         ����̶K�W�ۤv�ǩ_���I���G�Ƶ����Ӫ�
         �P��L����̤@�P���ɡC\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
