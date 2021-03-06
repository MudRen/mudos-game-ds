//Adv_八極門：八極內功(bagi_force)  
//八極門評比：
//        攻擊    防禦    輔助    醫療    牽制
//        10       2       3       1       4
//by tmr AM 02:03 1999/12/4
//update By tmr PM 2000/3/4

#include <ansi.h>
inherit SKILL;

void delay(object me);
void armor(object me,int effect);
void power_up(object me,int effect);

int exert(object me,object target, string arg)
{
        int force,bagi_force,heal;

        force=me->query_skill("force",2);
        bagi_force=me->query_skill("bagi_force",2);
        heal=(force+bagi_force)/2;

//療傷功能，扣ap 補 hp ，引用評比 醫療 1
        if(arg =="heal" )
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("你正在修煉八極內功\。\n");
            	if(me->query("hp") >= me->query("max_hp") ) return notify_fail("你的健康狀況已達顛峰。\n"); // tmr 你忘了這行 add by Luky
            	if(me->query("ap") < heal/2 ) return notify_fail("你目前的身體狀況，不能使用療傷功\能。\n");
                
                message_vision( "$N將雙掌平放腰間，氣轉周天，運息療傷。\n" ,me); //改一下讓顏色清爽一點, 一直吐血很惡.luky
                me->receive_damage("ap",heal/2);

// fighting 中 {heal*(2/3) } 
// 引用評比 輔助 4
            if (me->is_fighting() ) me->receive_heal("hp",heal*2/3 );
                        else me->receive_heal("hp",heal*4/5);

                me->start_busy(1);
                me->improve_skill("bagi_force",1+random(force/4)+me->query_int()/5 );
                me->improve_skill("force",1+random(me->query("level"))+me->query_int()/5 );
                return 1;
        }

//「八極勁擋」 引用評比 防禦 2
        if(arg=="armor")
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("你正在修煉八極內功\。\n");
                if (bagi_force< 30 ) return notify_fail("你的八極心法不夠，無法施展「八極勁擋」。 \n");
                if(me->query("ap") < 120 ) return notify_fail("你目前的狀態無法施展「八極勁擋」。\n");
                if(me->query_temp("bagi_force/armor")==1) return notify_fail("你已經在施展「八極勁擋」。\n");
                if(me->query_temp("bagi_force/power_up")==1) return notify_fail("你已經在施展「八震訣」。\n");

                message_vision(HIG "$N馬步一坐，運使體內的纏絲勁遂繞著身體形成一道氣勁。 \n" NOR,me);
                me->add_temp("apply/armor", heal/3); //最多增加33 Luky
              me->improve_skill("bagi_force",1+random(force/3)+me->query_int()/4 );
              me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                me->receive_damage("ap",100);
                me->set_temp("bagi_force/armor",1);
                me->start_busy(2);
                me->skill_active( "bagi_force",(: call_other, __FILE__, "armor", me,heal/3:), 300);
                return 1;
        }
        
//八震訣 引用評比 攻擊力 10 輔助 3
        if(arg=="power_up")
        {
                if( me->query_skill_mapped("force")=="bagi_force" ) return notify_fail("你正在修煉八極內功\。\n");
                if (bagi_force< 50 ) return notify_fail("你的八極心法不夠，無法施展「八震訣」。 \n");
                if(me->query("ap") < 70  || me->query("hp")<120 ) return notify_fail("你目前的狀態無法施展「八震訣」。\n");
                if(me->query_temp("bagi_force/power_up")==1) return notify_fail("你已經在施展「八震訣」。\n");
                if(me->query_temp("bagi_force/armor")==1) return notify_fail("你已經施展了「八極勁擋」。\n");

             message_vision(HIY "$N施展八極不傳之祕「八震訣」，登時全身肌肉暴起！！ \n" NOR,me);
                me->add_temp("apply/damage", heal/2 ); //最多增加50 Luky
              me->improve_skill("bagi_force",1+random(force/3)+me->query_int()/4 );
              me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                me->receive_damage("hp",100);
                me->receive_damage("ap",50);
                me->set_temp("bagi_force/power_up",1);
                me->start_busy(2);
                me->skill_active( "bagi_force",(: call_other, __FILE__, "power_up", me,heal/2:), 300);
                return 1;
        }
        return notify_fail("八極內功\有heal,armor,power_up 等功\能。\n");

}

void armor(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("bagi_force/armor") ) return;
        message_vision(HIG "$N身子一抖，散去了八極護身氣勁。\n"NOR,me);
        me->add_temp("apply/armor",-effect);
        me->delete_temp("bagi_force/armor");
        return;
}

void power_up(object me,int effect)
{
        if(!me) return;
        if(!me->query_temp("bagi_force/power_up") ) return;
        message_vision(HIG "$N一聲低嘯，渾身暴起的肌肉恢復了平常的狀態。\n"NOR,me);
        me->add_temp("apply/damage",-effect);
        me->delete_temp("bagi_force/power_up");
        return;
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
        b = me->query_skill("bagi_force",1);
        c = me->query("skill/bagi_force");//luky
        //bagi_force 80 大關 (十萬exp)
        if( b > 79 && !me->query("bagi/forceok") )
        {
               	tell_object(me,HIW "經過長期的修煉，你的八極內功\更上一層了！\n" NOR );
               	tell_object(me,HIY "你的體質和力量提高了！\n" NOR );
               	me->add("addition/str", 1);
               	me->add("addition/con", 1);
		me->set("bagi/forceok",1); //標記
               	me->delete("bagi/bagi_force");
		me->save();
        }

        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me,HIY "你的力量提高了！\n" NOR );
                        me->add("addition/str", 1);
                }
                else
                {
                        tell_object(me,HIY "你的體質提高了！\n" NOR );
                        me->add("addition/con", 1);
                }
                
                me->set("skill/bagi_force",b);
        }
        me->save();
        return;
}

