// 浪人精神 editor Cominging, sexking 在旁邊喝咖啡打混..@@..
#include <ansi2.h>
inherit SKILL;
void delay(object me, object weapon, int flag);
void delay1(object me);
void end(object me, int x);
string *hara_msg = ({
  NOR HIR"\n\n$N緩緩的提起手中的$n……\n"NOR,
  NOR HIR"$N手臂一彎, 將手中的$n的刀口, 對準著自己……\n"NOR,
  NOR HIR"$N手中的$n一晃, 只見$n已經插在$N的腹上了！！！\n"NOR,
});
int exert(object me, object target, string arg)
{
        int minus_hp = me->query("hp")/10*5,
        minus_ap = me->query("ap") / 10*2,
        sk = me->query_skill("hara_kiri"),
        max_hp = me->query("max_hp"),
        max_ap = me->query("max_ap"),
        damage = me->query_damage(), x;
        object weapon;
        if( !objectp(weapon=me->query_temp("weapon")) )
                return notify_fail("你沒有刀, 要怎麼切腹呢？\n");
        if( weapon->query("skill_type") != "blade" )
                return notify_fail("你只能用刀切腹喔！\n");
        if( me->query("max_hp") < 200 )
                return notify_fail("你的身體不夠好, 等以後再說吧！\n");
        if( me->query("hp") < (minus_hp+10) )
                return notify_fail("你的身體狀況不佳, 無法切腹.\n");
        if( me->query("ap") < (minus_ap+20) )
                return notify_fail("你似乎沒有什麼體力來切腹了∼！\n");
        if( me->is_busy() )
                return notify_fail("你似乎在忙喔！\n");
        if( me->is_fighting() )
                return notify_fail("你在戰鬥中, 可能無法來切腹吧？\n");
        if( me->query_bar() < 1) 
                return notify_fail("你太膽小..不敢做這種切自己腹部的事。\n");
        x = (int)(sk*minus_hp/(200-(sk/2)))/30*(sk/15)+random(minus_ap/50+me->query_bar());
        if( x > 80 ) x = 80+random(4);
        if( x < 1 ) x = 1+random(3);
        me->add_temp("apply/damage", x);
        if( me->query_armor() < (max_hp/(30+(sk/10))+x) )
        {
                me->set_temp("skills/hara_kiri_armor", me->query_armor());
                me->add_temp("apply/armor", -(me->query_armor()));
        }
        else
        {
                me->set_temp("skills/hara_kiri_armor", max_hp/(30+(sk/10))+x);
                me->add_temp("apply/armor", -(max_hp/(30+(sk/10))+x) );
        }
        me->start_busy(4); //add by sexking @_@ cominging 好狠設成6ㄛ..戰鬥用會死的很難看的說
        me->receive_damage("ap", minus_ap, COMBAT_D);
        me->receive_damage("hp", minus_hp, COMBAT_D);
        call_out("delay", 1, me, weapon, 0);
        call_out("end",20, me, x);
        return 1;
}
void delay(object me, object weapon, int flag)
{
        if( !me ) return;
        switch(flag)
        {
                case 0:
                case 1:
                case 2:
                        message_vision(hara_msg[flag] , me, weapon);
                        call_out("delay", 1, me, weapon, flag+1);
                        break;
                case 3:
                        tell_object(me, NOR HIR"... 你突然感覺到一陣痛楚.."NOR);
                        me->set_temp("block_msg", 1);
                        call_out("delay1", 0, me);
                        call_out("delay", 2, me, weapon, 4);
                        break;
                case 4:
                        me->delete_temp("block_msg", 1);
                        tell_object(me, HIR"....\n\n");
                        message_vision(HIG"由於$N貢獻了鮮血, 使得$N身上的血液沸騰, 攻擊力增加了不少！！！\n"NOR, me);
                        break;;
                default:
                        tell_object(me, BEEP HIR"[error]: 傳入錯誤,請通知巫師修正.\n");
                        break;
        }
        return;
}
void delay1(object me)
{
        if( !me ) return;
        tell_object(me, HIR"....");
}

void end(object me, int x)
{
        if( !me ) return;
        me->add_temp("apply/damage", -x);
        me->add_temp("apply/armor", me->query_temp("skills/hara_kiri_armor"));
        me->delete_temp("skills/hara_kiri_armor");
        message_vision(HIY"$N隨著時間的流逝, 激烈的情緒漸漸緩和了下來....\n"NOR, me);
        return;
}
int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }

