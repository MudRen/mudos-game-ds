#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string dir,string str)
{
        string msg;
        object horse,weapon;
        int damage;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target->is_ghost())
        {
                return notify_fail("你認為衝撞這個東東會很有快感嗎！？\n");
        }
        if(environment(me)->query("no_fight") || environment(me)->query("no_kill"))
                return notify_fail("這裡禁止戰鬥﹗\n");
        if((int)me->query("mp") < 10 )
                return notify_fail("你目前的身體狀況無法完成衝撞這個動作。\n");
         horse = (object)me->query_temp("on_horse");
          if(!horse) {
                 notify_fail("你必須騎在東東上才能衝刺敵人！\n");
                 return 0;
                  }
        weapon=me->query_temp("weapon");
        if(!weapon) return notify_fail("你手中沒有槍，無法進行衝刺撞擊。\n");
        if(weapon->query("skill_type")!="fork") return notify_fail("你手中沒有槍，無法進行衝刺撞擊。\n");
        if(me->query_skill("charge")<10) return notify_fail("你的衝刺技術還不夠就想出師啦！？\n");
        if(userp(me) && userp(target))  //攻擊的一定要設定
        {
          if(me->query("level") < 5 ) return notify_fail("你目前的等級不可以攻擊玩家﹗\n");
          if(target->query("level") < 5 ) return notify_fail("你不可以攻擊如此低等級的玩家﹗\n");
          if(me->query("level") > target->query("level") + 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
          if(me->query("level") < target->query("level") - 5 ) return notify_fail("你不可以攻擊等級相差太多的玩家﹗\n");
        }
        if(!me) return 0;
        //閃過
        if( random(me->query_dex()/2+me->query_skill("charge")/3+me->query_skill("ride")/3+me->query_skill("spear")/5) < random(target->query_dex()/3*2+target->query_skill("dodge")/2)+random(15))
        {
         message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，快速的朝$n衝撞過去。\n"NOR,me,target);
         message_vision(HIC"$n看清$N的來勢，以迅捷的身法輕鬆的避過你的攻擊。\n"NOR,me,target);      
         me->start_busy(1);
         if(!target->is_fighting(me)) target->kill_ob(me);      //反擊
         return 1;
        }
        //命中
        damage = me->query_skill("charge")/3*2 + me->qurey_skill("ride")/2 + me->query_skill("fork")+me->query_dex()/5+me->query_str()/5+random(20)-target->query_dex()/2+target->query_skill("dodge")/3;
        damage -= target->query_armor();
        if(damage < 30) damage = 30;
        if(damage > 250) damage =250;
        if(damage < 20)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，快速的朝$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n看清$N的來勢，試圖扭身避向一旁，但因時間計算上的誤差，仍受到小小的擦傷。\n"NOR,me,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;
  }
        if(damage < 50)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，快速的朝$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n看清$N的來勢，企圖以迅捷的身法向一旁閃開，但因速度不夠，仍受到一些擦傷。\n"NOR,me,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;
  }
        if(damage < 80)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，快速的朝$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n在慌亂中勉強扭身閃避$N的衝撞，雖然避開正面的撞擊，但仍受到不小的傷害。\n"NOR,me,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;
  }
        if(damage < 120)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，快速的朝$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n在避無可避的情況下，被$N正面撞個正著，受到極為嚴重的撞傷。\n"NOR,me,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;  
}
        if(damage < 180)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，以雷霆萬鈞之勢向$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n被$N強大無濤的撞擊猛然衝倒在地，受到無比巨大的傷害。\n"NOR,me,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;  
}
        if(220 < damage)
        { 
        message_vision(HIW"$N大喝一聲"HIR"『殺』"HIW"兩腿一夾，以雷霆萬鈞之勢$n衝撞過去。\n\n"NOR,me,target);
        message_vision(HIR"$n被$N強大無濤的撞擊猛然衝倒在地，受到無比巨大的傷害。\n\n"NOR,me,target);
        message_vision(HIC"就在這同時$N將手中的長矛順勢向前一戳，瞬間貫穿$n的胸膛。\n"NOR,me,target);
        message_vision(HIR"無數的鮮血自$N的胸口泉湧而出。\n"NOR,target);
        me->start_busy(1);
	// 增加素質對傷害的影響
	damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp", damage, me );
        if(!me->is_fighting(target)) me->kill_ob(target);       //攻擊性技能加上這行
        if(target->query("hp")>0)
        {
                if(!target->is_fighting(me)) target->kill_ob(me);       //攻擊性技能加上這行
                COMBAT_D->report_status(target);
        }
return 1;  
}

}

