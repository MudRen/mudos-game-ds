#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(RED"駭客神匕"NOR,({"hack dagger","dagger"}));
set("long" ,@LONG
這是一根長約四吋的一隻小匕首，上面刻著許多不知名的文字，傳說這隻匕首是惡靈駭客的隨身武器，有這一股神秘的力量。
LONG
        );

     
   set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("material","pem");
                set("no_sac",0);
        }
        set("value",2380);

        set("volume",1);
        
        set("monster_weapon_prop/bio",1);
        set("monster_weapon_prop/sou",-1);
        set("monster_weapon_prop/dodge",7);
        set("monster_weapon_prop/hit",12);
        set("monster_weapon_prop/damage",293);
        
        set("weapon_prop/bio",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/dodge",7);
        set("weapon_prop/hit",32);
        set("backstab_bonus",99);
        
        set("wield_msg",HIY"$N將$n"HIY"拿了出來，使$N全身充滿了電流。\n"NOR);
        set("unwield_msg", "$N將手中的$n放下，電流也隨著$n消失了。\n");
        
        init_dagger(14293);
        setup(); 
   
}        

 


