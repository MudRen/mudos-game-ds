#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
        int sk,i,inn;
        object ob,*ob2;

        sk=me->query_spell("god-benison");
        inn=me->query_int();

        if(sk < 20) tell_object(me,"你的「神祝禱篇」還未成火侯，尚無能力使用。\n");
        if(me->is_busy() ) return notify_fail("你現在正忙著，沒有空吧。\n");
        if(me->query("hp")<100 || me->query("mp")<100) return notify_fail("你目前的身體狀態無法使用「神祝禱篇」的。\n");

        if(me->is_fighting() )
        {
        if(!target) return notify_fail("你要對誰施展「神祝禱篇」？？\n");

        switch( random(3) ) 
        {
        case 0:
                message_vision(HIG
                "$N默唸「神祝禱篇」之「六合」訣：\n\n" NOR
        +HIM    "      「群兇彌六合，日月蔽風塵。」\n" NOR
        +HIM    "      「祥煙浮寶殿，明月照金床。」\n" NOR
        +HIY    "\n$N頭頂上方數尺忽凝聚數道無形金黃箭氣....\n" NOR
                ,me);
        ob2 = all_inventory(environment(me));

        for(i=0; i<sizeof(ob2); i++)
        {
                if( !living(ob2[i]) || ob2[i]==me || !ob2->is_fight(me)|| !ob2->is_kill(me) ) continue;

                message_vision(HIY"$N默唸一聲：「去」，一數金黃箭氣迅捷無迅無比地往$n射去！！\n" NOR,me,ob2[i]);
                if(random
(ob2[i]->query_skill("dodge")/2+ob2[i]->query_shield() )< random(sk+inn) )
                {
                        message_vision(HIR"\n$N閃躲不及中了道金黃箭氣，只聽$N慘呼一聲，看來受傷不輕。\n\n"NOR,ob2[i]);                 
                        ob2[i]->receive_damage("hp",sk/2+random(inn)*2 );
                }
                else
                        message_vision(HIG"\n只聽$N驚呼一聲，使盡吃奶的力氣，好不容易躲開了金黃箭氣的追擊。\n\n"NOR,ob2[i]);
        }
        break;
        
        case 1:
                message_vision(HIG
                "$N默唸「神祝禱篇」之「神殺」訣：\n\n" NOR
        +HIM    "      「血刃浮沉戍上遊，披頭五鬼在辰求。」\n" NOR
        +HIM    "      「天哭逆數起於午，凡占切忌動當頭。」\n" NOR
        +HIC    "\n只見$N頭上一道刺眼強光，赫然出現三位神將，威風凜凜，不可一世！！\n" NOR
,me);

        message_vision(HIY "\n$N雙手結卬，低念數聲，驅使「血刃」，「披頭」，「天哭」引嘯同擊$n！！\n"NOR,me,target);

        if(random(target->query_skill("dodge")/2+target->query_shield() )< random(sk+inn) )
        {
                message_vision(
                MAG"血刃殺手中剝血刃直砍橫劈十三刀，砍向$N頭、手、胸三盤要害！！\n" NOR
        +       MAG"披頭殺揮舞手上二把奪魂匕，七七四十九式連往$N胸、腰各要害招呼！！\n" NOR
        +       MAG"天哭殺氣運手上穿骨槍，一式「石破天驚」，十成力道刺向$N胸口要穴！！\n" NOR
        +       HIR"\n$N慘呼一聲，登時血花四濺、狂吐數口鮮血，看來受傷不輕。\n\n" NOR
        ,target);
        target->receive_damage("hp",sk+inn*3);
        }
        else
        {
                message_vision(HIG"\n$n使出渾身解數，狼狽的逃開了這一擊。\n\n"NOR,me,target);
        }
        break;

        case 2:
                 message_vision(HIG
                 "$N默唸「神祝禱篇」中的「長生」訣：\n\n" NOR
        +HIM     "      「大哉乾元，萬物滋始。」\n" NOR
        +HIM     "      「至哉坤元，萬物滋生。」\n" NOR    
        +HIC     "\n$N雙手左右畫圈，泛出淡藍色之光，霎時藍光四散，團團圍繞著$n。\n"NOR,me,target);

        if(random(target->query("inn")/2+target->query_shield() )< random(sk+inn) )
        {
                 message_vision(HIC
                    "淡藍色之光衝向$n體內，只見$n癱軟在地上，慢慢地從$n身體裡散出\n" NOR
        +HIR        "血紅色的薄霧，$N伸出雙手，閉目吐吶，血色對霧緩緩的被$N吸收了。\n\n" NOR,me,target);

        target->receive_damage("mp",sk+inn);
        me->set("heal_mp",(sk+inn)/2);
        }
        else
        {
                message_vision(HIG"\n$n慌慌張張，左支右絀，逃出了藍光的圍繞。\n\n"NOR,me,target);
        }
        break;
        }
        
        me->start_busy(2);
        me->receive_damage("mp",((sk/2)+random(inn/2)) );
        me->improve_spell("god-benison",inn/10+random(3));
        }
        else
        {

        if(sk>40 && random(3)==1 )
        {
                message_vision(HIG
                "$N默唸「神祝禱篇」之「沫浴」訣：\n\n" NOR
        +HIM    "      「天門日射彩雲開，大降洪恩布九垓。」\n" NOR
        +HIM    "      「萬物一時沾聖化，蒼生鼓舞醉金罍。」\n" NOR
        +HIW    "\n登時$N全身上下圍繞著一陣白光，然後漸漸消去。\n" NOR
                ,me);

                        if(me->query("wound/head") )
                           me->receive_curing("head",sk/20+inn/8);
                        if(me->query("wound/hand") )
                           me->receive_curing("hand",sk/20+inn/8);
                        if(me->query("wound/foot") )
                           me->receive_curing("foot",sk/20+inn/8);
                        if(me->query("wound/body") )
                           me->receive_curing("body",sk/20+inn/8);
        }
        else
        {
                message_vision(HIG
                "$N默唸「神祝禱篇」之「遊魂」訣：\n\n" NOR
        +HIM    "      「重陰在上，鬼氛浮游。神黯黯，意悠悠。」\n" NOR
        +HIM    "      「若得陰人引，變化魚龍出大淵。」\n" NOR
        +HIB    "\n\n登時$N的四周鬼影重重，陰風陣陣....\n" NOR
                ,me);


                if(me->query_temp("call_ghost")<=3 && (sk+me->query_int() ) >random(40) )
                {
                ob=new(__DIR__"npc/ghost");
                ob->set("level",random((sk+me->query_int())/3) );
                ob->set_temp("host",me->query("id") );
                message_vision(HIW "\n只見$N身旁的煙霧一起，伴雜著鬼嘯魂啼，漸漸凝聚成一股人形.....\n"NOR,me);
                me->add_temp("call_ghost",1);
                ob->move(environment(me) );
                }
                message_vision(HIW "\n只見$N四周鬼影隱默，又恢復了平常的樣子，看來什麼事也沒有發生。\n"NOR,me);
        }
        me->start_busy(2);
        me->receive_damage("mp",((sk/2)+random(inn)/2) );
        me->improve_spell("god-benison",inn/10+random(3));
        }
        return 1;
}
