#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(YEL"�F���C"NOR, ({ "ling yan sword", "sword" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o��C�O�e�����j�̤l�U�A�F���M�ΨؼC�A�]�p�D�`�S�O�A�e���ϥΡC\n");
                set("value", 15000);
                set("material", "steel");
                set("no_steal", 1);
}
        init_sword(70);
        set("weapon_prop/tec", 1);
        set("weapon_prop/bar", -1); //2003.5.2  by ksj
        set("weapon_prop/dex", 3);
        set("replica_ob", __DIR__"sword");
        set("wield_msg", "$N�˳�$n��A��P��ޥ��W�ɡC\n");
        setup();
}
