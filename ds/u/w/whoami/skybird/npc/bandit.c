#include <ansi.h>
inherit NPC; 
void combat_ai();  

void create()
{
 set_name("����",({"bandit"}));
 set("long",@LONG  
�b�A���e���N�O�H�B���T�Q�U�s�s�D���ȤH���]���g��, ��
�D�D�Q�U�s�����g��U�U�����L��, ���o���O�k�H. �ݨӳo
�ӶǻD���D�ťިӭ�. 
LONG);

 set("title",YEL"�Q�U�s�s��"NOR);
 set("age",23+random(15));
 set("gender","�k��");
 set("level",35);  
 set("max_hp",8600+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75);  
 set("Merits/bar",3+random(3));  
 set("Merits/wit",2+random(3)); 
 set_temp("apply/damage",95+random(30)); 
 set_temp("apply/hit",30+random(30));
 set_skill("sword",80+random(15)); 
 set_skill("blade",80+random(15));
 set_skill("whip",80+random(15));
 set_skill("dagger",80+random(15));
 set_skill("hammer",80+random(15));
 set_skill("fork",80+random(15));
 set_skill("throwing",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));  
 setup();  
 set_living_name("Ten-mount_bandit");/* 
 carry_object(__DIR__"silk_cloth")->wear();
 carry_object(__DIR__"eq/large_blade")->wield();
 carry_object("/open/world1/eq/moon_skirt")->wear();
*/
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return; 
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);

} 

void die()
{
        int i;
        object ob,env,npc;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        switch( random(10) ){
        case 0:
        tell_object(ob,HIW"\n(�]���A�����F"+this_object()->query("name")+HIW"�A�ҥH�o��F 2 �I�n��C)\n"NOR); 
        ob->add("popularity",2); 
        break;
        }
        ::die();
        return;
}

