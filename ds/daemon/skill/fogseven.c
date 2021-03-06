// 更新日期: 2003.06.15	修改人: Shengsan@DS 修改代號: sV1 -->修改 fogseven + dodge 所佔的比例
// fogseven.c 迷幻七步訣 ( editor date 忘了 )
// update time: 10, Sept., 2000.
// last update: 11, Sept., 2000. --> 恢復 fogseven + dodge
#include <ansi.h>
inherit SKILL;

void remove_add_dodge(object me);

string *dodge_msg = ({
                         HIM"$n隨地走了一走，竟然把$N的攻擊視若無睹的閃了過去。\n"NOR,
                         HIM"$n用腳跟壓了一下腳尖，大叫了一聲哇，接著就消失在$N眼前。\n"NOR,
                         HIM"$n微微聽見$N的武器攻來，瞬間就馬上就躲了起來。\n"NOR,
                         HIM"$N一攻向$n，結果$n從背後拿出一把鐵鏟，接著就往地上挖洞逃走了。\n"NOR,
                         HIM"$n旁邊突然衝出一堆人，把$n給搶走了。\n"NOR,
                         HIM"$n內力一提，閉目使心眼看，把$N的攻擊都給躲了起來。\n"NOR,
                         HIM"$n輕如神靈一般，輕鬆的躲過了$N的攻擊。\n"NOR,
                         HIR"$n突然使出一幻玉兔閃輕爾一舉閃過敵人的猛烈攻擊\n"NOR,
                         HIR"$n突然使出二幻閃靈訣輕飄飄的閃過敵人的重攻擊。\n"NOR,
                         HIR"$n精氣一提使出三幻蝴蝶飄隨著敵人的攻擊使攻擊之力化於二旁不受創傷。\n"NOR,
                         HIR"$n凝聚身上之力, 使出四幻軟骨功\軟綿綿的消去敵人的攻擊,吸其力做為己力,閃過此擊。\n"NOR,
                         HIR"$n精氣再提,使出五幻遁地使得敵人一時不知所措,趁此避過一擊。\n"NOR,
                         HIR"$n氣神已足,凝聚氣神,使出六幻摧眠術使得敵人當時腦中一時混沌,避開此擊。\n"NOR,
                         HIR"$n凝聚精氣神,使出迷幻七步訣最上層幻影步訣,突然幻影數十,使得敵人胡亂攻擊,逃過此擊。\n"NOR,
                     });

string *dodge_msg_high = ({
                              HIB"$n腳踩八卦五行之方位，對$N置之不理。\n"NOR,
                              HIB"$n一腳踩上八卦上之無妄位，如倒轉般的逆走。\n"NOR,
                              HIB"$n卻自走自的，無料卻躲過了$N的攻擊。\n"NOR,
                              HIB"$n口中喃喃念道：無妄天罣....，隨著口中念出而走。\n"NOR,
                              HIB"$n兩腳跨下腋，如是依照易筋經上般的躲避。\n"NOR,
                              HIR"$n凝聚精氣神,使出迷幻七步訣最上層幻影步訣,突然幻影數十,使得敵人胡亂攻擊,逃過此擊。\n"NOR,
                          });

int exert(object me, object target, string arg)
{
    int tmp;

    if ( arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="fogseven")
            return notify_fail("你並沒有使用迷幻七步訣。\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N又恢復回原來的速度了。\n"NOR,me);
        remove_add_dodge(me);
        write("取消使用技能 - 閃避之技迷幻七步訣。\n");
        return 1;
    }

    if( me->query_skill("dodge") < 5 )
        return notify_fail("你的輕功\基礎不夠無法使用迷幻七步訣。\n");

if( !me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12) )
        return notify_fail("你正在使用迷幻七步訣。\n");

    if( me->query("ap") < 10 )
        return notify_fail("你的身體目前狀況還無法使用迷幻七步訣。\n");

    me->map_skill("dodge","fogseven");
    me->reset_action();

    message_vision("\n"HIB"一聲重重的喘息聲，$N把四骸之氣集壇中，心意會神，用心去體會迷幻七步訣的真義。\n"NOR,me);
    me->receive_damage("ap", 1);
    me->start_busy(1);
    if( me->query_temp("class_wind/fogseven_dodge") )
        remove_add_dodge(me);
    //sV1 me->add_temp("apply/sk_dodge", (tmp = me->query_skill("fogseven", 1)*2/5 + me->query_skill("dodge", 1)/5 + random(me->query_skill("dodge",1)/4)));
    me->add_temp("apply/sk_dodge", (tmp = me->query_skill("fogseven", 1)*2/5 + random(me->query_skill("dodge",1)/10)));//sV1
    me->set_temp("class_wind/fogseven_dodge", tmp);
    //	me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12);
    return 1;
}

void delay(object me)
{
    if( !me ) return;

    if( me->query_skill_mapped("dodge")!="fogseven" )
    {
        remove_call_out("delay");
        remove_add_dodge(me);
        return;
    }

    if( me->query("ap")<10 )
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N又回復到了一般的速度。\n"NOR,me);
        tell_object(me,"你的內息已亂，已無法再使用迷幻七步訣。\n");
        remove_add_dodge(me);
        remove_call_out("delay");
        return ;
    }

    if( me->is_fighting()  )
    {
        if( (me->query_skill("fogseven") + me->query_skill("dodge") - 30) > 1 ) me->receive_damage("ap", 1);
        else me->receive_damage("ap", 2);
    }
me->skill_active("fogseven",(: call_other, __FILE__, "delay", me :), 10);
}

void remove_add_dodge(object me)
{
    int ar1 = (int)me->query_temp("class_wind/fogseven_dodge");

    if( ar1 < 0 ) return;
    me->add_temp("apply/sk_dodge", -ar1);

    me->delete_temp("class_wind/fogseven_dodge");
    return;
}

string query_dodge_msg(string limb)
{
    if( this_player()->query_skill("fogseven") == 100 )
        return dodge_msg[random(sizeof(dodge_msg))];
    else return dodge_msg_high[random(sizeof(dodge_msg_high))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob) { return 100; }
int valid_learn(object me) { return 1; }
