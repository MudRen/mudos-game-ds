#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create() {
	set_name(HIC"風魂"NOR,({"wind soul","soul","dagger"}));
	set("long",@LONG

小小的一把水晶匕首，看起來微不足道，但其中蘊含著不可知的魔
力，據說寄宿在其中的風之魂會吸收生物的靈魂。
風魂等級：空無一物
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("limit_dex",40);
    set("limit_int",25);
        set("unit", "把");        
        set("value",1000);
        set("volume",2);        
        set("material","crystal");               
               }
        set("soul_times",0);
        set("soul_levels",0);
	set("weapon_prop/bar",-1);
	init_dagger(20);
        set("backstab_bonus",10);
        set("class_only","thief");
        setup();
}    

void soul_lv(int lv)
{
 mixed level = ({"空無一物","似有若無","平凡無奇","妖力初成","略有成就",
                        "頗具妖力","妖芒乍現","妖力大盛","妖氣沖天","妖芒內斂",
                        "隨心所欲","爐火純青","深不可測","登峰造極","毀天滅地",
                        "究極妖力","妖力無邊",});
 int times,levels;
 times = this_object()->query("soul_times");
 levels = this_object()->query("soul_levels");
 times = times + lv;
 if (times >= (levels+1)*15 && levels < 50)
 {
  levels = levels +1;
  times = 0;
  write(HIR"風魂吸收了足夠的魂魄，威力更上一層樓。\n"NOR);
  if(levels<=33) set("long","小小的一把水晶匕首，看起來微不足道，但其中蘊含著不可知的魔\n"+
                "力，據說寄宿在其中的風之魂會吸收生物的靈魂。\n"+
                "風魂等級："+level[levels/2]+"\n");
  set("soul_levels",levels);
  this_object()->unequip();
  init_dagger(20+levels);
  this_object()->wield();
  set("backstab_bonus",10+levels);
 }
 set("soul_times",times);
 return;
}

void attack(object me,object victim)
{
 int lv;

  ::attack();
 if (((!victim) || (victim->query("hp") < 0)))  //找不到攻擊對象(可能打死mob在query到hp<0前離開)
 {                                               //或是打死mob並在當格query到mob hp<0
  if(victim) lv=victim->query("level");
  else lv=1;
  message_vision(HIW"$N"HIW"手中的風魂中透出一道光芒，將殘留的魂魄吸收。\n"NOR,me);
  soul_lv(lv * 2);
 }
 return;
}
