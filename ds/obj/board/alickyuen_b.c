#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name(HIR"Release Board "HIY"[Final Version]"NOR, ({ "board" }) );
        set("location","/u/a/alickyuen/workroom.c");
        set("board_id", "alickyuen_b");
        set("long",
        "�o�O�@���γn�찵���d���O �A�Ԥ���Q�n�b�W���d�U�A����ĳ�C\n");
        setup();
	set("capacity", 500);
        replace_program(BULLETIN_BOARD);
}
