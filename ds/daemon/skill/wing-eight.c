// create by whoami 2006/12
// QC by tmr 2007/01/05
// skyowl 輕功不需要有特攻

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
                         HIR"突然$n血紅的雙眼放出殺氣，像老鷹一般，嚇的$N不敢靠近$n。\n"NOR,
                         "\n$n突然像背後插了雙翅膀一樣的活動迅速，讓$N無從攻擊起。\n",
                         "\n$n突然像鴕鳥般的急衝起來，讓$N出手的時間大亂，因此避過此招。\n",
                         "\n$n閉上雙眼，腦中想著踩石樁陣的情形，腳也踩起石樁陣式，讓$N無從下手。\n",
                         "\n$n雙腳一蹬，直衝上天，一式"+HIC+"【驚弓之鳥】"+NOR+"漂亮的落在$N身後。\n",
                         "\n突然$n腳步變輕，一招"+HIM+"【返樸歸真】"+NOR+"，在$N的攻勢中遊走四方。\n",
                         "\n突然$n放慢了腳步，忽進忽退，使$N完全摸不著頭腦。\n",
                         "\n煞那間，$n的雙眼發出異樣的光芒，動作比平常要快上數倍，使$N完全碰不到$n一根寒毛。\n",
                     });

int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="wing-eight")
            return notify_fail("你並沒有使用『靈翼八步訣』。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision( CYN"$N的眼睛慢慢轉為平常的顏色，而原本輕盈的腳步也逐漸趨緩。\n"NOR,me);
        write("技能『靈翼八步訣』已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("以你的輕功\基礎無法使用『靈翼八步訣』。\n");
    if(me->query_skill_mapped("dodge")=="wing-eight")
        return notify_fail("你已經在使用『靈翼八步訣』。\n");
    if(me->query("ap")<50 || me->query("hp")<50)
        return notify_fail("你的身體狀無法使用『靈翼八步訣』。\n");
        if(!me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("你的『靈翼八步訣』收招動作還沒完成。\n");

    message_vision(HIR"$N的雙眼突然轉為血紅色，捕捉敵人的一舉一動，使出傳說中的『靈翼八步訣』。\n"NOR,me);

    me->map_skill("dodge", "wing-eight");
    me->reset_action();
    me->receive_damage("mp",3);
    me->receive_damage("ap",3);
    me->start_busy(1);
        me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10);
    return 1;
}

void delay(object me)
{
    if(!me)
        return;

    if(me->query_skill_mapped("dodge")!="wing-eight")
        return;

    if(me->query("ap")<50)  {
        me->map_skill("dodge");
        me->reset_action();
        message_vision( "$N的眼光漸漸恢復為正常顏色，而原本輕盈的腳步也逐漸趨緩。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用『靈翼八步訣』。\n");
        return ;
    }
        me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb, object me, object target)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object me)
{
    int a = me->query_dex() + me->query_int();
    if(a>100)
        a=100;
    return a;
}



