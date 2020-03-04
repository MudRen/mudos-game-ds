#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"索星劍" NOR,({"sorsin sword","sword"}) );
        set("long", "由一股強大的氣勁所形成的劍。\n");
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("limit_skill",70);
                set("material","crimsonsteel");
                set("limit_str",46);
                set("limit_int",35);
                set("limit_dex",65);
                set("limit_level",43);
                set("wield_msg", "$N裝上$n後，突感"HIY"日月星辰"NOR"都圍繞著$N在旋轉。\n"NOR);
        }
        set("weapon_prop/tec",2);
        set("weapon_prop/wit",-1);        
        set("weapon_prop/bar",-1);        
        set("weapon_prop/dex",5);        
        set("weapon_prop/str",-2);                
        set("weapon_prop/int",1);                
        if( this_player()->query_skill("sorsin_force") > 0 )
        this_player()->apply_skill("sorsin_force",15);
        init_sword(58);
        setup();        
}

