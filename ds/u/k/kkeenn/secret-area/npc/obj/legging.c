#include <armor.h>
inherit LEGGING;
void create()
{
        set_name("�ݬP�@�L", ({ "break star legging","legging" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�ǻ����O�H�ȤO�w�P�y�������ݦX�����@�L�C\n");
                set("unit", "��");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1400);          
                set("wear_msg", "$N��$n�˨�L�W�h��, ���G�ܭD�F�@��??\n");
           }
        set("armor_prop/dodge",-2);
        set("armor_prop/armor",10);
        setup();
}

