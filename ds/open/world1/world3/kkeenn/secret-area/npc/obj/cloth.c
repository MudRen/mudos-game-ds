#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�Ŧt����", ({ "air cloth","cloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@��Ѥ��a��w���зǤp���m�C\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1200);          
                set("wear_msg", "$N�H���@��$n�ܦb���W\n");
                set("unequip_msg", "$N���y�H�I, ��$n��U���ΰ��C\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",8);
        setup();
}

