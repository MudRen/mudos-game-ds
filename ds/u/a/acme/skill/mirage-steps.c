//神武教輕功：仙源迷蹤步   by Acme 1999.12.11
//cp到舊的被luky say cow....flee..ack
//so sorry

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "\n$n衣袂飄飄，長袖飛舞，從容避過此招。\n"NOR,
 "\n$n一招"HIW"『"HIC"寒潭飛雪"HIW"』"NOR"，後一飛躍，輕輕的避過了$N的攻擊。\n",
 "\n$n右腳掃踢地上塵土，一式"HIW"『"HIC"塵泥浮空"HIW"』"NOR"只見滿空飛灰，趁勢避過此招。\n",
 "\n$n邁開大步，圍繞著$N使出"HIW"『"HIC"八卦吉星"HIW"』"NOR"，$N登時頭昏眼花，無從著手。\n",
 "\n$n氣定神閒，身形無定，勢如翔龍，遊走四方，輕輕巧巧的避過$N的攻擊。\n",
 "\n$n一式"HIW"【"HIG"流螢舞空"HIW"】"NOR"，只見$n腳步如風，分化成數十個幻影，$N無從下手，呆若木雞。\n",
});

int exert(object me, object target, string arg)
{
        string msg;

        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="mirage-steps")
                        return notify_fail("你並沒有使用【仙源迷蹤步】。\n");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
                write("技能【仙源迷蹤步】已取消。\n");
                return 1;
        }

        if(me->query_skill("dodge")<20) return notify_fail("你的輕功\基礎不夠無法使用【仙源迷蹤步】。\n");
        if(me->query_skill_mapped("dodge")=="mirage-steps")
                return notify_fail("你已經在使用【仙源迷蹤步】。\n");
        if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你目前的身體狀況無法使用【仙源迷蹤步】。\n");

        if(!me->skill_active( "mirage-steps",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("你的仙源迷蹤步收招動作還沒完成。\n");

        me->map_skill("dodge", "mirage-steps");
        me->reset_action();
        
        message_vision("\n"HIW"$N身影迷離，開始施展【仙源迷蹤步】，令人捉摸不定。\n"NOR,me);
        me->receive_damage("ap",2);
        me->start_busy(1);
        return 1;
}

void delay(object me)
{
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="mirage-steps")
        {
                 //remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<2)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N慢慢的停下了腳步。\n"NOR,me);
                tell_object(me,"你的體力不足無法繼續使用【仙源迷蹤步】。\n");
                //remove_call_out("delay");
                return ;
        }
      if(me->is_fighting()) me->receive_damage("ap",2);
      me->skill_active( "mirage-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob) 
{
        int a;
        a=ob->query_dex();
        a=a+ob->query_int();
        a=a+40;
        if(a>90) a=90;
        return a;
}
