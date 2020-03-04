// Jangshow@DS 暫離 LPC 界之作,原因要聯考 =_=a
// 用最簡單的方式寫, 寶石鑲嵌跟特攻可補充
// 特點, 特攻必中  
// 請接下來的wiz補充其他的鑲嵌 wp 
// save wp

#include <ansi.h>
#include <weapon.h> 
#define WPNAME "鑲嵌之劍"
inherit SWORD;

//string *stone= ({"一道巨火！狂噴沖天！","

void create()
{
  set_name(HIY"鑲嵌之劍"NOR , ({ "inlay sword","sword" }) ); 
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "上面有一個小洞，不知道是幹麻的[inlay xxx]。\n");
    set("material", "gold");
    set("value",30000);
  }
  set("weapon_prop/dodge",10);
//  set("weapon_prop/sword",10);    
  init_sword(50); 
  setup();
}
void init()
{
     add_action("do_inlay","inlay");
}
int do_inlay(string arg)
{ 
    object me=this_player(),obj;  
    if(this_object()->query_temp("inlaied")==1) 
       return notify_fail("裡面已經鑲了一顆寶石，你沒看到嗎？\n");    

    /***************************************鑲嵌開始****************************************/ 

    if(arg =="red stone") 
              { 
               if(!objectp(obj=present("red stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIR"紅寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIR"紅寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIR"火系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/red",1);
                    }  
              return 1;
              }      
    if( arg =="blue stone") 
              { 
               if(!objectp(obj=present("blue stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"BLU"藍寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"BLU"藍寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："BLU"水系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/blue",1);
                    }  
              return 1;
              }  
    if( arg =="white stone") 
              { 
               if(!objectp(obj=present("white stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIW"白寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIW"白寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIW"光系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/white",1);
                    }  
              return 1;
              }     
    if(arg =="green stone") 
              { 
               if(!objectp(obj=present("green stone",me)) ) return notify_fail("What?\n");
                   {
                    message_vision("\n$N小心翼翼的將"HIG"綠寶"NOR"，鑲進了"HIY""+WPNAME+"\n"NOR,me); 
                    this_object()->set("long","這是一把鑲了一顆"HIG"綠寶"NOR"的劍，上面的小洞已經被填滿了。\n"
                                           HIW"特殊能力："HIG"毒系"HIW"攻擊\n"NOR);   
                    destruct(obj);
                    this_object()->add_temp("inlaied",1); 
                    this_object()->add_temp("inlay/green",1);
                    }  
              return 1;
              }      
} 
int attack(object me, object victim,string arg)
{ 
    string msg="";
    int damage;
    if(!me || !victim) return 0;   
    if(random(5)) return 0;
    if(me->query_skill("dodge")*2/3 > victim->query_dex()*3/4 ) 
    /************特攻分類*************************************/  

      if(this_object()->query_temp("inlay/red")==1 ) 
     {
      damage=me->query_str()*3+random(me->query_skill("sword")*3/4);
      msg += HIR"\n一道巨火！猛然從"HIY""+WPNAME+""HIR"竄出！颳向"HIW""+victim->name()+"！\n"NOR;   
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]點的傷害！\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(2);  
      //victim->add_temp("firing",1);
      //call_out("fired",10,victim);  
      //call_out("de_fired",31,victim); 
      return 1; 
     } 
      else if(this_object()->query_temp("inlay/blue")==1) 
           { 
      damage=me->query_str()*3+random(me->query_skill("sword")*2/3);  
      msg += BLU"\n一陣水氣從"HIY""+WPNAME+""BLU"滲出••形成一種似水似龍的形體！擊向"HIW""+victim->name()+"！\n"NOR; 
      message_vision(msg,me); 
      tell_object(me,HIR"["+damage+"]點的傷害！\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(3);   //delay較久 
      return 1; 
           }   
      else if(this_object()->query_temp("inlay/white")==1) 
           {  
      damage=me->query_str()+random(me->query_skill("sword")*2/3);  
      msg += HIW"\n「劍光一閃」，猶如光輝大地，刺眼的光芒，鎖住了"+victim->name()+"的行動！\n"NOR;
      message_vision(msg,me);
      tell_object(me,HIR"["+damage+"]點的傷害！ 並造成"+victim->name()+"六回合的滯移！\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(6);
      return 1; 
            } 
      else if(this_object()->query_temp("inlay/green")==1) 
            { 
      damage=me->query_str()*2/3+random(me->query_skill("sword")*2/3); 
     msg += HIW"\n"+me->name()+"揮舞著"HIY""+WPNAME+""HIW"，並巧妙的在"+victim->name()+"身上畫出一道傷口！\n"
     HIR"傷口"HIW"漸漸的"HIG"化膿中毒....\n"NOR;     
      message_vision(msg,me);
      tell_object(me,HIR"["+damage+"]點的傷害！並造成"+victim->name()+"毒性殘留！\n"NOR);
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
      victim->start_busy(2);
    if( userp(victim) ) victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5)));
    //else victim->apply_condition("poison", victim->query_condition("poison")+ (15+random(5))); 
         return 1;
         }
         else return damage;
} 
int query_autoload() { return 1; }

/*
好像沒作用
void fired(object me,object ob,object victim)
{    
     int damage=50+random(10);
     if(victim->query_temp("firing") >= 0)
     {
     message_vision(HIW""+victim->query_name()+"的身上冒出濃濃的焦味..\n"NOR,victim);  
      victim->receive_damage("hp",damage,me); // victim->me by alick@ds 16042005
     call_out("fired",10,victim); 
     } 
     else return ;
}
void de_fired(object victim)
{ 
     victim->delete_temp("firing"); 
     return ;
} 
*/  
    

