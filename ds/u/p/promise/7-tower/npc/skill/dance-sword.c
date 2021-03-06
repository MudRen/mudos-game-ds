/************************************************/
/* SK NAME: 披舞七絕劍訣         EDIT TIME: 6/29*/ 
/* EDIT BY: Promise@DS           FOR: NPC使用   */
/* SK 七招敘述: 起訣 【凌虛御空】               */
/*              貳訣 【斷鶴續鳧】               */
/*              參訣 【風飄萍轉】               */
/*              肆訣 【恨遺明珠】               */
/*              伍訣 【遺恨綿綿】               */
/*              陸訣 【凌渡天關】               */
/*              終訣 【乾坤無極】               */
/* 最終SUPER:醉花劍指 [以屬性中的物防、物攻、物攻*/
/*                               心防、HP、AP、MP*/
/*                               戰熟、SOU、BIO  */
/*                       技能中的Sword、dodge    */
/*                               Combat為主      */
/************************************************/

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
inherit F_UNIQUE;
#define SKILL_NAME "披舞七絕劍訣"

void delay(object me);
void speed(object me, object target);
void speed_1(object me, object target, int hit, int again, int index);

mapping *action = ({
        ([
        "action": "$N漫步消遙的舞出"HIC"起訣"NOR" 【凌虛御空】，只見$n突然不知所措，毫無防備之力。",
        "damage":                10,
        "dodge" :               10,
        "parry" :               10,
        "attact_type":  "bar",
        "damage_type":  "殺傷",
        ]),
        ([
        "action": "$N起身迅速的奔向$n，舞出"HIY"貳訣"NOR" 【斷鶴續鳧】，只見$n突然不知所措，毫無防備之力。",
        "damage":                20,
        "dodge":                 -10,
        "parry" :                -6,
        "attact_type":  "bar",
        "damage_type":  "多處劈傷",
        ]),

        ([
        "action": "只見$N身行似醉仙般的捉模不定，舞出"HIG"參訣"NOR" 【風飄萍轉】，只見$n突然不知所措，毫無防備之力。",
        "damage":                30,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "斬傷",
        ]),

        ([
        "action": "$N氣定神凝的舞出"HIR"肆訣"NOR" 【恨遺明珠】，只見$n突然不知所措，毫無防備之力。",
        "damage":                40,
        "dodge" :                10,
        "parry" :               15,
        "attact_type":  "bar",
        "damage_type":  "砍傷",
        ]),

        ([
        "action": "$N身擰腰，舞出"HIM"伍訣"NOR" 【遺恨綿綿】，鋼劍隨身平劃，點向$n的胸腹要穴！ ",
        "damage":                50,
        "dodge" :               -20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "殺傷",
        ]),

        ([
        "action": "$N施出"HIB"陸訣"NOR" 【凌渡天關】，鋼劍脫手飛出，如遊龍般翱翔青宇，破空射向$n的胸口！",
        "damage":                60,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bar",
        "damage_type":  "刺傷",
        ]),

        ([
        "action": "$N施出"HIW"終訣"NOR" 【乾坤無極】，劍鋒平指，劍勢如風，一氣呵成猛攻$n的的頸部！",
        "damage":                70,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "劈傷",
        ]),

       });

int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("dance-sword");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("鬼殺人...?\n");
        if (!weapon) return notify_fail("你要找一把劍才能施展披舞七絕劍訣。\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("你手中必須有劍才能施展披舞七絕劍訣。\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="dance-sword")
                        return notify_fail(HIR"你沒運行披舞七絕劍訣。\n"NOR);
                me->map_skill("sword");
                me->reset_action();
                write(HIW"你已取消使用披舞七絕劍訣了。\n"NOR);
                return 1;
        }

        if(me->query_skill("dance-sword")<5) return notify_fail("你目前對披舞七絕劍訣毫無概念。\n");
        if(me->query("ap")<100 || me->query("hp")<100) return notify_fail("你的身體狀況無法使用披舞七絕劍訣。\n");


        //第二次exert
        if(me->query_skill_mapped("sword")=="dance-sword")
        {
        if( me->is_ghost() ) return notify_fail("鬼殺人...?\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("你已運行了披舞七絕劍訣。\n");
                if (me->query_skill("dance-sword") < 90)
                return notify_fail("目前你還無法使用仙謎•醉花劍指。\n");
              if(me->query("ap")<100) 
                return notify_fail("你目前的內勁不足，無法使用仙謎•醉花劍指。\n");
              if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("你沒有在戰鬥中。\n");
                message_vision(HIY"$N醉意萌生，開始運起仙謎•醉花劍指。\n\n"NOR,me);
                me->receive_damage("ap",200+random(50));
                me->start_busy(2);
                call_out("speed",1,me,target,1,damage);
                return 1;
        }
        
        if(!me->skill_active( "dance-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("你使出披舞七絕劍訣的動作還沒完成。\n");
        me->map_skill("sword", "dance-sword");
        me->reset_action();
        message_vision("\n"HIW"$N持起手中的"+weapon->query("name")+HIW "，開始運行披舞七絕劍訣。\n"NOR,me);
        me->receive_damage("ap",20);
        me->start_busy(2);
//      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
        return 1;
}

void speed(object me, object target)
{
  int again = me->query_dex() / 60 ;
  int index = 2;
  if(!me->is_fighting()) return;

  if(me->query("ap") < 40)
  {
    message_vision(HIW"$N手中的劍開始不聽使喚。\n"NOR,me);
    write(HIR"現在的身體狀況不適合使出醉花劍指\n"NOR);
    me->start_busy(1);
    me->command("unwield mix six sword");
    return;
  }
  message_vision(HIW"\n\t$N走踏醉仙舞步，以柔軟的筋骨站末、剛烈的正氣為初，煞那間，使出 "HIY"仙謎"HIW"【"NOR+GRN"醉花劍指"HIW"】！！\n\n"NOR,me,target);
  message_vision(HIW+BLK"這一刻道道劍氣化為花，花轉生為劍氣，兩道混合，讓人撲溯迷離。\n"NOR,me);
  call_out("speed_1",1,me,target,0,again,index);
  return;
}
void speed_1(object me, object target, int hit, int again, int index)
{
  string msg;
  int mcexp,tacexp,bio,sou,mhp,map,maxhit, temp_damage, damage,tar_damage ,i;
  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N將動作取消了。\n",me);
    return;
  }

  mcexp = me->query("combat_exp");
  tacexp = target->query("combat_exp");
  mhp = me->query("max_hp") /100;
  map = me->query("max_ap") /100;
  bio = me->query("Merits/bio") *10;
  sou = me->query("Merits/sou") *10;
  again ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() /10 + mhp + map + bio + sou;
  tar_damage = target->query_damage();
  if(environment(me) != environment(target))
  {
    message_vision("$N因為對手不在取消了攻勢。\n",me);
    return;
  }
  for(i=1;i<maxhit;i++)
  {
    msg = HIW+BLK"$N旋轉手中的劍，迅速刺出。";

    damage = random(temp_damage)+20;
    if( (mcexp > tacexp * 3 && random(7)) || (mcexp > tacexp * 3 / 2 && random(6)) || (mcexp * 3 / 2 > tacexp && random(3)))
    {
      hit++;
      msg += HIW+BLK"陣陣醉意氣息在$n"BLK"的手中竄出"NOR"( "HIW"第 "NOR+GRN +hit+HIW" 道劍指 )。"NOR+HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
          }
    else
    {
      if( mcexp * 3 > tacexp && random(3))
      {
        msg += HIC"劍指道道的被$n化解\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIY"$n身輕如燕子般，從容不迫的躲開攻勢!!\n\n"NOR;
        message_vision(msg,me,target);
        COMBAT_D->report_status(target);
        me->start_busy(3);
        target->start_busy(0);
        return;
      }
    }
    target->start_busy(2);
    me->start_busy(2);
    me->receive_damage("ap", 10, me);
    if(me->query("ap") < 40)
    {
      message_vision(HIG"強大的醉意氣息在$N脫穎而出，使得$N楚於毫無招架之力狀態！\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(NOR+BLU"$N的體內的醉意氣息消失殆盡，攻勢暫緩了下來!!\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N蓄勢待發，醉意氣息灌注在劍中，快速的射出數道劍指\n\n"NOR,me,target);
    message_vision(HIR"射出第"+chinese_number(index)+"道醉花劍指。\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(NOR+GRN"\n$N再次遭受到劍指的傷害，不知倒地。"HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}


void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "sword" )
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("sword")!="dance-sword" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N"HIR"體力不足緩緩的停了下來。\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "dance-sword",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
