//god-shield  神祝禱盾 -by tmr- //PM 11:33 2000/1/24
//update 2000/4/7 -By Tmr-

#include <ansi.h>
#define GOD_SHIELD	"/open/always/god-benison-shield"

inherit SSERVER;
inherit SKILL;

int clone_shield(object me,int sk,int inn);

int cast(object me, object target)
{
      int sk,inn,cost;

    //return notify_fail("god-shield debuging...sorry by -Acme-\n");
    sk=me->query_spell("god-shield");
    inn=me->query_int();
    cost=(sk*3+inn*2)/2;
    //        if(me->query("ap") < 200 || me->query("mp") < 200)   條件改更嚴
    if( me->query("mp") < 200 || me->query("mp") < me->query("max_mp")/2 )
        return notify_fail("你的魔法不足，無法使用「神祝禱盾」。\n");
    if( me->query("hp") < me->query("max_hp")/2 )
        return notify_fail("看來你受傷不輕，無法使用「神祝禱盾」。\n");
    if(me->is_fighting() )
        return notify_fail("你正在戰鬥中。\n");

    message_vision(
        GRN"$N吟道：「精神感天地，陰氣自消融，獨藉扶持力，皆因造化功\。」\n" NOR
        ,me);

    call_out("clone_shield",3,me,sk,inn);
    if( userp(me) )
        me->receive_damage("mp",cost );
    me->start_busy(2);
    return 1;
}

int clone_shield(object me,int sk,int inn)
{
    object shield,ob;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("什麼事也沒發生...\n");
    if( (sk*3+inn*2)/4 < random(70)
            || objectp(ob = present("god-benison-shield", me) )  )
        //限制施法者只能擁有一個shield。
        message_vision("結果什麼事也沒發生.....\n",me);
    else    {
        shield=new(GOD_SHIELD);
        if( !shield->move(me) ) {
            message_vision("結果什麼事也沒發生.....\n",me);
            me->improve_spell("god-shield",random(inn) + 2);
            return 1;
        }


        shield->update_shield(me,sk,inn);
        message_vision(HIG "一陣綠色閃光過後，$N的手中忽然出現一個盾牌！！\n" NOR,me);
        me->improve_spell("god-shield",random(inn) + 2);
    }
    return 1;
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    else return 100;
}

