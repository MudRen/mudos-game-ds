//Update by Linjack 99/10/19
/* 疾風門 ： 殘月心法(moon_force) 由 Cominging 於 1999/5/29 日所創 */
// QC: Luky [10.21.1999] 開放實際測試.
// Update by tmr 2000/1/16
// Visit By Cominging 2000/1/16

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void arc(object me,object target);

int exert(object me,object target, string arg)
{
    int heal,reheal,sk,lv;
    int p,max;
    object weapon;

    if( arg=="off" )
    {
        if( me->query_skill_mapped("force")!="moon_force" )
            return notify_fail("你並沒有在運功\。\n");
        me->delete_temp("is_busy/moon_force");
        message_vision(HIY"$N閉起的兩眼慢慢睜開，內息又流回經脈中了。\n"NOR,me);
        me->map_skill("force");
        return 1;
    }

    if( me->query_skill_mapped("force")=="moon_force" )
        return notify_fail("你現在還在修煉殘月心法中。\n");

    if(!arg)
    {
        if( me->is_fighting() )
            return notify_fail("你現在正忙著打架, 沒空練功\。\n");
        if( me->query("hp") < 20 || me->query("ap") < 20 )
            return notify_fail("你目前的狀況不佳，無法修煉心法。\n");
if(!me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3))
            return notify_fail("你結束運功\的動作還沒完成。\n");

        if( me->query_skill("moon_force") < 85 )
            return notify_fail("你的殘月心法根本還不用自己修煉, 去找老師學吧.\n");
        message_vision(HIC"$N隨地盤腳坐下，氣運百骸，聚檀中而養息。\n"NOR,me);

        me->map_skill("force","moon_force");
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2);
        me->set_temp("is_busy/moon_force","你正在膳養內息，暫時不能移動。");
        me->start_busy(2);
me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me:), 2);
        return 1;
    }

    if( arg=="recover" )
    {
        if( me->query("ap") < 20 )
            return notify_fail("你目前的狀況不佳，無法使用殘月心法。\n");
        if( me->query_skill("moon_force") < 10 )
            return notify_fail("你的殘月心法基礎不夠！\n");
        heal= (int)me->query("max_hp");
        if( me->query("hp") >= heal )
            return notify_fail("你目前的生命狀況已經是極限了。\n");
        if(heal>4000) heal = 4000 + ((heal-4000)/8);
        sk = (int)me->query_skill("moon_force");
        lv = (int)me->query("level");
        if ( sk > 50 ) sk = 50 + ((sk-50)/2);
        reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);
        me->receive_heal("hp",reheal);
        me->receive_damage("ap",27 + reheal/7 + random(4));
        me->start_busy(2);
        message_vision(HIR"$N一時間靜下心來，運氣點了身上各傷口旁的大穴。\n"NOR,me);
        return 1;
    }



    // 引用疾風評比　牽制 5 -- 「弧月」
    // By Tmr
    // Edition By Cominging

    if( arg=="powerin" )
    {
        max = (me->query_con() / 4) + 10;
        sk = me->query_skill("moon_force") / 10;
        if( me->query_skill("moon_force") < 50 )
            return notify_fail("你的殘月心法還不夠熟練。\n");
        if( me->query("ap") < 150 )
            return notify_fail("你的內力不足，無法將內力貫於臂上。\n");
        if( me->query_str() < 20 )
            return notify_fail("你的膂力不足以承聚功\力。");
        if( me->query_temp("class_wind/power") >= max )
            return notify_fail("你的手臂已經無法再承受更大的壓力了。\n");

        message_vision(HIW"$N手臂微微顫動，顯然凝聚了一股功\力在手臂上！！\n" NOR,me);

        if( me->is_fighting() )
        {
            if( me->query_temp("class_wind/power") + sk > max ) {
                me->add_temp("class_wind/power", max - me->query_temp("class_wind/power") );
                me->receive_damage("ap",(max - me->query_temp("class_wind/power"))*10);
            }
            else {
                me->add_temp("class_wind/power", sk );
                me->receive_damage("ap",sk*10);
            }
            me->start_busy(2);
        }
        else
        {
            if( me->query_temp("class_wind/power") + sk > max ) {
                me->add_temp("class_wind/power", max - me->query_temp("class_wind/power") );
                me->receive_damage("ap",(max - me->query_temp("class_wind/power"))*10);
            }
            else {
                me->add_temp("class_wind/power", sk );
                me->receive_damage("ap",sk*10);
            }
            me->start_busy(1);
        }
        return 1;
    }

    if( arg=="moon-arc" )
    {
        if( !me->is_fighting() )
            return notify_fail("你並沒有在戰鬥中。\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("你要對誰使用「弧月」？\n");
        p=me->query_temp("class_wind/power");
        weapon=target->query_temp("weapon");

        if(!weapon)
            return notify_fail("敵方並沒有拿武器，「弧月」無法發揮效用。\n");
        if( p < 3 )
            return notify_fail("你覺得手臂酸軟無力，無法揮出「弧月」。\n");
        if(me->query("hp") < 50)
            return notify_fail("你的身體狀況不好。\n");

        message_vision("\n$N雙手一合一分，隨空虛劃凝出一片「弧月」。\n"
                       HIY "弧月似有生命一般，以快捷無倫的疾速攻向$n拿武器的雙手！！\n" NOR,me,target);

        me->add_temp("class_wind/power",-3);
        me->receive_damage("hp",30);
        me->start_busy(2);
me->skill_active( "moon_force",(: call_other, __FILE__, "arc", me,target:), 2+random(1) );
        return 1;
    }

    else return notify_fail("殘月心法沒有這種功\能！\n");

}

void arc(object me,object target)
{
    object wp;
    string type;
    int t,m;
    if(!me || !target ) return;

    wp=target->query_temp("weapon");
    if( !wp )
    {
        message_vision("「弧月」凌空轉了數圈，化成一陣輕煙消失了。",me);
        return;
    }
    type = wp->query("skill_type");
    t=target->query_skill(type)+target->query_str()+(wp->query_temp("durable")/25);
    m=me->query_skill("dodge")+me->query_str()+(me->query_skill("moon_force")/3);
    if( random(t) < random(m) && wp->unequip() )
    {
        message_vision(HIC "「鏘」地一聲響，弧月撞得$N脫落了手中的武器！！\n" NOR ,target);
        target->start_busy(1);
    }
    else message_vision(CYN "「鏘」地一聲響，弧月一撞上$N手中的武器反而被震碎了！！\n" NOR,target);
    return;
}

void delay(object me)
{
    int sk_level,lv,i;

    sk_level = me->query_skill("moon_force");
    lv = me->query("level");
    i = me->query_int();

    if( !me ) return;

    if( me->query_skill_mapped("force")!="moon_force" )return;

    if( me->query("ap") < 13 || me->query("hp") < 13 )
    {
        message_vision(HIR"$N心神如一道光劃過，瞿然停止了運功\。\n"NOR,me);
        me->delete_temp("is_busy/moon_force");
        me->map_skill("force");
        return;
    }
    else
        if ( sk_level < 50 )
        {
            me->receive_damage("ap",8);
            me->receive_damage("hp",5);
        }
        else
            if ( sk_level > 49 )
            {
                me->receive_damage("ap",12);
                me->receive_damage("hp",7);
            }
    me->improve_skill("force",1+random(5+lv/2)+(i/3) );
    me->improve_skill("moon_force",1+random(5+lv/2)+(i/3) );
me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me) // 注意, 一個skill能增加的屬性總和以 5 為上限
{
    int b,c;
    b = me->query_skill("moon_force",1);
    c = me->query("skill/moon_force"); //luky

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me, HIR "你的動作由於領悟殘月心法有道而更加輕盈了。\n" NOR);
            me->add("addition/dex", 1);
        }
        else
        {
            tell_object(me, HIR "你的體質由於領悟殘月心法有道而增強了。\n" NOR);
            me->add("addition/con", 1);
        }
        me->set("skill/moon_force",b);
    }
    me->save();
}

int improve_limite(object ob)
{
    int a;
    a=(ob->query("level")*3)+(ob->query_int()/2);
    if( a > 90 && ob->query("level") < 26 ) a=100;
    else if( a>100) a =120;
    return a;
}
