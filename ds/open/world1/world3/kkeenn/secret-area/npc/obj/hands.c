#include <armor.h>
inherit HANDS;
void create()
{
        set_name("�j�a���x", ({ "earth hands","hands" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���ǻ��Q�j�a����O�]�򪺤�x�C\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1400);          
                set("wear_msg", "$N�n���Q$n���֤F, �O�q�ɼW?!\n");
                set("unequip_msg", "$N��$n�汼, ���¬O�����������C\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

