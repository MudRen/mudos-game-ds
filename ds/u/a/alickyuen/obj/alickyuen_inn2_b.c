#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("�q�l�d���O",({"board"}));
        set("location","/open/world3/alickyuen/area/inn2.c");
        set("board_id", "alickyuen_inn2_b");
        set("long",
        "�o�O�@���q�l�d���O �A�Ԥ���Q�n�b�W���d�U�A����ĳ�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}