#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIG"Naboo���d���O"NOR,({"board"}));
        set("location","/open/world3/mulder/area/naboo/middle.c");
        set("board_id", "naboo_b");
        set("long",
        "�o�O�@���Ϊ��ݰ����d���O �A�i�H�b�W���d�U�A����ĳ�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}