#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(MAG"�T����"NOR ,({ "bone helmet","helmet" }) );
        set("long", "�o�O�B�������T���ҥ[�u�Ӧ�������, �ݰ_�ӯ�����Ѥ��������m�O.\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
		set("material", "rubber");
		set("limit_str",12);
                set("armor_prop/armor",  11);
                set("armor_prop/shield", 1);
                set("value", 4000);
        }
        setup();
}
