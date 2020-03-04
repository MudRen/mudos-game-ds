#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIR"烈日劍"NOR, ({ "sun sword","sword" }) );
        set_weight(11100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",@LONG
這把烈日劍異常的沉重，劍面極寬，劍刃鋒利。使用者需要
有相當的臂力才能揮的動，是一把足以削岩斷金的神兵利器。
LONG
);
                //set("no_sell",1);
                set("no_sac",1);
                set("material", "ice");
        }
    set("value", 5200);
    set("weapon_prop/bar",1);
    set("weapon_prop/sou",-1);
    set("weapon_prop/hit",8);
    set("weapon_prop/parry",8);
//    set("wield_msg",HIC"$N"HIC"將腰邊$n"HIC"緩緩抽出, 這裡的氣溫突然急劇下降!!\n"NOR);
//    set("unwield_msg",HIC"$N"HIC"將$n"HIC"上的薄冰拭去, 迅速的將"HIC"$n"HIC"插回腰上的劍鞘中。\n"NOR);
    init_sword(24);
    setup();
//      call_out("check_time", 30);
}

void check_time() // 2003.4.22 by ksj 檢查所在時空
{
  object obj,env;
  obj=environment(this_object());
  env=environment(obj);
  if( strsrch(file_name(env), "world1") != -1 )
  {
    message_vision("$N因為時空不合而立即鏽蝕成屑了。\n"NOR,this_object());
    destruct(this_object());
  }
  call_out("check_time", 35);
}

void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(21)) return; // 1/20 的機率出現特攻
        message_vision(HIM"$N"HIM"手上的$n"HIM"射出一道的炙熱的劍氣。\n"NOR,me,this_object());
        //tell_object(me,"你似乎被凍傷了，動作不太靈活。\n");
        message_vision(HIM"$N閃躲不及而被劍氣燙傷了。\n"NOR,victim);
        //me->receive_damage("hp",10+random(me->query("level")));
        //me->add_busy(1);
        victim->receive_damage("hp",15+random(40-victim->query_temp("apply/ice")), me);
        //victim->add_busy(1);
        return;
}

