#include <ansi.h>
inherit ITEM;

#define BOSS "/open/world1/tmr/crush_bone/npc/nightbane.c"


void create()
{
    set_name(HIY"�H���ҦL"NOR, ({"emperor stamp", "stamp","_EMPEROR_STAMP_"}));
    if( !clonep() ) {
        set("long", @LONG
�o�O�@�����~���覨���ҦL�A�W�Y�Τ����W���r��g�ۨ�r�A
�A�q�����ӬO�u�H���v�������r���C
LONG
                );
        set("value", 100);
        set("unit", "��");
        set("weight", 10);
        set("value",10);
        } else
                   set_default_object(__FILE__);
    setup();
}

