//本有打算要把劍氣還原,想想還是不要好了,這招算強的了
#include <ansi.h>
#define SKILL_NAME "索星奧義"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string arg)
{
    string msg;
    int damage,sk,c;
    object weapon,wp;
    if(!me) return 0;
    //    if(me->is_fighting())
    //    	return notify_fail(SKILL_NAME+"是一種戰鬥技能！[現在功\能有 氣勁劍(exert sorsin-force apsword)]\n");
    if( arg == "apsword" )
    {
        if( me->query_temp("apsword") )
            return notify_fail(""+SKILL_NAME+"一次只能使出一把氣勁劍！\n");
        wp = new("/u/j/jangshow/sword");
        wp->move(me);
        {
            message_vision(HIC"$N運起心法，集四大穴氣於雙掌間，漸漸凝聚成一把"HIW"氣勁劍"HIC"。\n"NOR, me);
            me->start_busy(3);
            me->receive_damage("ap", 100+random(me->query_skill("sorsin-force")/2));
            //基本點為100,sorsin愈高,扣愈多
            me->set_temp("apsword",1);
            call_out("de_apsword",20,me); // 5分鐘
        }
        return 1;
    }
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("你要對誰使出"+SKILL_NAME+"?\n");
    if((int)me->query("mp") < 20 || (int)me->query("ap") < 50)
        return notify_fail("你目前的身體狀況無法使用這麼劇烈的武功\﹗\n");
    if(!weapon=me->query_temp("weapon")) return notify_fail("你手中沒有武器。\n");
    if(weapon->query("skill_type")!="sword")
        return notify_fail("使用"+SKILL_NAME+"必須要有劍。\n");
    if(me->query_skill("sword")<100)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的劍法基礎。\n");
    if(me->query_skill("dodge")<100)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的閃躲基礎。\n");
    if(me->query_skill("sorgi_sword")<100)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的索疾劍法。\n");
    if(me->query_skill("sevenstar-sword")<100)
        return notify_fail("使用"+SKILL_NAME+"須求極為扎實的昂星劍義。\n");
    if(me->query_skill("moon_force")<100)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的殘月心法。\n");
    if(me->query_skill("force")<100)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的內功\心法。\n");
    if(me->query_dex() <60)
        return notify_fail("使用"+SKILL_NAME+"須要極為扎實的敏捷技術 [60]。\n");
    if( me->query_temp("nan") )
        return notify_fail("你短時間內不能使用"+SKILL_NAME+"！\n");
    sk=me->query_skill("sorsin-force");
    c=target->query_armor();
    message_vision("\n"HIW"$N以"HIC"勁"HIW"化氣，以氣禦"HIC"劍"HIW"，橫平於眼前，提起異手持扶於"HIC"氣"HIW"劍•••\n"NOR,me,target);
    me->receive_damage("mp",100);
    me->receive_damage("ap", 300);
    me->add_busy(3);
    if( random(me->query_dex()*4) < random(target->query_dex()+target->query_skill("dodge")))
    {
        message_vision("\n"HIW""+target->name()+"先發制人！抑止了$N的招式。\n"NOR,me,target);
        return 1;
    }
    else
    {
        damage = me->query_damage()*3+sk*10+me->query_dex()*2-c/3;
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        message_vision(HIG"\n\t劍風一起！\n"
                       HIB"\t\t『"HIC"殘月之祕•幻滅疾念"HIB"』\n"
                       HIW"\t\t一股劍氣掃蕩在"+target->name()+"的周圍！四面空氣滋滋作響！\n"
                       HIC"\t\t天疾星陣"HIW"奪劍而出！百道劍氣••由陣導入••\n"
                       HIR"\t\t鮮血哀嚎••"+target->name()+"可見••\n"NOR,me,target);
        target->receive_damage("hp", damage,me);
        target->add_busy(3);
        COMBAT_D->report_status(target);
        if( objectp(wp = me->query_temp("weapon")) ) wp->attack();
        if(wizardp(target) && target->query("env/debug")) tell_object(target,"["+me->name()+"受到: "+damage+"點的傷害]\n");
        me->set_temp("nan",1);
        call_out("stop_delay",60,me); // 一分鐘
    }


    return 1;
}
void de_apsword(object me)
{
    //    object wpp,me;
    //    me=this_player();
    object wpp;
    if( !me) return;
    if( objectp(wpp = present("ap sword", me)) )
    {
        if( (string)wpp->query("equipped")=="wielded" )
        {
            wpp->unequip();
        }
        //   me->delete("ap sword");
        me->destruct(wpp);
        me->delete_temp("apsword");
        message_vision(HIW"\n"+me->name()+"身上的氣勁劍瞬間蒸散！\n"NOR,me);
    }
    return;
}
void stop_delay(object me)
{
    if( !me ) return;
    me->delete_temp("nan");
}
int improve_limite(object ob)
{
    return 100;
}

