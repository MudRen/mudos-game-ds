//神武教：血蒼穹(bloodsky-force)  
//修改自tmr的bagi-force...:P

#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
        int force,bloodsky,heal;

        force=me->query_skill("force",2);
        bloodsky=me->query_skill("bloodsky-force",2);
        heal=(force+bloodsky)/2;

        if(arg=="off") 
        {
                if(me->query_skill_mapped("force")=="bloodsky-force")
                {
                   message_vision("$N功\聚丹田，氣歸紫海，雙手一撐，翻身而起，渾身舒泰無比。\n",me);
                   me->delete_temp("is_busy/bloodsky");
                   me->map_skill("force");
                   return 1;
                } else return notify_fail("你並沒有在修行「血蒼穹」內功\。\n");    
        }

        if(!arg)
        {
           if(me->is_busy() )
                return notify_fail("你先停止你手邊的事情吧。\n");
           if(me->is_ghost() )
                return notify_fail("你現在是靈魂，無法修行內功\。\n");
           if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("你已正在修行『血蒼穹』內功\了。\n");
           if(me->query("hp") < 10 || me->query("mp") < 10 || me->query("ap") < 10 ) 
                return notify_fail("你目前的身體狀況不好，無法修行『血蒼穹』內功\。\n");
           if(me->is_fighting() )
                return notify_fail("你正忙著打架，沒空修行『血蒼穹』內功\。\n");
           if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");
           message_vision(HIB "$N凝神靜氣，潛運內功\，一連吐納調息，開始修練『血蒼穹』內功\。\n" NOR,me);
  
           me->receive_damage("hp",3);
           me->receive_damage("mp",3);
           me->receive_damage("ap",3);
            
           me->set_temp("is_busy/bloodsky","你正在修行『血蒼穹』內功\，暫時不能移動。");
           me->map_skill("force","bloodsky-force");
           me->start_busy(2);
           me->skill_active( "bloodsky-force",(: call_other, __FILE__, "delay", me:), 2);
           return 1;
        }

//轉AP化HP

        if(arg=="heal" )
        {
        if(me->is_busy() )
                return notify_fail("你正忙著....\n");
        if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("你正在修行『血蒼穹』內功\。\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");
        if(me->query("ap") < heal/3 ) 
                return notify_fail("你目前的身體狀況，不能使用療傷功\能。\n");
        message_vision(HIR "$N潛心運氣，體內一股熱流在滾動，身上的傷口似乎恢復了。\n" NOR,me);
        me->receive_damage("ap",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal*(2/3) );
        else me->receive_heal("hp",heal);

        me->start_busy(2);
        me->improve_skill("bloodsky-force",random(10)+1 );
        return 1;
        }

//轉MP化AP

        if(arg=="fresh")
        {
        if(me->is_busy() )
                return notify_fail("你正忙著...\n");
        if( me->query_skill_mapped("force")=="bloodsky-force" ) 
                return notify_fail("你正在修行『血蒼穹』內功\。\n");
        if( sizeof(me->query_temp("is_busy")) ) 
                return notify_fail("你現在正在忙。\n");
        if(me->query("mp") < heal/2 ) 
                return notify_fail("你目前的身體狀況，無法恢復內勁。\n");
        message_vision(HIG "$N運起內功\，體內真氣流經四肢百骸，奇經八脈走九宮雷府，運轉一大週天。\n" NOR,me);
        me->receive_damage("mp",heal/2);

        if (me->is_fighting() ) me->receive_heal("ap",heal*(2/3) );
        else me->receive_heal("ap",heal);

        me->start_busy(2);
        me->improve_skill("bloodsky-force",random(10)+1);
        return 1;
        }
        return notify_fail("神武內功\有heal,fresh,等功\能。\n");
}

void delay(object me)
{
        if ( !me 
        ||   !me->query_temp("is_busy/bloodsky")
        ||   me->query_skill_mapped("force")!="bloodsky-force"
        ||    me->is_fighting() )
        {
                me->map_skill("bloodsky-force");
                return;
        }

        if(me->query("hp") < 10 || me->query("mp") < 10 || me->query("ap") < 10 )
        {
                message_vision("$N功\聚丹田，氣歸紫海，雙手一撐，翻身便起，渾身舒泰無比。\n",me);
                me->delete_temp("is_busy/bloodsky");
                me->map_skill("force");
                return;
        }       

        //bloodsky-force 70 大關 (二十萬exp)

        if (!me->query("senwu/forceok") && me->query_skill("bloodsky-force",1)==70)
        {
                me->add("senwu/bloodsky-force",me->query_int()/3+random(me->query_con()/4)  );
                if (me->query("senwu/bloodsky-force")>200000 )
                {
                        tell_object(me,HIW "經過長年的修行，你的『血蒼穹』內功\更上一層了！\n" NOR );
                        tell_object(me,HIY "你的體質和力量提高了！\n" NOR );
                        me->add("addition/str", 1);
                        me->add("addition/con", 1);
                        me->set("senwu/forceok",1);
                        me->set_skill("bloodsky-force",75);
                        me->delete("senwu/bloodsky-force");
                }
        }
        else {
                me->improve_skill("bloodsky-force",me->query_int()/3+random(me->query_con()/4)  );
                me->improve_skill("force",me->query_int()/3+random(me->query_con()/4)  );
        }

            me->receive_damage("hp",5);
            me->receive_damage("mp",6);
            me->receive_damage("ap",7);

            me->skill_active( "bloodsky-force",(: call_other, __FILE__, "delay", me:), 3);

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