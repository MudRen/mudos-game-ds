#include <ansi.h>
inherit NPC;

void create()
{
      set_name(HIY "楊過" NOR,({"Yang goo","goo"}) );
      set("title",HIC "古墓" NOR);   
      set("long",@LONG
 「楊過」是古墓主人之一，生性平淡，因早期的恩怨，使得他早期
 年少時就乏一臂，但仍不失其功力，反而更進一層，與妻子小龍女
 一起同住，也有幾位僕人，生活十分安逸。
LONG    
        );
        set("race", "human");    
        set("unit","隻");
        set("age",38);
        set("level",45); 
        set("max_ap",5100);
        set("combat_exp",540000);    
        set("limbs", ({ "頭部", "腹部","胸部","手部","腳部" }) );      
        add("addition_armor",300);
        add("addition_damage",200);  
        set("chat_chance", 100);
        set("chat_msg", ({
  (: command("exert ninning-force") :), 
  (: command("exert ninning-force") :),
  (: command("exert ninning-force") :),
  (: command("exert ninning-force") :),
  (: command("exert ninning-force") :),
  (: command("exert ninning-force") :),
}));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("exert heavy-sword") :),  
  (: command("exert heavy-sword") :),  
  (: command("exert heavy-sword") :),  
  (: command("exert anlan-fist") :),  
  (: command("exert anlan-fist") :), 
  (: command("exert anlan-fist") :), 
  (: command("exert anlan-fist") :), 
  (: command("exert anlan-fist") :), 
  (: command("exert ninning-force heal") :),
  (: command("exert ninning-force heal") :),
})); 
      set_skill("heavy-sword",100); 
      set_skill("anlan-fist",100);    
      set_skill("ninning-force",100);      setup();
      carry_object(__DIR__"sword")->wield();
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
    HIR"\n【驚傳快報】"+HIY "古墓派「 楊 過 」被"+ob->name(1)+"以俐落的手段殺掉了。\n\n"+NOR     
       ,users());
        ob->add("popularity",1); 
     message_vision( "$N"+HIR  "猛吐了一口鮮血，兩眼直視遠方"+HIW"，接著 . . . . 就不支倒地了 . . "NOR ,this_object() ); 
        ::die();
        return;
}

