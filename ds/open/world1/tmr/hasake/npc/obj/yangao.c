// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�ϥ���", ({ "sheep cloth", "cloth"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��Ǧ⪺�ϥ��͡C���ϤH���ެK�L��V, �h���U�B����ۥ��C\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 120);
        }
        setup();
}

