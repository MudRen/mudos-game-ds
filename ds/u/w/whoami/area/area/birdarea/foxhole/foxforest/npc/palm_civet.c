#include <ansi2.h> 
inherit NPC;
void steal_eq();
void create() 
{
        set_name(YEL"�W��"NOR,({"palm civet", "civet", "palm"}));   
        set("long","�@���Y���ۤ@���𸭪��W�ߡA�������l�O�L�Ҧ��k�O���ӷ��E��\n"
                   "�ǻD���A�W�ߵ��Τ۳N��ĤH�@�ԡA�@���ĤH���F�۳N�A�W����\n"
                   "�|�X���k���ԤԡE\n");         
        set("level",23+random(5));
        set("attitude", "peaceful");
        set("race", "���~");
        set("max_hp",3500+random(4000));
        set("str",40+random(2));  
        set("dex",40+random(2));   
        set("addition_damage",70+random(20));  
        set("addition_shield",200);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
        carry_object(__DIR__"eq/leaf")->wear();
}

void init()
{
  object me,ob=this_object();

  ::init();
  if( interactive(me = this_player()) && !is_fighting() && !ob->visible(me))
  { 
    if ( random(4) > 2){
    message_vision("�x�p��$N�ݨ�$n�a�F�L�ӡA�@�ȷϴN�k�o�����ܼv�F�E\n",ob,me);    
    destruct(ob);
    }
  }
} 
void die()
{
        object me=this_object(),
               obj=present("leaf",me),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(50) ){
         case 0..48:
          message_vision("$N�Y�����𸭬�M���ۤ��N���F�K\n",me);
          destruct(obj);
         break;
         }

        if(!random(8)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);  
        }     
        ::die();
        return;
}        

