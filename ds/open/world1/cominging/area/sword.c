#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"���P�C" NOR,({"sorsin sword","sword"}) );
        set("long", "�Ѥ@�ѱj�j����l�ҧΦ����C�C\n");
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�`");
                set("limit_skill",70);
                set("material","crimsonsteel");
                set("limit_str",46);
                set("limit_int",35);
                set("limit_dex",65);
                set("limit_level",43);
                set("wield_msg", "$N�ˤW$n��A��P���P������¶��$N����C\n");
        }
        set("weapon_prop/tec",2);
        set("weapon_prop/wit",-1);        
        set("weapon_prop/bar",-1);        
        set("weapon_prop/dex",5);        
        set("weapon_prop/str",-2);                
        set("weapon_prop/int",1);                
        set("weapon_prop/sorsin_force",15);                
        init_sword(58);
        setup();        
}

