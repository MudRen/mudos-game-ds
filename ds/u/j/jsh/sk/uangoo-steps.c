#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "\n$n以大幅度的跳躍，帶著腿風避過$N的攻擊。\n"NOR,
 "\n$n"HIY"錯開步伐，踏地一放，一股強大的力量，使得地上塵灰四起，使得$N不知道從何下手。\n"NOR,
 "\n$n"HIG"衝向前去，與$N正面交鋒，且一一化解了$N的攻擊。\n"NOR,
 "\n$n"HIC"收放真氣於奇筋八脈，硬擋下$N的攻擊卻毫無損傷。\n"NOR,
});

int exert(object me, object target, string arg)
{
        string msg;

        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="uangoo-steps")
                        return notify_fail("你並沒有使用【源古步】。\n");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIR"$N緩緩的慢步下來。\n"NOR,me);
                write("【源古步】已取消。\n");
                return 1;
        }

        if(me->query_skill("dodge")<5) return notify_fail("你的輕功\基礎不夠無法使用【源古步】。\n");
        if(me->query_skill_mapped("dodge")=="uangoo-steps")
                return notify_fail("你已經在使用【源古步】。\n");
        if(me->query("ap")<10 || me->query("hp")<50) return notify_fail("你目前的狀況無法使用【源古步】。\n");

        if(!me->skill_active( "uangoo-steps",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("你的動作還沒完成。\n");

        me->map_skill("dodge", "uangoo-steps");
        me->reset_action();
        
        message_vision("\n"HIC"$N左腳輕點，使出【源古步】，撫動了空氣中的微粒子振動。\n"NOR,me);
        me->receive_damage("ap",random(10));
        me->start_busy(1);
        return 1;
}

void delay(object me)
{
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="uangoo-steps")
        {
                 //remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<10)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIR"$N緩緩的慢步下來。\n"NOR,me);
                tell_object(me,"你目前的狀態無法繼續使用【源古步】。\n");
                //remove_call_out("delay");
                return ;
        }
      if(me->is_fighting()) me->receive_damage("ap",2);
      me->skill_active( "uangoo-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
void superpower(object me)
{
     int i,damage;
     object target;
     string *limbs;


    if( environment(me) != environment(target) ) return;
     if(!me->is_fighting()) return;

message_vision(HIG"$N聚集大量真氣，呈形於掌前，瞬間合十而放，一顆真氣球浮動於空中。\n"NOR,me);
     for (i=0;i<=4;i++)
     {
       damage=30+random(20);
       limbs = target->query("limbs");
       message_vision(HIR"狠狠踢向$n的"+limbs[random(sizeof(limbs))]+"。"NOR,me,target);
           switch( random(33) ) {
           case 0:
               message_vision(HIW"$n輕鬆一躍，躲開了攻擊!!。\n"NOR,me,target);
               break;
           case 1:
               message_vision(HIW"$n不懼你的攻擊，檔了下來\n"NOR,me,target);
               break;
           case 2:
               message_vision(HIW"$n輕鬆一閃，避開了攻擊。\n"NOR,me,target);
               break;
           case 3:
               message_vision(HIW"$n輕鬆一躲，閃開了攻擊。\n"NOR,me,target);
               break;
           default:
               message_vision(HIR"$n似乎受到前所未有的粉碎性攻擊，放聲唉嚎！！"NOR,me,target);
               target->receive_damage("hp",damage);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                     tell_object(me,HIY"("+damage+")"NOR"\n");
             COMBAT_D->report_status(target);         //顯示target狀態
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                     tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug")) 
                     tell_object(me,"  造成"+damage+"點傷害!!\n"); 
               me->receive_damage("ap",15+random(6));
               break;
           }
     }
     me->delete_temp("uangoo-steps/ball");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

