#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIW"�٢�ؤ��d���O"NOR, ({ "board" }));
	set("location", "/u/k/ksj/workroom");
	set("board_id", "ksj_b");
        set("long",
        "�o�O�@���γn�찵���d���O �A�Ԥ���Q�n�b�W���d�U�A����ĳ�C\n");
        setup();
        set("capacity",100);
        replace_program(BULLETIN_BOARD);
}
