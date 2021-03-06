#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
 set_name(HIM"歐坦之劍"NOR,({"oten sword","sword"}));
 set_weight(39180);
 set("value",20230);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit","把");
  set("long"," 黑暗劍士 歐坦將其畢生力量封印在這把劍之中, 又名[斬鐵劍]。這把劍上刻"
          +"\n滿了古文, 陣陣妖氣似乎要將你全身的血液凝固, 傳說只有鮮血將能使它的力"
          +"\n量解放出來.\n");
  set("material","steel");
  set("limit_sk",67);
  set("sword",67);
 }
 init_sword(937,TWO_HANDED);
 //set("weapon_prop/damage",820+random(50));
 set("wield_msg",HIC"$N從肩上抽出$n"HIC", 忽然$N的背後出現一個巨大的黑影!!\n"NOR);
 set("unwield_msg","一陣黑影從$N的身上向上竄離, $N將$n插回背上的劍鞘。\n");
 setup();
  set("weapon_prop/damage",query("sword")*4+(int)query("sword")*7/10+5);
  set("weapon_prop/hit",query("sword")*6 );
  set("weapon_prop/attack",(int)query("sword")/3);
  set("weapon_prop/parry",(int)query("sword")/5);
}

int fail_eq(object me)
{
 string wname;
 int dam;
 wname=this_object()->query("name");
if(!me) return 0;
 if(me->query("int") < 40+random(20) )
 {
  message_vision("\n"+wname+HIY"發出一陣低嚎: $N的能力還不夠資格驅使我戰鬥!!\n\n"NOR,me);
  message_vision(wname+HIR"劇烈的抽動了一下!! $N被震傷了!!"NOR,me);
  dam=random(200);
  me->receive_damage("hp",dam);
  message_vision("("HIR+dam+NOR")\n\n",me);
  return 1;
 }
 return 0;
}

void attack(object me,object victim)
{
 int lck,lv,vlck;
 int damage;

if(!me || !victim)
 return ; //by pudon

 vlck=victim->query("lck");
 lck=me->query("lck");
 if(random(vlck)<random(lck*2) && random(20)>15)
 {
  message_vision(HIR"\n  　      喝∼啊∼∼哈∼哈∼∼哈∼∼哈∼∼∼[m\n"NOR,me);
  message_vision(HIC"\n$N的身體突然幻化為一名手持長劍, 騎在一匹神駒上的[1;34m黑衣武士!!![m\n"NOR,me);
  message_vision("[1;30m$N化身的[1;34m黑衣武士[1;30m開始慢慢對著"+victim->query("name")+"[1;30m策馬加速....\n\n\n[m"NOR,me);
  me->start_busy(1);
  call_out("attack2",3,me,victim);
  return;
 }
 return;
}

int attack2(object me,object victim)
{
 object link_ob;
 int lck,lv1,lv2,hhp,blood;
 int damage;

 if(!me || !victim) return 0; //by pudon

 lv1=me->query("level");
 if(!victim || victim->query("hp")<1)
 {
   message_vision(HIB"黑影找不到對手便漸漸回到了$N"HIB"的身上.\n"NOR,me);
  return 1;
 }
 lv2=victim->query("level");
 lck=victim->query("lck");
 if(random(lck) > random(me->query("lck")*3) )
 {
 message_vision("\n[1;34m黑衣武士[1;31m雙眼迸出兇光[m!!  [1;37m飛馬衝向$n....\n[m",me,victim);
 message_vision(HIW"\n只見黑暗中[1;5;37m一道閃光[m.. $n"HIW"十分狼狽的躲過了這致命的一擊!!\n"NOR,me,victim);
 return 1;
 }
  damage=me->query("int")*5;
  damage+=me->query("wis")*5;
  damage+=me->query("str")*3;
  damage+=me->query("air")*2;
  damage+=me->query("mus")*2;
  if(userp(victim)) damage =damage/4 ; else damage+=random(lv2*10);
  damage+=random(lv1*10);
  damage-=victim->query_temp("apply/armor");
  if(userp(victim)) hhp=victim->query("hp")/10; else hhp=victim->query("hp")/45;
  if(hhp>damage) damage=hhp;
  if(victim->query("hp")<damage) 
  {
   set_temp("upgrade",3);
  } else
  {
   if( random( me->query("lck") + victim->query("lck") )  > victim->query("lck") )
    set_temp("upgrade",1);
  }
  message_vision("\n\n[1;34m黑衣武士[1;31m雙眼迸出兇光[m!!  [1;37m飛馬衝向$n....\n[m",me,victim);
  message_vision("\n只見黑暗中[1;5;37m一道閃光[m..   $n身上"HIR"鮮血如泉水般噴出!!"HIG"("HIR+damage+HIG")\n\n\n"NOR,me,victim);
  victim->receive_damage("hp",damage,me);
  if(query_temp("upgrade"))
  {
   blood=query_temp("upgrade")+random(3);
   if(query("weapon_prop/damage")<1000)
   {
    me->add_temp("apply/damage",blood);
    add("weapon_prop/damage",blood);
    me->add_temp("apply/hit",blood);
    add("weapon_prop/hit",blood);
   }
   message_vision(HIR"$N"HIR"手中的"HIM"歐坦之劍"HIR"吸收了敵人的鮮血, 殺氣直衝雲霄!!\n"NOR,me);
   delete_temp("upgrade");
  }
  return 1;
}
