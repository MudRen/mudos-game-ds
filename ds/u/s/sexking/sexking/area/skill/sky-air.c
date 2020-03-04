// 天之怒氣(Sky-air) by cominging and sexking
#include <ansi2.h>
inherit SKILL;
void delay(object me, object weapon, int flag);
void delay1(object me);
void end(object me, int x);
string *hara_msg = ({
  HIR"\n\n$N將$n插入地面,閉上雙眼,雙手握拳,準備爆發"HIC"[天之怒氣]"HIR"！！！\n\n"NOR,
  HIR"\n\n$N看起來痛苦萬分,兩眼發紅,長嘶怒吼著,似乎已快被怒氣吞噬\n\n"NOR,
  HIR"\n\n漸漸的$N睜開雙眼,此時身上已包覆著藍色的氣燄-"HIC"[天之怒氣]"HIR"！！！\n\n"NOR,
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
                return notify_fail("你得準備一把刀才能引發出天之怒氣\n");
        if( weapon->query("skill_type") != "blade" )
                return notify_fail("只有手中有刀才能引發出天之怒氣\n");
        if( me->is_busy() )
                return notify_fail("你正在忙！\n");
        if( me->query_bar() < 1) 
                return notify_fail("你獸性不足,無法使出天之怒氣。\n");
        if(me->query_temp("cccc")==1) return notify_fail("你已經受到"HIC"天之怒氣"HIR"之包覆了。\n");
        
        x = (int)(sk*minus_hp/(200-(sk/2)))/30*(sk/15)+random(minus_ap/50+me->query_bar());
        if( x > 80 ) x = 80+random(4);
        if( x < 1 ) x = 1+random(3);
        me->add_temp("apply/damage", x);
        me->add_temp("cccc",1);
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
        me->start_busy(5); //add by sexking @_@ cominging 
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
                        tell_object(me, NOR HIR"... 你感覺體內沸騰..力量已增強了不少.."NOR);
                        me->set_temp("block_msg", 1);
                        call_out("delay1", 0, me);
                        call_out("delay", 2, me, weapon, 4);
                        break;
                case 4:
                        me->delete_temp("block_msg", 1);
                        tell_object(me, HIR"....\n\n");
                        message_vision(HIR"$N受到了"HIC"天之怒氣"HIR"的包覆..攻擊力大大的增加！！！\n"NOR, me);
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
        me->add_temp("cccc",-1);
        me->delete_temp("skills/hara_kiri_armor");
        message_vision(HIY"隨著時間的流逝, $N的"HIC"天之怒氣"HIY"之藍色氣燄也漸漸釋去....\n"NOR, me);
        return;
}
int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
