#include <ansi.h>
inherit NPC;

void create()
{
      set_name(HIY "���L" NOR,({"Yang goo","goo"}) );
      set("title",HIC "�j��" NOR);   
      set("long",@LONG
 �u���L�v�O�j�ӥD�H���@�A�ͩʥ��H�A�]����������A�ϱo�L����
 �~�֮ɴN�F�@�u�A����������\�O�A�Ϧӧ�i�@�h�A�P�d�l�p�s�k
 �@�_�P��A�]���X�칲�H�A�ͬ��Q���w�h�C
LONG    
        );
        set("race", "human");    
        set("unit","��");
        set("age",38);
        set("level",45); 
        set("max_ap",5100);
        set("combat_exp",540000);    
        set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��" }) );      
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
    HIR"\n�i��ǧֳ��j"+HIY "�j�Ӭ��u �� �L �v�Q"+ob->name(1)+"�H�W������q�����F�C\n\n"+NOR     
       ,users());
        ob->add("popularity",1); 
     message_vision( "$N"+HIR  "�r�R�F�@�f�A��A�Ⲵ��������"+HIW"�A���� . . . . �N����˦a�F . . "NOR ,this_object() ); 
        ::die();
        return;
}

