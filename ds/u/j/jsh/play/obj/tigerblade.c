#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY"��z "HIW"���M"NOR, ({ "tiger blade", "blade" }));
        set("long", "�Ĩ��r�ꪺ����A�A���J�d�~��z�̡A�~�����z���A�i���갩�C\n");
        set_weight(12500);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("volume",3);
                set("material", "crimsonsteel");
                set("limit_skill",40);
                set("limit_str",25);
                set("limit_dex",30);
                      set("value",15000);
                set("limit_lv", 25);
        }
        set("weapon_prop/armor", 15);
        set("weapon_prop/con",  1);
        set("weapon_prop/str",2); 
        set("weapn_prop/dex",-2);
        set("wield_msg",HIW"$N�N$w���_�����@�����A$N�������]�i�ݥX�A"HIR"�� . ...\n");
        set("unwield_msg", "$N�N��$n��U�C\n");

        init_blade(80);
        setup();
}

