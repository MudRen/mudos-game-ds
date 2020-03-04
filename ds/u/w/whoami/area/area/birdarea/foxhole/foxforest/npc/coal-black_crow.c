#include <ansi2.h> 
inherit NPC;

void create() 
{
        set_name(HIW+BLK"���¯Q�~"NOR,({"coal-black crow","crow"}));    
        set("long","�@�س����A���麣�¡A�}�Ӫ��A�k���_���A�L�j�Ӧy�A�h�s��\n"
                   "��L�����A�`���\���M�G���A���@���`�����E\n");
        set("level",27+random(5));
        set("attitude", "peaceful");
        set("race", "���~");
        set("max_hp",3500+random(4000));
        set("str",30+random(2));  
        set("dex",80+random(2));   
        set("addition_damage",86+random(20));  
        set("addition_shield",70);  
        set_temp("apply/dodge",30+random(20));
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "�Y��", "����", "���l"}) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
}

int special_attack(object me,object target,int hitchance)
{
    if(!me || !target) return 0;
    COMBAT_D->do_attack(me, victim, this_object(), 4);
    COMBAT_D->report_statue(victim);  
      return 1; 
}

void die()
{
        object me=this_object(),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(45) ){
         case 0:
          new(__DIR__"eq/feather")->move(me);
         }
        if(!random(5)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);  
        }     
        ::die();
        return;
}        

