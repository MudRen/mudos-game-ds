// star-sword.c
// 昴星劍義 - Star sword - By Cominging - 2000.2.10 = For Advanced Wind Party
// 這個劍義有 3 個 function 
// 1. 極星田字(tian) 2. 九淳二式(nine) 3. 劍氣(stun)
// Document:
//  1. 極星田字 - 大絕招, 攻擊為主. 在攻擊後有機會還有 random 內傷
//  2. 九淳二式 - 牽制招, 可以讓敵人 delay, 頂級時可以傷些微傷害值
//  3. 劍氣 - Max 大絕招, 可以傷人 + delay, 為高級絕招.
//
// 基本招式 - (5) 煜 罡 蔚 沃 奘 ( now )
/************************************************
 * 連發沒dely................重大問題
 * 強度好像超過了bagi
 *
 ************************************************/
//Linjack 修正部份問題.
//
// Cominging 調整固定強度 Aug, 26, 2000 
// Jangshow 修改 busy 與關閉 sevenstar-sword 的自學 func
#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

void delay_0(object me);
void stop_delay(object me);

int p_force = this_player()->query_skill("star-sword")/5;
int b_force = random(this_player()->query_skill("moon_force"))/4;
int spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force );

mapping *action = ({
  ([
        "action": "$N屈劍一指，內力潛進劍中，使出"HIC"「"HIR"煜"HIC"」"NOR"字訣，劍招狠狠的斗直直進",
        "damage":       25,  //這個是傷害強化的百分比 , 不是傷害點數
        "attack":       10,
        "attact_type":  "bar",  // 設定技能的攻擊種類 // 生物(bio) 獸性(bar) 魔法(wit)心靈(sou)科技(tec)
        "damage_type":  "刺傷", 
  ]),
  ([
        "action": "$N提劍虛畫七劃，似北斗七星，層層包住$n，趁機抽劍一擊，一招"HIC"「"HIB"罡\"HIC"」"NOR"戳向$n的$l",
        "damage":       15+random(spal/4),
        "dodge":        -5,
        "delay":        1,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
  ]),
  ([
        "action": "$N隱身潛進，突然在$n身旁對$n出了一招"HIC"「"HIG"蔚"HIC"」"NOR,
        "damage":       18,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
  ]),
  ([
        "action": "$N口中喃喃念道『背故都之沃衍，適新邑之丘墟』，手中之劍突然挑起土，使了"HIC"「"YEL"沃"HIC"」"NOR,
        "damage":       25,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
  ]),
  ([
        "action": "$N運氣於臂，手上的劍突然嗡嗡作響，氣勢驟升，對$n的$l使出一招"HIC"「"HIW"奘"HIC"」"NOR,
        "damage":       30,
        "attack_type":  "bar",
        "damage_type":  "刺傷",
  ])
});
int cast_skill(object me,string a, object target, string arg)
{
        int sk = me->query_skill("star-sword"),
            force = me->query_skill("force"),
            w_force = me->query_skill("moon_force"),
            sw = me->query_skill("sorgi_sword"),
            target_armor, me_damage, target_dodge, me_dex, sum_damage, penuma_damage, g,damage, nine;

    object weapon, wp, *attack_targets;
        
        weapon = me->query_temp("weapon");
        force=me->query_skill("force");

        if( arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="star-sword" )
                        return notify_fail("你並沒有在用昴星劍義喔！\n");
                me->map_skill("sword");
                me->reset_action();
                write("你不繼續使昴星劍義了！\n");
                return 1;
        }

        if( me->query("ap") < 30 )
                return notify_fail("你身體的狀況還不能使用昴星劍義。\n");

        if( !weapon ) return notify_fail("你沒有劍要怎麼使劍呀？\n");

        if( sw < 70 ) return notify_fail("你的索極劍法還不夠純熟，不能使昴星劍義，否則將易走火入魔！\n");

        if( weapon->query("skill_type")!="sword" )
                return notify_fail("你不用劍﹐還想用什麼武器來使劍？\n");

        if( arg == "?" || arg == "help" )
        {
                tell_object(me, HIC"「"HIB"昴星劍義"HIC"」的功\能有 極星田字(tian) 九淳二式(nine) 劍氣(penuma-sword)。\n"NOR);
                return 1;
        }

// 好像有問題, 先不要開劍神
//
//      else if( weapon->query("skill_type")!="sword" && sk == 110 )
//      {
//              me->map_skill(weapon->query("skill_type"), "star-sword");
//              me->set_temp("class/star-sword", weapon->query("skill_type"));
//              write("你決定使用"HIW"劍神"NOR"用意去體會昴星劍義的真義！\n");
//      }

        if( me->query_skill_mapped("sword") == "star-sword" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("你並沒有目標可以襲擊！\n"); // 改 by cominging
                if( !me->can_fight(target) ) return me->can_fight(target);

                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                //me_damage = me->query_damage() + w_force/4 + sk/3 + (int)(w_force * w_force + random(sk/4) * random(sk/2))/(w_force + sk);
                me_damage = me->query_damage() + w_force/4 + sk/3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                // qc section
                if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                // end of qc section
                if( !arg || arg == "?" )
                {
                        tell_object(me, HIC"「"HIB"昴星劍義"HIC"」的功\能有 極星田字(tian) 九淳二式(nine) 劍氣(penuma-sword)。\n"NOR);
                        return 1;
                }

                if( arg == "tian" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                        if( me->is_busy() ) return notify_fail("你正在忙！\n");
                        if( me->query_skill("star-sword") < 30 )
                                return notify_fail("你的極星劍法還沒練的很純熟！\n");
                        message_vision("\n$N握劍一立，將劍置於胸前五寸前，接著用將手中的" + weapon->name() + "在空中劃了個 "NOR+BLU"[田]"NOR" 字，\n大喝了一聲﹐一招"HIC"『"HIY"極星田字"HIC"』"NOR"殺向$n。\n\n", me, target);
                        if( random(me_dex) > random(target_dodge)
                        && sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        {
                                target->receive_damage("ap", sum_damage/10, me);
                                target->receive_damage("hp", sum_damage, me);
                                target->start_busy(2+random(3)); // fix by jangshow
                                message_vision(HIR"$n一個不小心，被$N擊中了極星田字，結果口中一陣鮮血狂噴！！"NOR, me,target);
                                // QC
                                if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                // End QC
                                me->improve_skill("star-sword", random(me->query_int()/5) + 5);
                                me->improve_skill("sword", random(me->query_int()/6) + 5 );
                        else
                        {
                                message_vision(HIY"不料，$n似乎感受到了$N的各招各式，把$N所擊的招式一一化開。"NOR, me, target);
                                target->imporve_skill("dodge", 2);
                                sum_damage = 0;
                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                        else message_vision("\n\n", me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("ap", 28 + sum_damage/40 );
                        return 1;
                }

                if( arg == "nine" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                message_vision("$N使了使手中之劍，憶起"HIW"穴道之門"NOR"，接著便用劍點向$n的五泉穴，"NOR, me, target);
                        if( random(target->query_dex()) < random(me->query_dex()*1/2) )
                        {
                                message_vision(HIW"一團白光從$N的五泉穴彈出！令其無法行動！\n"NOR, target);
                                if( sk > 60 && sk < 90 ) target->start_busy(3+random(4)); //by jangshow
                                if( sk >= 90 )
                                {
                                        target->receive_damage("hp", me->query_damage()/3, me);
                                        target->start_busy(4+random(3)); //by  jangshow
                                        message_vision(HIR"一條血絲從$N的五泉穴噴了出來！"NOR, target);
                                        nine = 1;
                                }
                                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                  message_vision(HIY" ("+ HIR + me->query_damage()/4 + HIY")"NOR" \n"NOR, me);//js
                                else message_vision("\n", me);
                                COMBAT_D->report_status(target);
                        }
                        else
                        {
                                message_vision("$N運行氣勁鎖住五泉穴，進而瓦解攻勢。\n"NOR,target);
                        me->receive_damage("ap", 20 - sk/15);
                        if( nine )
                if( arg == "penuma-sword" )
                {
                        if( me->query("level") < 35 )
                                return notify_fail("你的等級還不夠高!\n");
                        if( me->query_skill("moon_force") < 95 )
                                return notify_fail("你的殘月心法還不夠純熟。\n");
                        if( me->query_skill("star-sword") < 90 )
                                return notify_fail("你的昴星劍義還不夠純熟。\n");
                        if( me->is_busy() )
                                return notify_fail("你還在忙！\n");
                        if( !me->is_fighting() )
                                return notify_fail("你沒在打架, 所以不能用劍氣！\n");
                        if( !arrayp(attack_targets = me->query_enemy()) )
                                return notify_fail("沒有攻擊對象！\n");
                        if( me->query_temp("class_wind/penuma-sword") )
                                return notify_fail("你短時間內還不能使用劍氣！\n");
                        message_vision(HIC"\n只見$N四周陡然一股強大的氣疾速上升…\n"NOR, me);
                        message_vision(HIY"　　$N提劍縱橫於敵之間，瞬間…$N發出劍氣，以劍剋敵…\n\n"NOR, me);
                        message_vision(HIM"  $N使出 - 進階 "HIY"『 "HIR"極 "HIG"． "HIR"星"HIG" ． "HIR"劍 "HIG"． "HIR"氣 "HIY"』 "HIM"－－－－－－－－－\n\n"NOR, me);

                        for(g=0;g<sizeof(attack_targets);g++)
                        {
                                if( random( attack_targets[g]->query_dex() ) < random( me->query_dex()*2 ) + 15 ) { 
                                        if( random( attack_targets[g]->query_skill("force")/2 ) > random(force) )
                                        {
                                                damage = me->query_damage()*2/3 + w_force/4 + random( me->query_damage()/4 );
                                                damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                                                attack_targets[g]->receive_damage("hp",damage, me);
                                                attack_targets[g]->start_busy(2);
                        message_vision(CYN"$N奮力迎擊, 硬是接下了這道劍氣！"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                                                COMBAT_D->report_status(attack_targets[g]);
                                        }
                                        else
                                        {
                                                damage = me->query_damage() + w_force*2/3 + random( me->query_damage()/3 );
                                                damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                                                attack_targets[g]->receive_damage("hp", damage , me);
                                                attack_targets[g]->start_busy(3);
                        message_vision(HIC"$N不及抵擋, 被劍氣打個正著！"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                                                COMBAT_D->report_status(attack_targets[g]);
                                        }
                                }
                                else {
                                        message_vision(YEL"$N躲過了這道劍氣！\n"NOR,attack_targets[g] );
                                        attack_targets[g]->start_busy(1);
                                }
                        }
                        message_vision("\n",me);
                        me->start_busy(2);
                        me->receive_damage("ap", 70);
                        me->set_temp("class_wind/penuma-sword", 1);
                        call_out("stop_delay", 25, me);
                        return 1;
                }
        }
        if( !me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6) )
                return notify_fail("你結束昴星劍義的動作還沒完成！\n");
          
        message_vision(HIY"$N眼觀四方﹐耳聽八方﹐心凝意在﹐漸漸體會昴星劍義！\n"NOR,me);
        me->map_skill("sword", "star-sword");
        me->receive_damage("ap", 10);
        me->reset_action();
        me->start_busy(1);
        return 1;
}

void delay_0(object me)
{
        object me_weapon;
        int sk = me->query_skill("star-sword");

        if( !me ) return;

        me_weapon=me->query_temp( "weapon" );

        if( !me_weapon || me_weapon->query("skill_type") != "sword" )
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }
        if( me->query_skill_mapped("sword")!="star-sword" ) return;

        if( me->query("ap") < 10 )
        {
                me->map_skill("sword");
                me->reset_action();
                tell_object(me, "你的體力不夠繼續使昴星劍義了！\n");
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap", 7);

        me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6);
}

void stop_delay(object me)
{
        if( !me ) return;
        me->delete_temp("class_wind/penuma-sword");
}

int valid_learn(object me)
{
        return 1;
} 
/*
mapping query_action(object me, object weapon)
{
        if( me->query_skill("star-sword") == 100 && !me->query_skill("sevenstar-sword"))
        {
                if( random(me->query("level")) == random(me->query_skill("star-sword")) )
                {
                        me->set_skill("sevenstar-sword", 1);
                        tell_object(me, HIW+BEEP"\n你受到了啟發，練成了新技能-[昴七星劍義 (sevenstar-sword)]。\n\n"NOR);
                }
        }
        return action[random(sizeof(action))];
}
*/
int practice_skill(object me)
{
        return 1;
}

int improve_limite(object ob)
{
        return 100;
}
 /*
void skill_improved(object me)
{
        if( me->query_skill("sevenstar-sword") )
        {
                me->set_skill("sevenstar-sword", me->query_skill("sevenstar-sword")-1 );
              tell_object(me, HIW"因為你練回昴星劍義，所以你不小心忘記了一部份的昴七星劍義。\n\n"NOR);
        }
} 
*/
