//cloudmove.c
// QC: Luky
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         "$n瞬間身影模糊，一招"HIC"「迷雲幻霧」"NOR"就讓$N撲了個空。\n",
                         "$N忽覺眼前一片幻影，無法進攻，原來這是$n的"HIC"「雲影如形」"NOR"。\n",
                         "$n腳步一換，瞬間使出"HIC"「神移虛雲」"NOR"讓$N的攻招落空。\n",
                         "$n站定不動，用出一式"HIC"「身形如雲」"NOR"，雖被$N擊中但$n卻完好無缺！\n",
                         "$n元神歸一，身形後移，一式"HIC"「濃雲密佈」"NOR"將$N的攻擊悉數卸開。\n",
                     });
int exert(object me, object target, string arg)
{
    string msg;
    int speed,b;
    speed = (int)me->query_skill("dodge");
    speed = speed/13;
    b=(int)me->query_temp("skill/ghostspeed");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="cloudmove")
            return notify_fail("你並沒有運行縱雲五行功\。\n");
        if( me->query_temp("ghostmove")==1 )
            return notify_fail("請你先停止運行凌雲鬼影。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIC"$N腳步放慢，停止運行縱雲五行功\。\n"NOR,me);
        return 1;
    }
    if(arg=="ghostmove")
    {
        if( me->query_skill_mapped("dodge")!="cloudmove")
            return notify_fail("你並沒有運行縱雲五行功\。\n");
        if( me->query_temp("ghostmove")==1 )
            return notify_fail("你已經使出凌雲鬼影這項特技了。\n");
        if( me->query_skill("dodge") < 90 || me->query_skill("cloudmove") < 80 )
            return notify_fail("你的能力還不夠使用凌雲鬼影。\n");
        if( me->query("ap") < 500 )
            return notify_fail("你的體力已經不夠使用凌雲鬼影了。\n");
        message_vision(HIM"\n$N勁凝腳盤，全身浮移，行運起凌雲鬼影絕技。\n"NOR,me);
        me->set_temp("skill/ghostmove",1);
        me->set_temp("skill/ghostspeed",speed);
        me->add("ap",-400);
        me->start_busy(2);
        me->add_temp("apply/dex",speed);
        return 1;
    }
    if(arg=="off_ghostmove")
    {

        if( me->query_temp("skill/ghostmove")!=1 )
            return notify_fail("你並沒有在使用凌雲鬼影。\n");
        message_vision(HIM"\n$N散去腳下之氣，穩住身形，停止運行了凌雲鬼影。\n"NOR,me);
        me->delete_temp("skill/ghostmove");
        me->delete_temp("skill/ghostspeed");
        me->start_busy(2);
        me->add_temp("apply/dex",-(b));
        return 1;
    }
    if(me->query_skill("dodge")<70) return notify_fail("你的縱躍之術還太差。\n");
    if(me->query_skill_mapped("dodge")=="cloudmove")
        return notify_fail("你已經運行縱雲五行功\了。\n");
    if(me->query("ap")<100 || me->query("hp")<20) return notify_fail("你的體力已經不夠了。\n");
if(!me->skill_active( "cloudmove",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你還在運行縱雲五行功\喔。\n");
    me->map_skill("dodge","cloudmove");
    me->reset_action();
    message_vision(HIY"$N腳勁一抖，身形一飄，開始運起縱雲五行功\。\n"NOR,me);
    me->add("ap", -4);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    int a;
    a=(int)me->query_temp("skill/ghostspeed");
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="cloudmove")
    {
        me->delete_temp("skill/ghostmove");
        me->delete_temp("skill/ghostspeed");
        me->add_temp("apply/dex",-(a));
        return;
    }
    if(me->query("ap")<50)
    {
        me->map_skill("dodge");
        me->reset_action();
        me->delete_temp("skill/ghostmove");
        me->delete_temp("skill/ghostspeed");
        me->add_temp("apply/dex",-(a));
        message_vision("\n"CYN"$N身形突然減慢，凌雲鬼影停止運行了。\n"NOR,me);
        message_vision("\n"HIB"$N腳力一洩，身形歸位，沒辦法再運行縱雲五行功\了。\n"NOR,me);
        tell_object(me,"你的體力已經不夠了。\n");
        return;
    }
    me->add("ap",-3);
me->skill_active( "cloudmove",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
    int a,b;
    a=ob->query_int();
    b=ob->query_dex();
    a=a+b+30;
    if(a>80) a = 80;
    else if(ob->query("adv_class")==2) return 90; //進階後可練到 90
    else return a;                                //否則是 80 以下
}
