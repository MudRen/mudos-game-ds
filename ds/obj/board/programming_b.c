#include <ansi2.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIR"�{���Q�ת� "HIY"[Java 2 Version]"NOR, ({ "board" }) );
	set("location", "/u/a/alickyuen/programming.c");
	set("board_id", "c++_b");
	set("long",
		"�o���O�{�ɳ̥��i���q�l��ܪ��A�O���F�ܦh�����{���g�@����ơC\n");
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
