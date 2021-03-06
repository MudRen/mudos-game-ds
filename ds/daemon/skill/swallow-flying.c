#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "\n但是$n身形飄忽，輕輕一縱，一招"GRN"「乳燕投林」"NOR"，舉重若輕的避開這一擊。\n",
        "\n$n身隨意轉，一式"GRN"「雪花飛舞」"NOR"，倏地往一旁飄開數尺，避過了這一招。\n",
        "\n可是$n側身一讓，使出"GRN"「柳絮輕飄」"NOR"，$N這一招撲了個空。\n",
        "\n卻見$n足不點地，一招"GRN"「騰雲駕霧」"NOR"，身形滴溜溜一轉，往旁閃開數尺，躲了開去。\n",
        "\n$n左腳一點右腳背，身形往上一拔，一招"GRN"「一鶴衝天」"NOR"，輕輕巧巧地避開了這一招。\n",
                     });

int exert(object me, object target, string arg)
{
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="swallow-flying")
            return notify_fail("你並沒有使用【飛燕迴翔】。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N身形滯慢下來了。\n"NOR,me);
        write("技能【飛燕迴翔】已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<10) return notify_fail("你的輕功\基礎不夠(10級)無法使用【飛燕迴翔】。\n");
    if(me->query_skill_mapped("dodge")=="swallow-flying")
        return notify_fail("你已經在使用【飛燕迴翔】。\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你目前的身體狀況無法使用【飛燕迴翔】。\n");

if(!me->skill_active( "swallow-flying",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("你的飛燕迴翔收招動作還沒完成。\n");

    me->map_skill("dodge", "swallow-flying");
    me->reset_action();

    message_vision("\n"HIW"$N身影迷離，開始施展【飛燕迴翔】，令人捉摸不定。\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!="swallow-flying")
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N身形滯慢下來了。\n"NOR,me);
        tell_object(me,"你的體力不足無法繼續使用【飛燕迴翔】。\n");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
        me->skill_active( "swallow-flying",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
        int lv = ob->query_dex() + ob->query_int();
        return (lv < 90 ) ? 90 : 100;

}

