//神武教：血穹蒼(bloodsky-force)  
//參考自tmr的bagi-force...:P   by DS-Acme
//update 2000/4/17 -By Tmr-

#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
        int force,bloodsky,heal;

        force=me->query_skill("force",2);
        bloodsky=me->query_skill("bloodsky-force",2);
        heal=(force+bloodsky)/2;

//轉AP化HP
        if(arg=="heal" )
        {
        if(me->query("ap") < heal/3 ) 
                return notify_fail("你目前的身體狀況，不能使用療傷功\能。\n");
        if(me->query("hp") == me->query("max_hp"))
                     return notify_fail("你現在並沒有受傷哦。\n");
        message_vision(HIR "$N潛心運氣，體內一股熱流在滾動，身上的傷口似乎恢復了。\n" NOR,me);
        me->receive_damage("ap",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal*2/3 );
        else me->receive_heal("hp",heal);

        me->start_busy(2);
        me->improve_skill("bloodsky-force",1+random(force/3)+me->query_int()/4 );
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
        }

        return notify_fail("血穹蒼心法有heal等功\能。\n");
}


int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b,c;
        b = me->query_skill("bloodsky-force",1);
        c = me->query("skill/bloodsky-force");
        
        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "你的智慧提高了！\n" NOR );
                        me->add("addition/int", 1);
                }
                else
                {
                        tell_object(me,HIY "你的體質提高了！\n" NOR );
                        me->add("addition/con", 1);
                }
                
                me->set("skill/bloodsky-force",b);
        }
        me->save();
        return;
}

