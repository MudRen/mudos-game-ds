/**************************************************

                回復技能[backup heal]  
                ap->hp,mp->ap,hp->mp 
                Editor - Jangshow 
                Date - 2003.3.22  

**************************************************/

#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
        int force,backup,heal;

        force=me->query_skill("force",2);
        backup=me->query_skill("backup-heal",2);
        heal=(force+backup)/2;

//ap->hp
        if(arg=="hp" )
        {
        if(me->query("ap") < heal/3 ) 
                return notify_fail("以你目前的身體狀況，不能使用回復技能。\n");
        if(me->query("hp") == me->query("max_hp"))
                     return notify_fail("你現在並沒有受傷哦。\n");
        message_vision(HIW"$N雙手微開，一股"HIR"紅色"HIW"的粉末，輕飄飄的覆蓋\在$N的傷口上。\n" NOR,me);
        me->receive_damage("ap",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("hp",heal*2/3 );
        else me->receive_heal("hp",heal);

        me->start_busy(2);
        me->improve_skill("backup-heal",1+random(me->query_int()/4));
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
        }    
        if(arg=="ap" )
        {
        if(me->query("mp") < heal/3 ) 
                return notify_fail("以你目前的身體狀況，不能使用回復技能。\n");
        if(me->query("ap") == me->query("max_ap"))
                     return notify_fail("你現在並沒有氣損哦。\n");
        message_vision(HIW"$N雙手微開，一股"HIB"藍色"HIW"的粉末，環繞在$N的周圍，提高了氣勁。\n" NOR,me);
        me->receive_damage("mp",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("ap",heal*2/3 );
        else me->receive_heal("ap",heal);
        me->start_busy(2);
        me->improve_skill("backup-heal",1+random(me->query_int()/4));
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
        }   
        if(arg=="mp" )
        {
        if(me->query("hp") < heal/3 ) 
                return notify_fail("以你目前的身體狀況，不能使用回復技能。\n");
        if(me->query("mp") == me->query("max_mp"))
                     return notify_fail("你現在並沒有神損哦。\n");
        message_vision(HIW"$N雙手微開，一股"HIR"紫色"HIW"的粉末，被$N吸了進去，提高了精神度。\n" NOR,me);
        me->receive_damage("hp",heal/3);
        
        if (me->is_fighting() ) me->receive_heal("mp",heal*2/3 );
        else me->receive_heal("mp",heal);

        me->start_busy(2);
        me->improve_skill("backup-heal",1+random(me->query_int()/4));
        me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
        return 1;
        }   
}
int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}


