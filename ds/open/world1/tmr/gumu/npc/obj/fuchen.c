#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("�ع�", ({ "brush dust whip","whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "�`");
                set("long", "�o�O�@�`�عСA���u��ӡA�O�ܳ��r���L���C\n");
                set("value", 7000);
                set("material", "leather");
                set("wield_msg", "$N�u�|�v���@�n�q�V����X�@�`$n���b�⤤�C\n");
                set("unwield_msg", "$N�N�⤤��$n�O�^�V���C\n");
        }
        set("weapon_prop/dex", 1); 
        set("weapon_prop/con", 1); 
        set("weapon_prop/damage", 5); 
        init_whip(60);
        setup();
}

