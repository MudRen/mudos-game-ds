#include <ansi.h> 
inherit NPC;
void FLYAWAY(); 
void HEALTH(); 
void SUCKBLOOD(); 
string *ways = {("/open/world1/void create()
{
      set_name(HIM"�l�尭" NOR,({"lamia"}) );
      set("title",HIW "�ڧl" NOR);   
      set("long",@LONG
text 
LONG    
        );
        set("race", "human");    
        set("unit","��");
        set("age",200);
        set("level",55+this_player()->query("level")/5); 
        set("max_ap",8000); 
        set("max_hp",16500);
        set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��","�ͻH" }) );      
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
    HIR"\n�i��ǧֳ��j"+HIY "�j�Ӭ��u �� �L �v�Q"+ob->name(1)+"�H�W������q�����F�C\n\n"+NOR     
       ,users());
        ob->add("popularity",1); 
     message_vision( "$N"+HIR  "�r�R�F�@�f�A��A�Ⲵ��������"+HIW"�A���� . . . . �N����˦a�F . . "NOR ,this_object() ); 
        ::die();
        return;
}

