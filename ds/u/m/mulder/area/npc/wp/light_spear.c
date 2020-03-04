#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
     set_name(HIW"光之槍"NOR, ({ "light spear","spear" }) );
     set_weight(2000);
     if( clonep() )
     set_default_object(__FILE__); 
     else {
           set("unit", "把");
           set("long", "\n");
           set("value", 10000);
           set("material", "steel");
}
           init_fork(200);
           set("wield_msg", HIW"$N將$n握在手中，$N大喝一聲： 光啊！ 槍身突然放出一道耀眼光芒！\n"NOR);
           set("unwield_msg", HIW"$N將$n放下，那道圍繞在光之槍的光芒瞬間消失無蹤！\n"NOR);
          
           setup();
}
void attack(object me,object ob)
{
int damage,str,con,dodge;

if( random(100)>70)
{

str = me->query_str();
con = me->query_con();
dodge = -COMBAT_D->attack_factor(me,"skill_type") - COMBAT_D->dodge_factor(ob,"dodge");
damage=(con+str-random(ob->query_armor()))*(3+random(5));
if( damage < 40) damage = 40 +random(10);
message_vision(HIW"\n     $N將光之槍卓立在敵人面前\n\n"+
HIY"   你不停將魔法力凝聚在槍口\n\n"+
HIR"   突然！   槍刃放出一道極為耀眼光芒！\n\n"+
BLU"   $N翻轉身形，以氣御槍，天空頓時變的渾沌黯淡!\n\n"+
HIG"   ……………………………………      暗\n\n"+
   "   ……………………………………\n\n"+
HIW"   ……………………………………      光\n\n"+
HIM"   $N突然大喝一聲：\n\n"+
HIW"            光啊！\n\n"+
HIY"   一道光芒從槍刃射出！\n\n"+
   "        此道聖光以雷霆萬鈞之勢射向敵人!!!"NOR,me);
 
if( random(100) < dodge)
    {
      message_vision(HIG"只見$N身形一閃，光彈從$N身旁擦身而過\n\n"NOR,ob);
    }
  else
    {
            ob->receive_damage("hp", damage, ob );
      message_vision(HIC"光之矢命中了$N\n\n"+
                     "在一場巨大爆炸中對$N造成了"+damage+"點的傷害\n\n",ob);
    }
         return;

    }
  return;
}
