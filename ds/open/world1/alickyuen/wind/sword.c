#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY"�F���C"NOR, ({ "ling yan sword", "sword" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o��C�O�e�����j�̤l�U�A�F���M�ΨؼC�A�]�p�D�`�S�O�A�e���ϥΡC\n");
                set("value", 10000);
                set("material", "steel");
                set("no_steal", 1);
}
        init_sword(55);
        set("weapon_prop/tec", 1);
        set("weapon_prop/bar", -1); //2003.5.2 by ksj
        set("wield_msg", "$N�˳�$n��A��P��ޥ��W�ɡC\n");
        setup();
}
