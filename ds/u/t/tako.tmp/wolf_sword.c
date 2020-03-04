#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit SWORD;

void create() 
{
        set_name(YEL"狼牙劍"NOR,({"wolf-tooth sword","sword"}));
        set_weight(10000); 
                if( clonep() )
                set_default_object(__FILE__); 
 else { 
                set("long",
"由數百隻野狼的牙齒製成的,晚上還會隱約聽到野狼咆哮的聲音\n" 
" ,此劍是由名鑄劍師,靈劍王所鑄造的,靈氣逼人,但因是百隻狼\n"
"所製,靈氣轉為怨氣,是邪界武器排名數一數二的\n"
);
        set("limit_dex",32); 
        set("limit_skill",70);
        set("unit", "把");        
        set("value",1000);
        set("volume",4);        
        set("wield_msg",MAG"$N從腰際抽出一把$n,瞬間$N周圍的散出無比的煞氣。\n"NOR);  
        set("unwield_msg",MAG"$N放下手中的$n,$N提深口氣,把煞氣吸進體內。\n"NOR);
        set("material","steel");       
        set("weapon_prop/dex",-2); 
        set("weapon_prop/con",2);  
        set("weapn_prop/str",1);
        set("weapon_prop/int",-3);   
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-3);  
        set("replica_ob", "wolf sword2");     
        init_sword(65); 
           setup();
}    
}
int attack(object target)
{
 object me;
 me=this_player();
 if( random(8) < 6 )
 {
     message_vision("\n"
     +HIC"一陣咆哮聲從狼牙劍傳了開來,狼牙劍滲出一滴血往$n衝去！\n"NOR
     +HIC"忽然變成一隻惡狼,往$n身上狠狠的咬了下去！ \n"NOR     +HIR"造成四個腐洞\n\n"NOR,me,target);
 target->receive_damage("hp", 50+random(100));
 me->receive_damage("mp",40);
 me->add_busy(1);
 return 1;
}
else
{
     message_vision("\n"
     +HIR"一陣咆哮聲從狼牙劍傳了開來,狼牙劍滲出一滴血往$n衝去！\n"NOR
     +HIR"忽然變成一隻惡狼,往$n身上狠狠的咬了下去！\n"NOR
     +HIW"但是$n在千鈞一髮之際,向上跳開了!\n\n"NOR,me,target);
     me->receive_damage("ap",10);
     return 1;
        }
}



