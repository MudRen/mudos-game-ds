#include <ansi.h>
inherit NPC; 
void combat_ai();  

void create()
{
 set_name("�}�b��",({"archer"}));
 set("long",@LONG  
�b�A���e���N�O�H�B���T�Q�U�s�s�D���ȤH���]���g��, ��
�D�D�Q�U�s�����g��U�U�����L��, ���o���O�k�H. �ݨӳo
�ӶǻD���D�ťިӭ�. 
LONG);
 set("title",YEL"�Q�U�s�s��"NOR);
 set("age",23+random(15));
 set("gender","�k��");
 set("level",30);  
 set("max_hp",6600+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75+random(15));  
 set("Merits/bar",5+random(3));
 set("Merits/bio",3+random(3));  
 set("Merits/wit",5+random(3)); 
 set_temp("apply/damage",95+random(30)); 
 set_temp("apply/hit",30+random(30));
 set_skill("gun",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));
 set("chat_chance_combat",60);
 set("chat_msg_combat", ({
 (: combat_ai :),
 }));
 
 setup();  
   carry_object(__DIR__"eq/thunder_crossbow")->wield();
 carry_object(__DIR__"eq/bolt"); carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
 carry_object(__DIR__"eq/bolt");
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return; 
  if ( me->query_temp("invis") ) return;
  command("shoot "+me->query("id"));

} 
 
void combat_ai()
{
        int i;
        object *target,wp;

        target = all_inventory(environment(this_object()));
        wp = this_object()->query_temp("weapon");

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield crossbow");

        if( wp->query_temp("loaded") < wp->query("max_load")/5 )
                command("reload bolt");

        /* �ĤH->attack */ 
 
           command("shoot");
           this_object()->start_busy(-2);
        return;
}

