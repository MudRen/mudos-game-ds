#include <armor.h>
inherit WRISTS;
void create()
{
        set_name("�d����M", ({ "sad wind wrists","wrists" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���Q�d�˪���O�]�򪺤�M�C\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1250);          
                set("wear_msg", "$N��$n�a�W, �|�P��M�ܪ��Y���W�B\n");
                set("unequip_msg", "$N�N$n�汼, ��~�@�ɨ��¬��n�C\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

