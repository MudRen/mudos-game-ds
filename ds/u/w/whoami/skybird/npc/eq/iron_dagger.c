#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name("�K�P", ({ "iron dagger" ,"dagger"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@����K���y�Ӧ����Z���A���ˤO�����C\n");
                set("value", 3500);
                set("material", "steel");
        }
        init_dagger(35);
        
        set("weapon_prop/str", 1);
        set("limit_str",20);
        set("limit_dex",30);
        set("limit_level",15);

        set("wield_msg", "$N�q�h���N�X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n�äJ�h���C\n");

        setup();
}

