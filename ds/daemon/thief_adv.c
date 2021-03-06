// 現代公會職業信物核心 (小偷公會-Thief)
// 編寫者: Luky 1999.9.5
//
// 小偷公會_進階版 -Tmr 2002/04/04

/*   特殊功能
 * 一、背刺連擊技巧： 在背刺成功後，有可能多1~2 回合的攻擊
 * 
 * 二、偷竊：可 強奪 對方已裝備的武器、防具 //不開放
 */
#include <weapon.h>
#include <combat.h>
#include <ansi.h>

void create()
{
        seteuid(getuid());
}

void show_damage(object me,object target,int damage)
{
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
}

int do_help(object me,string arg)
{
 if(arg=="advanced thief")
 {
  tell_object(me,@HELP

        指令                    說明
        ==================      ===============================================
        help advance thief      本說明文件。

        stillhunt <id>          由背後偷襲名為<id>的怪物或玩家，先決條件是
                                對方不注意你，或看不到你。當偷襲成功時，有
                                機會趁對方身心受損的情況下，達到多次攻擊。


        Edit By Tmr 2002/04/04
HELP
  );
  return 1;
 }
 return 0;
}

/* 進階背刺：Stillhunt */
int do_backstab(object me,string arg)
{
        object target,weapon;
        int sk,cost;

        if(!me) return 0;
        if(!arg) return notify_fail("你要偷刺誰﹖\n");
        sk=me->query_skill("backstab");
        cost=5+sk/3;
        if(!weapon=me->query_temp("weapon"))
                return notify_fail("你沒有拿武器如何背刺?\n");
        if(!weapon->can_stab() )
                 return notify_fail(weapon->name()+"並不適合用來背刺。\n");
        if(me->is_busy() || me->is_block())
                return notify_fail("你的上一個動作還沒完成。\n");
        if( me->is_fighting() )
                 return notify_fail("你正在戰鬥沒空背刺。\n");
        if(sk<1)
                 return notify_fail("你的還沒學過背刺。\n");
        if((int)me->query("ap")< cost || (int)me->query("mp")< cost/2 )
                return notify_fail("你的精神體力不佳，無法背刺。\n");
        target = present(arg, environment(me));
        if(!target) 
                return notify_fail("你要偷刺誰﹖\n");
        if(!living(target) )
                return notify_fail("看清楚一點, 那並不是活的.\n");
        if(!me->can_fight(target))
                return me->can_fight(target);
        if(target->visible(me))
                return notify_fail("對方正注視著你，你沒有機會背刺。\n");
        /* 進階背刺要求較高的邪惡值 */
        if(me->query("evil")< -200)
                return notify_fail("你太善良了，不忍心下手。\n");
        
        if(random(target->query_dex()/4+target->query_skill("perception")/3)
                > random(sk/2+me->query_dex()/3+me->query_temp("hide")*4)
        )
        {
                me->delete_temp("hide");
                message_vision(HIW"$N"HIW"想從背後偷襲$n"HIW"，但是卻被$n"HIW"發現了！！\n"NOR,me,target);
                me->improve_skill("backstab",2+random(2+me->query_int()/10));
                target->kill_ob(me);
                if(me->query_skill("free_action")>69) me->add_busy(1); //技能 free_action 用來減少忙碌時間
                if(me->query_skill("free_action")>39) me->add_busy(2); //技能 free_action 用來減少忙碌時間
                else me->add_busy(3);
                return 1;
        }
        tell_object(me,CYN "你緊握"+weapon->name()+CYN"，小心翼翼地向"+target->name()+CYN"的背後接近...\n\n"NOR);
        me->receive_damage("mp",cost/2);
        me->receive_damage("ap",cost);
          me->add_busy(2);
        call_out("bs",3+random(2),me,target);
        return 1;
}


void bs(object me,object target)
{
        int damage,exp,sk,c;
        object weapon;
        if(!me || !target) return;
        if(!weapon=me->query_temp("weapon"))
        {
                tell_object(me,"你臨時卸下武器，放棄了這次的行動。\n");
                 return;
        } else if(!weapon->can_stab())
                {
                        tell_object(me,"你不小心拿錯了武器，放棄了這次的行動。\n");
                        return;
                }
        
        if(environment(me) != environment(target) || !me->visible(target))
        {
                tell_object(me,"你放棄了這次的行動。\n");
                return;
        }
        me->delete_temp("hide");
        sk=me->query_skill("backstab");
        c=target->query_armor();
        /* 背刺成功的傷害力計算 */
        damage=me->query_damage()*3+sk;
        /* 武器的背刺加乘效果 */
        if(weapon->query("backstab_bonus")!=0)
                damage=damage*(100+weapon->query("backstab_bonus"))/100;
        damage=damage/2+random(damage/2);
        damage=damage-c/5-random(c/2);
        if(damage<20)
                damage=20+random(10);
        damage += damage*(me->query("evil")/700);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        /*　由背刺的威力來決定取得 經驗值 的數量*/
        exp=damage/2+random(damage/4);
        /*
        if(damage>200)
                msg=RED"$n"RED"慘叫一聲!! 身上還發出一聲『喀!!』似乎是骨頭碎裂的聲音。"NOR;
        else if(damage > 130)
                msg=HIR"$n"HIR"一聲哀嚎!! 傷口深可見骨。"NOR;
        else if(damage > 60)
                msg=HIM"$n"HIM"大叫一聲!! 鮮血濺了一地。"NOR;
        else    msg=HIM"痛的$n"HIM"哇哇大叫，幾乎快要昏死過去。"NOR;
        */
        /* 進階背刺的威力-多次背刺*/
        message_vision(HIY"\n$N"HIY"突然出現在$n"HIY"的身後，舉起"+weapon->name()+HIY"用力的往$n"HIY"背上刺了下去!!"NOR,me,target);
        /* 顯示背刺過程中的 訊息*/
        //message_vision("\n"+msg+"\n",me,target);
        target->receive_damage("hp",damage,me);
        show_damage(me,target,damage);
        message_vision("\n",me);
        //if(target->query("hp") > 0)
                COMBAT_D->report_status(target);
        /* 連續背刺 */
        if( sk > 60 )
        {
                message_vision(HIY"$N"HIY"偷襲成功\，趁著$n"HIY"身心受損下，又猛刺一下！！"NOR,me,target);
                damage=damage/3+random(damage/3);
                show_damage(me,target,damage);
                target->receive_damage("hp",damage,me);
                message_vision("\n",me);
                //if(target->query("hp") > 0)
                        COMBAT_D->report_status(target);
                if( sk > 70 )
                {
                message_vision(HIR"$N"HIR"趁勢翻絞還在$n"HIR"體內的"
                        +weapon->name() +HIR"，結果造成更大的肉體傷害。\n"NOR,me,target);
                target->receive_wound("body",1+random(2));
                }
                if( sk > 80 )
                {
                        me->kill_ob(target);
                        me->attack();
                }
                if( sk > 90 )
                {
                        me->attack();
                }
        }

        tell_object(me,HIG"\n(你的這次行動得到了"+exp+"點經驗值。)\n"NOR);
        me->add("exp",exp);
        me->improve_skill("backstab",2+random(me->query_int()/2+me->query("level")/2));
        if(target->query("hp") > 0) target->kill_ob(me);
        return;
}

