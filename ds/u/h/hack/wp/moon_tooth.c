#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("月牙",({"moon tooth","tooth"}));
	set("long",@LONG
這是一根長約七吋閃閃發亮的尖銳獸牙。你看見月牙上不時地閃
耀著淡淡詭異的青光，似乎不斷地凝結附近的水氣。月牙上散發出來
的寒氣使人視為一件帶有詛咒的不祥物。

LONG
);
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "支");
		set("material","gem");
		set("no_sac",1);
        }
        set("value",2380);
        set("volume",1);
        
    	set("monster_weapon_prop/bio",1);
    	set("monster_weapon_prop/sou",-1);
	set("monster_weapon_prop/dodge",7);
    	set("monster_weapon_prop/hit",12);
    	set("monster_weapon_prop/damage",43);
    	
    	set("weapon_prop/bio",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/dodge",7);
    	set("weapon_prop/hit",12);
	set("backstab_bonus",49);
	
	set("wield_msg",HIC"$N將$n緊緊握住，全身散發出迫人寒氣。\n"NOR);
	set("unwield_msg", "$N將手中的$n放下，攝人的寒氣也漸漸消散了。\n");
	
	init_dagger(43);
        setup();
	
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
         if( userp(me) && random(10) != 1 ) return;
       if(random(20) !=1 ) return;
	if(!victim->query_temp("heat"))
	{
message_vision(HIC"  $N"+HIC"手中的月牙突然射出一股寒氣，$n"+HIC "被寒氣射中動作顯得有些遲緩。\n"NOR,me,victim);
		victim->add_busy(1+random(2));
           victim->apply_condition("coldmoon_poison",3);
	}
	return;
}


