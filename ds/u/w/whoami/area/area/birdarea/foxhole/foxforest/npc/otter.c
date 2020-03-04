#include <ansi2.h> 
inherit NPC;

void create() 
{
        set_name("��á",({"otter"}));   
        set("long","�����T�ت��@�����~�A������A�ީ~�e��A�ɭ����s�ӥ͡E\n");         
        set("level",23+random(5));
        set("attitude", "peaceful");
        set("race", "���~");
        set("max_hp",3500+random(4000));
        set("str",40+random(2));  
        set("dex",40+random(2));   
        set("addition_damage",75+random(20));  
        set("addition_shield",50);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
}

void die()
{
        object me=this_object(),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(3) ){
         case 0:
           new(__DIR__"eq/fresh_fish")->move(me); 
         break;
         case 1:
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me);  
         break;
         case 2:
           new(__DIR__"eq/fresh_fish")->move(me);
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
           new(__DIR__"eq/fresh_fish")->move(me); 
         break;
         }

        if(!random(15)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);  
        }     
        ::die();
        return;
}        

