/********追雲流步(Run_cloud)       Update By Kkeenn*******/
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         "$n低聲說道：【水影虛涵一鏡中】，晃身閃開了$N的招式。\n",
                         "$n高聲唱出：【晴光搖蕩暖雲紅】，躲過了$N的攻擊。\n",
                         "$n以舞姿跳出【小桃花重初經兩】，離開了$N的攻擊範圍。\n",
                         "$n腳下一動一招【弱柳絲柔屢舞風】，閃開了$N的攻勢。\n",
                         "$n一個拔身一招【旱雲飛火燎長空】，飛身躲過了$N的威脅。\n",
                         "$n運起全身功\力以一招【白日渾如坐罈中】，硬生生的將$N的攻擊凝住。\n",
                         "$n雙手同使出一招【不到廣寒冰雪窟】，架開了$N的攻勢。\n",
                         "$n一聲嬌笑【扇頭能有幾多風】，斜裡躍出了$N的正前方。\n",
                     });
string *adv_dodge_msg = ({
                             "$n低聲說道：【水影虛涵一鏡中】，晃身閃開了$N的招式。\n",
                             "$n高聲唱出：【晴光搖蕩暖雲紅】，躲過了$N的攻擊。\n",
                             "$n以舞姿跳出【小桃花重初經兩】，離開了$N的攻擊範圍。\n",
                             "$n腳下一動一招【弱柳絲柔屢舞風】，閃開了$N的攻勢。\n",
                             "$n一個拔身一招【旱雲飛火燎長空】，飛身躲過了$N的威脅。\n",
                             "$n運起全身功\力以一招【白日渾如坐罈中】，硬生生的將$N的攻擊凝住。\n",
                             "$n雙手同使出一招【不到廣寒冰雪窟】，架開了$N的攻勢。\n",
                             "$n一聲嬌笑【扇頭能有幾多風】，斜裡躍出了$N的正前方。\n",
                             "$n低聲說道：【新秋涼露濕荷叢】，晃身閃開了$N的招式。\n",
                             "$n高聲唱出：【不斷清香足曉風】，躲過了$N的攻擊。\n",
                             "$n以舞姿跳出【滿目濃華春意在】，離開了$N的攻擊範圍。\n",
                             "$n腳下一動一招【晚霞澄錦照芙蓉】，閃開了$N的攻勢。\n",
                             "$n一個拔身一招【寒夜客來茶當酒】，飛身躲過了$N的威脅。\n",
                             "$n運起全身功\力以一招【竹爐湯沸火初紅】，硬生生的將$N的攻擊凝住。\n",
                             "$n雙手同使出一招【尋常一樣窗前月】，架開了$N的攻勢。\n",
                             "$n一聲嬌笑【才有梅花便不同】，斜裡躍出了$N的正前方。\n",
                         });
int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="run_cloud")
            return notify_fail("你並沒有使用追雲流步。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N的腳步慢下來了。\n"NOR,me);
        write("技能[追雲流步]已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<40) return notify_fail("你的縱躍閃避能力還不夠使用追雲流步。\n");
    if(me->query_skill_mapped("dodge")=="run_cloud")
        return notify_fail("你正在使用追雲流步。\n");
    if(me->query("ap")<40 || me->query("hp")<40) return notify_fail("你的身體狀況無法使用追雲流步。\n");
if(!me->skill_active( "ruun_cloud",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("你收起追雲流步的動作還沒完成。\n");

    me->map_skill("dodge", "run_cloud");
    me->reset_action();
    message_vision("\n"HIG"$N施展追雲流步, 好像在一剎間幻出許\多的分身。\n"NOR,me);
    me->add("ap", -20);
    me->start_busy(2);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="run_cloud")
    {
        return;
    }
    if(me->query("ap")<cost+15)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N突然慢了下來。\n"NOR,me);
        tell_object(me,"你的體力不夠使用追雲流步了。\n");
        return ;
    }
    if( me->is_fighting() ) me->receive_damage("ap", cost);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "run_cloud",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {    return 1;       }

string query_dodge_msg(string limb)
{
    if( this_player()->query("class2") == "情城池" )
        return adv_dodge_msg[random(sizeof(adv_dodge_msg))];
    else return dodge_msg[random(sizeof(dodge_msg))];

}
int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
    int a;
    a=ob->query_dex();
    a=60+a;
    return a;
}

