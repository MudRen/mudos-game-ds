#include <ansi.h> 
inherit NPC;
void FLYAWAY(); 
void HEALTH(); 
void SUCKBLOOD(); 
string *ways = {("/open/world1/void create()
{
      set_name(HIM"吸血鬼" NOR,({"lamia"}) );
      set("title",HIW "我吸" NOR);   
      set("long",@LONG
text 
LONG    
        );
        set("race", "human");    
        set("unit","隻");
        set("age",200);
        set("level",55+this_player()->query("level")/5); 
        set("max_ap",8000); 
        set("max_hp",16500);
        set("limbs", ({ "頭部", "腹部","胸部","手部","腳部","翅膀" }) );      
        add("addition_armor",300);
        add("addition_damage",200);  
        set("chat_chance", 15);
        set("chat_msg", ({
  (: HEALTH :), 
  (: random_move() :),
}));
        set("chat_chance_combat", 19);
        set("chat_msg_combat", ({
  (: SUCKBLOOD :),  
  (: FLYAWAY :), 
  (: random_move() :)
})); 
   setup(); 
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

