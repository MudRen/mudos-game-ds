#include <armor.h>
inherit SHIELD;
void create()
{
        set_name("�]�O��", ({ "magic shield","shield" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�i���]�O�c�����޵P�C\n");
                set("unit", "�i");
                set("no_sell",1);
                set("no_sac",1);
                set("value",900);          
                set("wear_msg", "$N����W��M���~�|�g, $n�Q�l��X�ӤF!\n");
           }
        set("armor_prop/dodge",6);
        set("armor_prop/armor",15);
        setup();
}

