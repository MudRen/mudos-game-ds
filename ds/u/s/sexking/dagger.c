#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name("�p����P��",({"sexking dagger","dagger"}));
        set("long",@LONG
�o�O�@���Τp���󰵦����P���ݰ_�ӫܳn���ܭ����ˤl�C

LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","iron");
                set("no_sac",1);
        }
        set("value",4380);
        set("volume",1);
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/dodge",5);
        set("weapon_prop/perception",6);
        set("weapon_prop/hit",11);
        set("backstab_bonus",36);
        init_dagger(10000);
        setup();
}


