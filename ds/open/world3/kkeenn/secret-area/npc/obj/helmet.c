#include <armor.h>
inherit HEAD;
void create()
{
        set_name("��������", ({ "light helmet","helmet" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�ӯ¹q�l�s�����Y���C\n");
                set("unit", "��");
                set("material", "silver");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1000);          
                set("wear_msg", "$N��|�P���q�l���E���l�W, �n�����F��b�O�@$N���j�Y\n");
                set("unequip_msg", "$N���q�O����, $n��M�����F�C\n");
           }
        set("armor_prop/dodge",1);
        set("armor_prop/armor",7);
        setup();
}

