#include <ansi.h>
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
 HIC"$N施展天劍疾刀流『狠』之真義，提起手中$w毫不留情的鑽向$n的心窩,"NOR,
 HIC"$N施展天劍疾刀流『準』之真義，全神貫注，將$w尖端明確對準$n的要害刺去,"NOR,
 HIC"$N施展天劍疾刀流『蕩』之真義，將$w拋到天空利用內勁使之不斷旋轉重重落在$n肩頭,"NOR,
 HIC"$N施展天劍疾刀流『楓』之真義，提起手中$w在$n的身上不斷的劃上強而有力的劍氣,"NOR,
 HIY"$N施展天劍疾刀流『亂』之真義，將$w繁亂的點落在$n的全身上下,"NOR,
 HIY"$N施展天劍疾刀流『華』之真義，握緊$w在$n的身上舞出繁多的華麗招式,"NOR,
 HIY"$N施展天劍疾刀流『怒』之真義，突然像發狂似的對著$n展開一連串的強勁攻勢,"NOR,
 HIY"$N施展天劍疾刀流『疾』之真義，像風一樣以迅雷不及掩耳之速朝著$n的$S劃了過去,"NOR,
});
mapping *action = ({
([
        "action":HIB"$N眼神一變，手腕一轉，將$w拖在地板上衝向$n，霎時使出一招"HIC"「疾滅斬天」"NOR"\n斬向$n",
        "damage":                20,
        "dodge" :               -10,
        "attact_type":  "bar",  // 設定技能的攻擊種類
                                // 種類有 生物(bio) 獸性(bar)
                                // 魔法(wit)心靈(sou)科技(tec)
]),
([
        "action":HIR"$N手指按著刀柄，腳尖一蹬，快速的奔到$n的身旁，拔刀迴斬，一式"HIG"「旋龍破」"HIR"\n狠狠的落在$n的$s上",
        "damage":    15,
        "dodge" :    20,
        "attact_type":  "bar",
        "damage_type":  "斬傷"
]),
([
        "action":HIM"$N氣定神閒,內勁頓時湧了上來，只見$w冒出了一道熊熊烈火,一式"HIR"「赤焰閃」"HIM"\n毫不
         留情的帶著烈火燃燒的聲響燒向$n",
        "damage": 22,
        "parry" : 5,
        "attact_type":  "wit",
        "damage_type":  "燒傷"
]),
([
        "action":HIC"$N把$w往上一丟，順勢跳了上去，氣勁一運，\n使出一式"HIB"「破空一線」"HIC"人和刀似乎化為一體,像一條閃電般向$n穿去",
        "damage": 21,
        "dodge" : -10,
        "attact_type":  "bar",
        "damage_type":  "穿傷"
]),
([
        "action":HIW"$N將$w用力的插入地板，突然狂風大作，$N身旁冒出了一道龍捲風包住了$N衝向$n\n
        ∼$N突然怒吼一聲"HIR"「∼一字狂風斬∼」"HIW"，手持$w向$n的胸膛鑽去",
        "damage": 28,
        "parry" : -20,
        "attact_type":  "bar",
        "damage_type":  "鑽傷"
]),
([
        "action":HIC"$N施展天劍疾刀流"HIY"『疾』"HIC"之真義，像風一樣以迅雷不及掩耳之速\n朝著$n的面部劃了過去"NOR,
        "damage": 22,
        "parry" : -10,
        "attact_type":  "bar",
        "damage_type":  "劃傷"
]),
([
        "action":HIR"$N施展天劍疾刀流"HIY"『怒』"HIR"之真義，突然像發狂似的對著$n展開\n一連串的強勁攻勢"NOR,
        "damage": 19,
        "dodge" : -9,
        "attact_type":  "bar",
        "damage_type":  "多重刀傷"
]),
([
        "action":HIG"$N施展天劍疾刀流"HIY"『華』"HIG"之真義，握緊$w在$n的身上舞出繁多的華麗招式"NOR,
        "damage": 22,
        "dodge" : -2,
        "attact_type":  "bar",
        "damage_type":  "多重創傷"
]),
([
        "action":HIM"$N施展天劍疾刀流"HIY"『亂』"HIM"之真義，將$w繁亂的點落在$n的全身上下"NOR,
        "damage": 24,
        "parry" : -2,
        "dodge" : -2,
        "attact_type":  "bar",
        "damage_type":  "模糊刀傷"
]),
([
        "action":HIC"$N施展天劍疾刀流"HIY"『楓』之真義，提起手中$w在$n的身上不斷的劃上強而有力的劍氣"NOR,
        "damage": 15,
        "dodge" : -5,
        "attact_type":  "bar",
        "damage_type":  "劍氣劃傷"
]),
([
        "action":HIW"$N施展天劍疾刀流"HIY"『蕩』之真義，將$w拋到天空利用內勁使之不斷旋轉重重落在$n肩頭,"NOR,
        "damage": 21,
        "dodge" : -8,
        "attact_type":  "bar",
        "damage_type":  "多重斬傷"
]),
([
        "action":HIG"$N施展天劍疾刀流"HIY"『準』之真義，全神貫注，將$w尖端明確對準$n的$s刺去,"NOR,
        "damage": 25,
        "dodge" : -15,
        "attact_type":  "bar",
        "damage_type":  "極深刺傷"
]),
([
        "action":HIR"$N施展天劍疾刀流"HIY"『狠』之真義，提起手中$w毫不留情的鑽向$n的心窩,"NOR,
        "damage": 23,
        "dodge" : -10,
        "parry" : -5,
        "attact_type":  "bar",
        "damage_type":  "極深鑽傷"
]),
});
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
 int a,c,i,j,damage,th,sd,b,d,e,da;
 string msg,aa;
 object weapon,ccc;
 mapping type;
 weapon=me->query_temp("weapon");
 da = me->query_damage();
 th = me->query_skill("taingin-blade");
 sd = me->query_skill("blade");
 if(arg=="off" )
 {
  if( me->query_skill_mapped("blade")!="taingin-blade")
  return notify_fail(HIG"你並沒有在施展"HIC"天劍疾刀流。\n"NOR);
  me->map_skill("blade");
  me->reset_action();
  message_vision(HIM"$N將刀向旁一甩，散掉了"HIC"「天劍疾刀流」"NOR"之劍氣。\n"NOR);
  return 1;
 }
 if(!weapon || weapon->query("skill_type")!="blade") 
 return notify_fail(HIC"天劍疾刀流"NOR"乃需有刀才能施展。\n"NOR);
 if(me->query_skill("blade")<60)
 return notify_fail(HIG"你對刀的認知還不夠，施展天劍疾刀流的話會走火入魔。\n"NOR);
 if(me->query("ap")<30 )
 return notify_fail(HIR",你現在內力不足，無法施展"HIC"天劍疾刀流"NOR"。\n"NOR);
 if(me->query("hp")<50 ) 
 return notify_fail(HIR"你受了重傷，如果勉強施展"HIC"天劍疾刀流"NOR"是會吐血身亡的。\n"NOR);
 if(!objectp(ccc=present("blade",me) ) )
 return notify_fail(HIC"天劍疾刀流"NOR"乃需有刀才能施展。\n"NOR);
 //第二次exert
 if(me->query_skill_mapped("blade")=="taingin-blade")
 {
  if( !target ) target = offensive_target(me);
  if(!target)   return notify_fail(HIG"你已經在施展"HIC"天劍疾刀流了"NOR"\n"NOR);
  if( arg == "?" || arg == "help" )
        {
                tell_object(me, HIC"「"HIC"天劍疾刀流"NOR"」的絕招有:霸王櫻花斬(overlord-chop) 奧義-心之意完全爆發(heart-burst)。\n"NOR);
                return 1;
        }
}
if( arg == "heart-burst" )
  {
  if(!me->can_fight(target)) return me->can_fight(target);
  if( !me->is_fighting(target)) me->kill_ob(target);
  if( !target->is_fighting(me)) target->kill_ob(me);
  if( me->is_busy() ) return notify_fail("你還沒有時間出招！\n");
  if (me->query_skill("taingin-blade") < 70)
  return notify_fail("你到目前為止還無法領會到"HIC"天劍疾刀流"NOR"的最終奧義。\n");
  c = target->query_armor();
  if(th > random(100) && sd > 60 && me->query("ap")>60 )
  {
   b = th/10;
   b = (b/2) + (random(b)/2) + 1;
   if(b>8) b=8;
   if(b<1) b=1;
   for( e=0;e<b;e++)
   {
    if(e<1) message_vision(HIY"$N閉上雙眼準備使出"HIC"天劍疾刀流"NOR"最終奧義-"HIR"【心之意】...."NOR"\n\n"NOR,me,target);
    d = random(sizeof(adv_attack));
    msg = adv_attack[d];
    damage = th + sd;
    damage =  (damage/3) + ((da*3)/2);
    damage -= (c/2) + (random(c)/2);
    if(damage<50) damage=30+random(20);
    if(damage>100) damage=40+random(40);
    if(random(me->query_dex()*2+th/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
    {
     msg += HIG"結果造成$n一處嚴重的傷害!!\n"NOR;
     message_vision(msg, me, target);
     me->improve_skill("taingin-blade",random(3));
     damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
     target->receive_damage("hp",damage,me);
     COMBAT_D->report_status(target);
    }
   else
    {
     msg += HIY"沒想到$n竟然看破了這招還沒出招便被閃了開去。\n" NOR;
     message_vision(msg, me, target);
     target->improve_skill("dodge",1);
   }
   }
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);     
   me->receive_damage("ap",8*b);
   me->improve_skill("blade",1);
   return 1;
  }
if( arg == "overlord-chop" ) 
  {
   if( !me->is_fighting(target)) me->kill_ob(target);
   if( !target->is_fighting(me)) target->kill_ob(me);
   if (me->query_skill("taingin-blade") < 50)
   return notify_fail("你到目前為止還無法領會到"HIC"天劍疾刀流"NOR"的精義。\n");
   if( me->is_busy() ) return notify_fail("你還沒有時間出招！\n");
   message_vision(HIM"$N怒吼一聲"HIC"【精義】"NOR"∼"HIY"【/霸王"HIM"櫻花"NOR"斬】"NOR"驚天動地，鬼哭神號，兩眼發紅的劈向$n∼!\n"NOR,me,target);
   damage = (th/5) + (sd/5) + (da/5);
   damage = (random(damage)/2) + damage/2;
   damage -= (random(c)/2);
   if( damage < 5 ) damage = random(10);
   if( random(me->query_dex()*2+sd/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
   {
    msg = HIC"$n閃躲不及被$N狠狠的劈中了這招奧義，傷口鮮血不斷狂噴"NOR;
    message_vision(msg, me, target);
    me->improve_skill("taingin-blade",target->query("level")/5);
        // 增加素質對傷害的影響
    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
    target->receive_damage("hp",damage,me);
    COMBAT_D->report_status(target);
    target->start_busy(2);
   }
   else
   {
    msg = HIC"$n看穿了這招，冷靜的避開了這招天劍疾刀流之精義。\n";
    message_vision(msg, me, target);
    target->improve_skill("dodge",1);
    target->start_busy(1);
    me->start_busy(2);
   }
   me->receive_damage("ap",40);
   me->start_busy(1);
   if(!me->is_fighting(target)) me->kill_ob(target);
   if(!target->is_fighting(me)) target->kill_ob(me);
   me->improve_skill("taingin-blade",1+random(me->query_int()/4));
   me->improve_skill("blade",1+random(me->query_int()/4));
   return 1;
 }
 }
 
 me->map_skill("blade","taingin-blade");
 me->reset_action();
 message_vision("\n"HIC"$N提起手中"+weapon->query("name")+"，使出"HIC"天劍疾刀流"NOR"。\n"NOR,me);
 me->receive_damage("ap",20);
 me->start_busy(1);
 return 1;
}
void delay(object me,int cost)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
        me->map_skill("blade");
        me->reset_action();
        return;
        }
        if(weapon->query("skill_type")!="blade")
        {
                me->map_skill("blade");
                me->reset_action();
                return;
        }
    if(me->query_skill_mapped("blade")!="taingin-blade")
        {
         return;
        }
    if(me->query("ap")<30)
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me,HIR"以你的內力已無法再繼續使用天劍疾刀流。\n"NOR);
                return ;
        }
        if(me->query("hp")<50)
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me,HIR"你吐了口鮮血，已無法繼續施展"HIC"天劍疾刀流"NOR"。\n"NOR);
                return ;
        }
  if( me->is_fighting() ) me->receive_damage("ap",20);
  me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay", me ,cost:), 10);
    }
int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
        int a;
        a=ob->query_int();
        a=40+a;
        return a; 
}
