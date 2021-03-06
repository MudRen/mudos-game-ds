//god-benison 改良版. by Acme 2000.1.21
//改良II  -by Tmr- for 廢神殺、調長生，沐浴
//PM 11:30 2000/1/24

#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cure_all(object me,int sk,int inn);
int attack_b(object me,object target,int sk,int inn);

int cast(object me, object target)
{
     int sk,inn,cost;

    sk=me->query_spell("god-benison");
    inn=me->query_int();

    //    return notify_fail("神武革命中，暫時關閉。\n"); //By tmr
    if(sk < 20)
        return notify_fail("你的「神祝禱篇」還未成火侯，尚無能力使用。\n");
    if(me->query("ap") < 100 || me->query("mp") < 100)
        return notify_fail("你現在的身體狀況無法使用「神祝禱篇」。\n");
    if(me->is_fighting() )
    {
        if(!target )
            target = offensive_target(me);
        if(!me->can_fight(target))
            return me->can_fight(target);
        message_vision(
            "\n$N默唸"HIM"「神祝禱篇」"NOR"之"HIC"「長生」"NOR"訣：\n\n"
            +"      「大哉乾元，萬物滋始。」\n"
            +"      「至哉坤元，萬物滋生。」\n"
            +HIC"\n$N雙手左右畫圈，泛出淡藍之光，霎時藍光四散，團團圍繞著$n。\n"NOR,me,target);
        cost=(sk*5+inn*2)/8;
        me->start_busy(2);
        call_out("attack_b",1,me,target,sk,inn);
        me->receive_damage("mp",cost);
        me->set_temp("power_cast",1+sk/20);
    } //end of is_fighting()
    else
    {
        message_vision(
            "\n$N默唸"HIM"「神祝禱篇」"NOR"之"HIW"「沐浴」"NOR"訣：\n\n" NOR
            +"      「天門日射彩雲開，大降洪恩布九垓。」\n"
            +"      「萬物一時沾聖化，蒼生鼓舞醉金罍。」\n" NOR,me);

        me->receive_damage("mp",(sk*2+inn)/3 );
        me->start_busy(3);
        call_out("cure_all",3,me,sk,inn);
    }

    return 1;
}

int cure_all(object me,int sk,int inn)
{
    if(!me) return 0;

    if( !me->is_fighting() && random(sk) > random(30)  )
    {
        message_vision(HIW"\n$N全身上下圍繞著一陣白光，然後漸漸消去。\n" NOR,me);
        me->receive_curing("all",sk/20+inn/8);
        me->improve_spell("god-benison",random(2+inn/5) );
        return 1;
    }
    tell_object(me,"結果什麼事情都沒發生。\n");
    tell_room( environment(),me->query("name")+"搖搖頭, 失望的嘆了一口氣。\n",({me}) );
    return 1;
}

int attack_b(object me,object target,int sk,int inn)
{
    int damage,i;

    if(!me)
        return 0;
    if(!target)
        return notify_fail("目標消失了。\n");
    if( environment(me) != environment(target) )
        return notify_fail("目標離開了你的施法範圍。\n");
    if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1)
    {
        message_vision(HIW"$N"HIW"因為受到創傷而亂了思緒, 無法順利施展法術。\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");

    if(random(target->query_skill("dodge")*2)/3+random(target->query_shield())+1 < random( sk*2 )/3+inn )
    {
        damage = (sk*3+inn)/2;
        damage -=target->query_shield();
        damage = COMBAT_D->Merits_damage(me,target,damage,"wit");

        if(target->query("mp") >= damage ) i=1;
        else if(me->query("mp")+50>me->query("max_mp")) i=2;
        else if(target->query("ap") >= damage) i=2;
        else if(me->query("ap")+50>me->query("max_ap")) i=3;
        else i=3;

        switch( i ) {

        case 1:
            message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n頓時精神一陣恍惚，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("mp",damage,me);
            me->receive_heal("mp",damage);
            break;

        case 2:
            message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，$n但覺內勁一洩千里，霎時薄霧從$n散出，被$N吸收了。\n"NOR,me,target);
            target->receive_damage("ap",damage,me);
            me->receive_heal("ap",damage/3);
            break;

        case 3:
            message_vision(HIC"淡藍色薄霧"NOR"衝入$n體內，霎時薄霧從$n體內四面八方射出，$n狂吐了許\多鮮血。\n"NOR,me,target);
            COMBAT_D->report_status(target);         //顯示target狀態
            target->receive_damage("hp",damage*5/2,me);
            break;
        }

        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage")  )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        if(wizardp(me) && me->query("env/debug"))
            tell_object(me,"  造成"+damage+"點傷害!!\n");

        target->start_busy(1);
    }
    else	  message_vision(HIC"淡藍色薄霧"HIG"衝向$n，但是$n慌慌張張，左支右絀，逃出了藍光的圍繞。\n\n"NOR,me,target);

    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    me->improve_spell("god-benison",random(2+me->query("level")/2)+inn/7);
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    else return 100;
}
