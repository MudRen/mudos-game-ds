#include <ansi.h>
inherit NPC; 
void super_attack(); 
void heal_hp();
void create()
{
        set_name(HIC"時空魔術師"NOR, ({ "mage" }) );
        set("race", "人類");
        set("age", 40);
        set("level",60+random(10));
        set("long", HIW"迷樣的人。\n"NOR);      
        set("max_hp",25000);
        set("addition_damage",250); 
        set("addition_shield",350);
        set("addition_armor",350);
        set("dex",300); 
         set("Merits/bar",15+random(5)); 
        set("chat_chance", 33);  
        set("chat_msg", ({
                (: heal_hp():), 
                "魔術師拿出了一面鏡子，開始整理頭髮。\n" }) );  
        set("chat_chance_combat", 300);
        set("chat_msg_combat", ({  
        (: random_move() :), 
        (: heal_hp():),
        (: super_attack() :), 
}));        

        setup();  
        carry_object(__DIR__"mage-hat")->wear();  
carry_object(__DIR__"mage-glasses")->wear();  
        carry_object(__DIR__"mage-gloves")->wear(); 
}  

void heal_hp()
{
     object me=this_object();
     me->receive_heal("hp",200,me);
     return;
}
void super_attack()
{ 
    object me=this_player(),target=me->select_opponent();
    int tdex,tcon;  
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(100)+100 > tdex+tcon)
    {
    message_vision(HIW"$N大喊一聲：時空炸彈！！猛然地丟向$n！\n" 
                     HIW"$n被炸的鮮血淋淋...\n"NOR,me,target);
    target->receive_damage("hp",700+random(199), me);
    }  
    else {
    message_vision(HIW"$N大喊一聲：時空炸彈！！猛然地丟向$n！\n" 
                     HIW"$n被炸的鮮血淋淋...\n"NOR,me,target);
    target->receive_damage("hp",700+random(199), me);
          }
    return;
}  
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
//    object room = load_object("/open/world1/jangshow/room"); 
//    target->move("open/world1/jangshow/room");
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIW"\n$N輕聲道：嗯...這次就選你囉！看我表演吧\n\n"
                     HIW"\n$N隨便指了一個人。\n\n" ,me,target);  
      message_vision(HIW"$N輕聲道：順便讓你們嚐嚐時空的壓力吧！\n\n"NOR,me,target);
      message_vision(HIW"只見"+target->query("name")+"被一個扭曲的空間給吃了進去！\n\n"NOR,me);
      target->receive_damage("hp",100+random(200), this_object());    
      target->add_temp("be_point",1); 
      target->move("/open/world1/jangshow/room");
      tell_object(target,"你的胸口似乎被種下了什麼東西..\n");
      call_out("do_super2",2,me);
      return 1;    
    }   else {return 1;}
     
/*
    else if(random(hitchance*5) < tdex+tcon)    {
      message_vision(HIW"$N輕聲道：讓你們嚐嚐時空的壓力吧！\n\n"NOR,me,target);
      call_out("do_super",2,me);
      return 1;
    } 
      else { return 1; }   
*/
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
      if( !inv[i]->is_fighting(this_object()) ) continue;
      damage = random(1000)+500;
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
/* 有bug,先關掉 -by whoami 
  if(inv[i]->query_temp("be_point")!=0) {  
               switch(random(10)){
               case 0..1:               
               message_vision(HIW""+me->name(1)+"突然兩眼直視前方...口吐鮮血而亡！\n"NOR,inv[i]);
               inv[i]->die(); 
               break;
               case 2..5:
               message_vision(HIW""+me->name(1)+"受不了時空的壓力，吐了一口鮮血！\n"NOR,inv[i]);
               inv[i]->receive_damage("hp",600,inv[i]);
               break;
               case 6..9:
               message_vision(HIW""+me->name(1)+"受不了時空的壓力，吐了一口鮮血！\n"NOR,inv[i]);  
               inv[i]->receive_damage("hp",600,inv[i]);
               break;
                } 
  }
*/
  return;
} 
void do_super2()
{
      object me=this_player();  
      if(!me) return;
      message_vision(HIR"只見"+this_player()->query("name")+"被扭曲的空間擠壓的吐出一口鮮血！\n\n",me); 
      me->receive_damage("hp",500+random(200), me);    
      return;
} 
int receive_damage(string type,int cost)
{
  object ob,me;
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
        switch(random(99))
        {
        case 0..3:
        ::die(); 
        break;
                  default:
                  message_vision(HIW"時空魔術師說：嘿嘿嘿....。隨即便跳進了時空裂縫..\n"NOR,ob); 
                  destruct(this_object());
                  break; 
        }
        return;
} 
void start_busy() { return; }
void add_busy() { return; }

