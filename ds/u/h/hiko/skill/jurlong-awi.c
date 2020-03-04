#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void ccc(object me,object target,int z,int damage);
mapping *action = ({
([
        "action":"$N忽然身形一停使出「"HIC"狂浪滔天"NOR"」，攻勢有如狂濤浪擊般橫過$n眼前"NOR,
        "damage":    30,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "擊傷"
]),
([
        "action":"$N一時攻勢凌厲使出「"HIC"駭浪覆頂"NOR"」，手中$w不停進擊如駭浪般使$n
無法招架"NOR,
        "damage": 30,
        "parry" : 5,
        "attact_type":  "bar",
        "damage_type":  "擊傷"
]),
([
        "action":"$N手中招式忽然錯亂使出「"HIC"亂浪錯形"NOR"」，在$n恍惚之時忽然連擊"NOR,
"damage": 30,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "震傷"
]),
([
        "action":"$N猛然一式「"HIC"霸浪不息"NOR"」，招式毫無贅招令$n無法抵禦 "NOR,
        "damage": 30,
        "dodge" : 10,
        "attact_type":  "bar",
        "damage_type":  "震傷"
]),
([
        "action":"$N手中$w不斷旋動使出「"HIC"橫浪無痕"NOR"」，招式渾然天成，毫無停歇的
擊在$n身上"NOR,
        "damage": 30,
        "dodge" : 20,
        "attact_type":  "bar",
        "damage_type":  "內傷"
]),
});

int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("jurlong-awi");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("鬼殺人...?\n");
        if (!weapon) return notify_fail("「絕浪奧義」得要有槌才可施展。\n");
        if(weapon->query("skill_type")!="hammer") return notify_fail(HIC"絕浪奧義"NOR"乃需有槌才能施展。\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("hammer")!="jurlong-awi")
                return notify_fail("你沒有施展"HIC"「絕浪奧義」"NOR"。\n");
                me->map_skill("hammer");
                me->reset_action();
                write("你將「絕浪奧義」之霸氣散去。\n");
                return 1;
        }
        if(me->query("ap")<20 || me->query("hp")<20) return notify_fail("你的身體狀況無法施展"HIM"「絕浪奧義」"NOR"。\n");
        //第二次exert
 if(me->query_skill_mapped("hammer")=="jurlong-awi")
        {
        if( me->is_ghost() ) return notify_fail("你已是鬼魂無法施展武功\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("你已在運行「絕浪奧義」了。\n");
                if (me->query_skill("jurlong-awi") < 91)
                return notify_fail("你到目前為止還無法領會到"HIC"絕浪"NOR"之奧義。\n");
                if(me->query("ap")<50) 
                return notify_fail("你目前的內勁不足，無法使用奧義。\n");
                if(!me->can_fight(target)) return me->can_fight(target);
                if(!me->is_fighting(target) ) return notify_fail("你並無在戰鬥中\n");
                message_vision(HIC"忽然一聲怒吼，$N手中$n一鳴，使出了"HIR"絕浪殺招"HIC"
                ，令人戰慄\n"NOR,me,target);
                me->start_busy(1);
                call_out("ccc",1,me,target,1,damage);
                me->start_busy(1);
                return 1;
        }
        if(!me->skill_active( "jurlong-awi",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("你「絕浪奧義」的動作還沒完成。\n");
        me->map_skill("hammer", "jurlong-awi");
        me->reset_action();
        message_vision(HIC"$N緊按手中之$n，兩腳紮出準備施展"HIM"「絕浪奧義」"HIC"
 之架式。\n"NOR,me);
        me->receive_damage("ap",40);
        me->start_busy(1);
        return 1;
}
void ccc(object me,object target,int z,int damage)
{
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return ;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
       if(!me->is_fighting(target)) me->kill_ob(target);
       z=me->query_skill("jurlong-awi");
             me->start_busy(1); 
             target->start_busy(3);
     message_vision(HIC"\n只見$N忽然靜止不動有如浪潮欲來…\n"NOR, me);                   message_vision(HIM"　　$N忽然手中招式順變擊出最強一式…\n\n"NOR, me);
     message_vision(HIM"  $N使出 - 奧義 "HIY"『 "HIC"—"HIM"浪"HIC"—"HIM"絕"HIC"—"HIM"天 "HIC"—"HIM"下"HIY"』\n"NOR, me);
 
      if( z >= random(target->query_skill("dodge")) )
       {
       message_vision(HIR"\n\n$n被浪氣捲入...無法止步受到重傷!!!\n" NOR,me,target);   
       damage = me->query_skill("jurlong-awi")+random(me->query("str")*5)
       +random(me->query_damage())-target->query_armor()/5-random(target->query("dex")*3);
       if(damage < 1) { damage = random(60)+me->query_skill("jurlong-awi"); } 
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+"   ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
      
       }
       else {
      message_vision(HIG"\n\n但$n已預感不對，全力脫離浪氣範圍"HIC"絕浪奧義"HIG"之威力大大降低了。\n" NOR,me,target);   
       damage = me->query_skill("jurlong-awi")+random(me->query("str")*3)   +random(me->query("damage")) - random(target->query("dex")*2);
       if(damage < 1) { damage = random(me->query_skill("jurlong-awi")); }
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
       target->receive_damage("hp",damage,me);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
       tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
       tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       COMBAT_D->report_status(target);
     
       }
if(!me->is_fighting(target)) me->kill_ob(target);   
}
void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "hammer" )
        {

                me->map_skill("hammer");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("hammer")!="jurlong-awi" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {        me->map_skill("hammer");
                me->reset_action();
                message_vision(NOR"\n$N忽然一陣乏力，看樣子已內勁全無。\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "jurlong-awi",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
     return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }







