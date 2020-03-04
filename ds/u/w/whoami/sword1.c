#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void sword_check();
void create()
{
set_name("陰陽長劍",({"yin-yang longsword","sword","longsword"})); 
set("long","這是一把由獨臂老人所打造出來的最佳傑作，但是現在劍身卻顯得\n"
           "暗淡無光•\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("limit_str",30); 
        set("limit_int",30);
        set("limit_dex",50); 
        set("limit_level",45);
        set("value",10000);
        set("material","blacksteel");
        }
        init_sword(45);
        setup(); 
        call_out("sword_check", 0);
}

void sword_check()
{

        object me = environment(this_object()),
               ob = this_object();
//        string sex;
//        sex = me->query("gender");

        if( !this_object() || !me ) return;
        if( interactive(me)
         && me->query_temp("weapon") == this_object())
        { 
          if ( me->query_skill("force") > 90 && me->query("ap") > 1000 ){
            switch( environment(this_object())->query("gender") ) {
             case "男性": 
              if( !ob->query("male") ){
              message_vision(HIR"$N將全身內力灌入劍中，$n"HIR"的劍身浮出淡淡的紅光•\n"NOR,me,this_object());
              me->receive_damage("ap",1000);
              ob->set("male", 1);  
              ob->set("long","這是一把由獨臂老人所打造出來的最佳傑作，現在劍身顯出淡淡\n"
                             "的紅光\n");
              }
              break;
             default: 
              if( !ob->query("female") ){
              message_vision(HIC"$N將全身內力灌入劍中，$n"HIC"的劍身現出亮眼的青光•\n"NOR,me,this_object());
              me->receive_damage("ap",1000);
              ob->set("female", 1); 
              ob->set("long","這是一把由獨臂老人所打造出來的最佳傑作，現在劍身顯出亮眼\n"
                             "的青光\n");
              }
              break;
            }
          }        }
 
        if ( ob->query("male") && !ob->query("female") ) {
             ob->set_name("陰"HIR"陽"NOR"長劍",({"yin-yang longsword","sword","longsword"})); 
           }
        else if ( ob->query("female") && !ob->query("male") ) {
             ob->set_name(HIC"陰"NOR"陽長劍",({"yin-yang longsword","sword","longsword"})); 
           } 
        else if ( ob->query("female") && ob->query("male") 
                  && !ob->query("power") && ob->query("equipped") != "wielded" ) {
             ob->set_name(HIC"陰"HIR"陽"NOR"長劍",({"yin-yang longsword","sword","longsword"})); 
             ob->set("power", 1); 
             ob->set("long","這是一把由獨臂老人所打造出來的最佳傑作，劍刃的地方有著絲\n"
                            "絲的寒氣，寒氣的外圍卻又包圍了一層暖氣，入手之後，令人為\n"
                            "之一震。\n"); 
        set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰陽調和之氣。\n");
        set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");
              set("weapon_prop/bio",-1); 
              set("weapon_prop/sou",-2); 
              set("weapon_prop/bar",random(3));
              set("weapon_prop/tec",random(3));
              set("weapon_prop/wit",1+random(2));
              set("weapon_prop/int",1+random(4)); 
              set("weapon_prop/hit",15);
              set("weapon_prop/damage",55);
          } 
        call_out("sword_check", 0);
} 

void attack(object me,object victim)
{
  object ob = this_object(),
         ppl = this_player();      
        int aa,aa1,power,mysk,myint,hp,mp,ap,time,times;
        hp = random(ppl->query("max_hp")*11/40);
        mp = random(ppl->query("max_mp")*11/60);  
        ap = random(ppl->query("max_ap")*11/50);        
        
        ::attack();
        if(!ob->query("power")) return;
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return; 
        
    switch ( random(30) ) {
      case 1:        
        message_vision(HIG"\n$N手中的$n"HIG"發出一股溫暖的氣息…"
                      +"\n這股溫暖的氣息讓$N的精氣在惡鬥之中不降反升！\n\n"NOR,ppl,ob); 
        tell_object(ppl,HIC"生命點數(HP)："+HIY+"("+hp+")"+HIC+ 
                          "　魔法點數(MP)："+HIY+"("+mp+")"+HIC+ 
                          "　內勁點數(AP)："+HIY+"("+ap+")"+NOR+"\n");

        ppl->receive_heal("hp",hp);
        ppl->receive_heal("ap",ap);  
        ppl->receive_heal("mp",mp); 
      break;
      case 2..6:
        if(me->query_skill("star-sword") > 90
        && me->query_dex() > 45
        && me->query("ap") > 170 ) 
        {
        message_vision("\n$N"HIW"手中的"+ob->query("name")+HIW"出一陣耀眼的白光，光芒中發出一股強烈的陰陽之氣衝向$n！\n"NOR,me,victim);
        mysk = me->query_skill("sword");
        aa1=me->query("MKS")/20000;
        if (aa1 < 1) aa1=1;
        if (aa1 > 4) aa1=4;
        power= (mysk+myint)/2;
         
         for (aa=0;aa<aa1;aa++)
         { 
          me->add_temp("apply/damage",power);
          COMBAT_D->do_attack(me, victim, this_object(), 1+random(4));
          COMBAT_D->report_statue(victim); 
          me->add_temp("apply/damage", -power);  
         }
        me->receive_damage("ap",random(25)+15);
        }
 
        if(me->query_int() >= 50
        && me->query("mp") > 400 
        && me->query_spell("god-fire") > 91 ) {
        myint = me->query("int");
        mysk = me->query_spell("god-fire"); 
        
        times =  myint/33+mysk/33;        
        message_vision(HIY"\n$N將手中$n"HIY"往空中一拋，煞時間"+chinese_number(times)+"顆火球從$N手中狂射而出！！\n"NOR,me,ob);
        for (time=0;time<times;time++)
         {
           SPELL_D("god-fire")->cast_fire(victim,me,mysk,myint);
           me->receive_damage("mp",20);
         }
        }
      break;
     } 
  return; 
}

