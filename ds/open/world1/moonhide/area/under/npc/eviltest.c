#include <ansi.h>

inherit NPC;
void heal();
void create()
{
        set_name(HIR"魔"NOR, ({ "devil" }) );
        set("long",@LONG
長年壓制在地底下，與天妖乃同出一轍，生性好強，對污辱
它的生物，只有「死」這個辦法。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("attitude","aggressive");
        set("level",45+random(10));
        set("age",200+random(100));
        set("evil",-20);
        set("title",HIC"天"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000); 
        set("chat_chance",10);
        set("chat_msg",({
        (: heal :),  
}));
     setup();  
     carry_object(__DIR__"obj/evil-armor-only")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     //carry_object(__DIR__"obj/evil-eye");   
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear();  
     carry_object(__DIR__"obj/fire-fruit");
} 
void heal()
{ 
  if(query("hp") > query("max_hp")) return;  
  add("hp",600); 
  return;
}   
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIR"\n天魔狠狠的往$N的胸口抓了下去！\n"+NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                case 1: 
                        this_object()->kill_object(environment(me));
                        break;
        }
} 
/*int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIR"\n$N"+HIW"張開雙手，漸漸凝聚一股氣勁••\n"     
                    +HIC"擊出！！『"+HIB"渾元魔球"+HIC"』直直地\n"
                    +HIC"落向$n，造成"+HIR"沉重的內傷！\n"+NOR,me,target);
      target->receive_damage("hp",400+random(150), this_object());
      return 1; 
    }
    else
    {
      message_vision(HIR"\n$N"+HIW"突然眼放"+HIG"青光"+HIW"，口內漸漸聚集一股能量••\n" 
                    +HIW"噴出！毀滅性的"+HIR"火燄"+HIW"無情的燒向$n，\n"
                    +HIW"造成"+HIR"嚴重的燒傷！\n"+NOR ,me,target);      
      target->receive_damage("hp",300+random(100), this_object());
      return 1;
    }
}  
*/int special_attack_two(object me, object target, int hitchance)
{ 
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if(random(hitchance*40) > this_player()->query_str()*2)
  if(!random(9))
  { 
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIM"\n一陣天搖地動.....一道強烈的妖氣從地縫竄出，緊緊纏繞著$N\n\n"NOR,me);
    call_out("do_shot",2,me);
    return 1;
  }
  return 0;
}

void do_shot(object me)
{ 
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIR"\n天魔"+HIW"雙手一開！無數的"+HIC"能量球"+HIW"四處亂擊，威力無窮！\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(500)+250;
      message_vision(HIW"$N被"+HIC"能量球"+HIW"擊中，瞬間少了一大半的生命！+"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
  }
  me->start_busy(3);
  return;
}

void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
 HIC"\n\t\t\t  "+ob->name(1)+"與眾位英雄大戰天魔數百回合後，伺機擊向天魔的天靈！！\n\n"+NOR   
    HIR"\n\t\t       一掌粉碎了天魔的元靈顱骨，天魔應聲倒地，邪靈從破碎的顱骨疾出！！\n\n"+NOR   
    HIW"\n\t\t\t\t\t　幻化為無數白光，破雲而逝！！\n\n"+NOR,users());  
   //HIG"\n\t\t\t\t\t 直直奔向幽靈聖地──《修羅域》\n\n"+NOR
        ob->add("popularity",8); 
        ::die();
        return;
}

