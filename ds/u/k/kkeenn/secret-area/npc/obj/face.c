#include <armor.h>
inherit MASK;
void create()
{
        set_name("���ۤ��y", ({ "psychical face","face" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�i�����W�����n�C\n");
                set("unit", "�i");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",800);          
                set("wear_msg", "$N����Q��M�@�ӿ��~, �q$N���y�W���G�B�W�@�i$n\n");
                set("unequip_msg", "$N�V�O�J��n��, �ש���$n�����F�C\n");
           }
        set("armor_prop/dodge",4);
        set("armor_prop/armor",2);
        setup();
}

