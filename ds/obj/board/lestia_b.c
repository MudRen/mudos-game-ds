// lestia_b.c
inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name(HIR"��"NOR""RED"��"HIR"��"NOR""RED"�y"NOR, ({ "lestia board","board" }) );
        set("location", "/u/l/lestia/workroom.c");
        set("board_id", "lestia_b");
        set("long",     "�o�O�@�ӵ��n�d��Lestia���H�Ϊ��C\n" );
        setup();
        set("capacity", 50);

}

