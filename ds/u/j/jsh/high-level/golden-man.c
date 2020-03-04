#include <ansi.h> 
inherit NPC;  
void super();
void create() 
{ 
       set_name(HIW"動態金人"NOR,({"golden man","man"}));
       set("gender","human"); 
       set("title",HIC"疾風"NOR); 
       set("level",40);
        set("mobhp",50);
        set_temp("apply/dodge",-999);
        set_temp("apply/armor",-10);
        set("combat_chance_chance",10);
        set("combat_chat_msg",({ 
  (: super :),   
}));
       set("long",@LONG      
專門針對疾風所設計的金人，有著強大的特攻，跟以往
的金人有所不同，如果不是疾風門的去打，它可是不會
理你的呢。

LONG
); 
        setup(); 
}  
void super()
{
     object me,victim;
     me=this_player();   
     if(!me->query("class1") == "疾風門" )return; 
     message_vision(HIW"\n單刨屢空，提腿震地，"HIR"四彩光芒"HIW"，由地而起！武林絕學『"HIG"萬劍藏空"HIW"』！！\n"NOR,me); 
     me->start_busy(2);  
     this_object()->start_busy(2);
     if(random(10)>5) 
     { 
message_vision(HIW"\n萬把氣劍齊飛，由上而往"+me->name()+"去，『啊！』數到光芒從"+me->name()+"爆發，"HIR"鮮血"HIW"直流而下..\n"NOR,me);
                   COMBAT_D->do_attack(me, this_object(), 5);
                   COMBAT_D->report_status(me);
                   me->add_busy(3);   
                   me->receive_damage("hp",500+random(100));
        } 
        else{
                    message_vision(HIG""+me->name()+"化解了那數到光芒，令子黃丹驚嘆不已..\n"NOR,me); 
                   this_object()->add_busy(3);
        } 
        return;} 
void heart_beat()
{
  object obj,corpse;
  obj=this_object();
  if( obj->query("mobhp") < 0 )
  {
   corpse=new(__DIR__"ccopper");
    message_vision("\n突然$N發出一陣『喀∼啦∼』數聲，$N已經毀壞了。\n",obj); 
     this_player()->remove_all_killer();
    destruct(this_object());
    //::die();
  } else obj->add_block(2);

  return; 
}

int receive_damage(string type,int damage,object who)
{
  int j,mobhp;
  object obj;
  obj=this_object();
  j=random(15)+1;
  if( !who ) return 0;
  who->add("exp", j);
  tell_object(who,"\n你得到了"+j+"點的經驗值。\n");
  mobhp=obj->query("mobhp");
  obj->set("mobhp",mobhp-1);  
  if(who->query("ap")>0)
  {
    who->receive_damage("ap",3);
  }
  else {
    who->receive_damage("hp",10);
  }
}

