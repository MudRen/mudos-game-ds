// bandage.c

#include <ansi.h>
inherit ITEM;
inherit F_EQUIP;
void create()
{
        set_name( "��h", ({ "piece"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", "�o�O�@�賷�ժ���h�C\n");               
        }
}
