#include <ansi.h>
inherit NPC; 
//void super_attack();
void create()
{
        set_name(HIC"時空魔術師"NOR, ({ "mage" }) );
        set("race", "人類");
        set("age", 40);
        set("level",60+random(10));
        set("long", HIW"迷樣的人。\n"NOR);      
        set("max_hp",30000);
        set("chat_chance", 33);
        set("chat_msg", ({
                (: random_move() :),
                "魔術師拿出了一面鏡子，開始整理頭髮。\n" }) );  
        set("chat_chance_combat", 300);
        set("chat_msg_combat", ({  
        (: random_move() :), 
/*
        (: super_attack() :), 
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :),
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :), 
        (: random_move() :),
        (: super_attack() :),
        (: super_attack() :),
        (: random_move() :),
        (: super_attack() :), 
        (: random_move() :),  
*/
}));        setup();  
        carry_object(__DIR__"mage-hat")->wear();  
        carry_object(__DIR__"mage-gloves")->wear(); 
}  

/*
void super_attack(object me,object target,int hitchance)
{
    int tdex,tcon;  
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision(HIW"$N大喊一聲：時空炸彈！！丟向$n！\n" 
                     HIW"$n被炸的鮮血淋淋...\n"NOR,me,target);
    target->receive_damage("hp",500+random(199), this_object());
    } 
    return;
}  
*/
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*200) > tdex+tcon)
    {
      message_vision(HIW"\n$N輕聲道：嗯...這次就選你囉！看我表演吧\n\n"
                     HIW"\n$N用手指著$n。\n\n" ,me,target);
      target->receive_damage("hp",100+random(200), this_object());  
      target->add_temp("yyy",1);
      call_out("do_super2",2,me);      return 1; 
    }
    else
    {
      message_vision(HIW"$N輕聲道：讓你們嚐嚐時空的壓力吧！\n\n"NOR,me,target);
      call_out("do_super",2,me);
      return 1;
    }
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"無比強大的壓力，從四面八方而來！\n"NOR,me);
  message_vision("\n你無處可逃，只能承受這強大的壓力！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(350)+300;
      message_vision(HIW"『喀啦』似乎是骨頭碎裂的聲音！ "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      if( inv[i]->query_con() > 90 )
        inv[i]->add_busy(1);
      else if( inv[i]->query_con() > 75 )
        inv[i]->add_busy(2);
      else
        inv[i]->add_busy(3);
      COMBAT_D->report_status(inv[i]);
    }
    else
    {
      message_vision(HIC"\n$N被強大的壓力所分解！ \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(2);
  return;
}
void do_super2()
{
      object me=this_player();  
      if(!me) return;
      if(me->query_temp("yyy") != 1 ) return;
      else{      message_vision(HIW"只見"+this_player()->name(1)+"被一個扭曲的空間給吃了進去！\n\n",me);
      this_player()->move(__DIR__"room");
      }
      return;
}int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        { 
                ::die();
                return;
        }
        message("world:world1:vision",
    HIR"\n【快    報】"+HIW "時空魔術師竟敗在"+ob->name(1)+"的手上！\n\n"+NOR     
       ,users()); 
        ob->add("popularity",10);  
        ::die(); 
        return;
} 
void start_busy() { return; }
void add_busy() { return; }





