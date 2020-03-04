// 解除結界之術 -Luky-
//

#include <ansi.h>
inherit SKILL;
int break_wall(object wall);
int cast(object me, object target,string dir)
{
    object wall1,wall2,env,env2;
    mapping wall=([]);
    if(!target) return notify_fail("cast dispel_wall on <結界> 或 cast dispel_wall at <方向>\n");
    env=environment(me);
    if(!dir) // cast on wall.
    {
        //find other-side wall.
        if( living (target) )
            return notify_fail("此法術不能用於生物上！\n");
        wall1=target;
        if(!wall2=wall1->query("link_wall")) return notify_fail("施法目標異常！錯誤代碼: sp_dw_1\n");
    }
    else //cast on other room. ignore target.
    {
        if(!wall1=env->query_temp("wall/"+dir)) return notify_fail("那個方向沒有結界！\n");
        if(!wall2=wall1->query("link_wall")) return notify_fail("施法目標異常！錯誤代碼: sp_dw_3\n");
    }
    if( environment(me)->query("no_magic") )
        return notify_fail("這個地方不可以施法！\n");
    if((int)me->query("mp") < 40 )
        return notify_fail("你的法力不夠﹗\n");
    me->add("mp", -40);
    me->start_busy(2);
    message_vision("\n\n\t$N將雙手張開，低頭默念:[1;33m形無體∼法無邊∼神光現∼魔障破[0m\n\n",me);
    call_out("do_dispel",2,me,wall1,wall2);
    return 1;
}

int do_dispel(object me, object wall1,object wall2)
{
    int hard,sp,intt;
    if(!me)
    {
        return 1;
    }
    if(!wall1 || !wall2)
    {
        message_vision("$N放棄了這次的施法。\n",me);
        return 1;
    }
    if(environment(me)!=environment(wall1))
    {
        message_vision("$N的施法被中斷了。\n",me);
        return 1;
    }
    hard=wall1->query("level");
    sp=me->query_spell("dispel_wall");
    intt=me->query_int();
    message_vision(HIW+"$N猛然合掌，一道奇異的光芒迅速射向$n，"+NOR,me,wall1);
    if(random(intt+sp/2)<=random(hard))
    {
        message_vision(HIW+"但卻被$N彈了開來﹗\n"NOR,wall1);
    }
    else
    {
        message_vision(HIW+"$N被光芒所包住了﹗\n"+NOR,wall1);
        break_wall(wall1);
        break_wall(wall2);
    }
    me->improve_spell("dispel_wall",1+random(intt/3));
    return 1;
}

int break_wall(object wall)
{
    if(!wall) return 0;
    if(environment(wall))
    {
        tell_room(environment(wall),"極光結界開始變得透明而逐漸消失了！\n");
        environment(wall)->delete_temp("wall/"+wall->query("dir"));
        destruct(wall);
    }
    return 1;
}
