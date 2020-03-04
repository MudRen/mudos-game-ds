#include <ansi2.h> 
inherit NPC;

void create() 
{
        set_name(HIW+BLK"���彿��"NOR,({"blood-sucking bat","bat"}));   
        set("long","�@�ط|�������Űʪ��A�Φ��ѹ��A�⨬�M���鳣�����۳s�p�l�A\n"
                   "�ޥ�]�X�A�h�������B�A�A�]���ּƳ߭��H��E\n");         
        set("level",27+random(5));
        set("attitude", "peaceful");
        set("race", "���~");
        set("max_hp",3500+random(4000));
        set("str",30+random(2));  
        set("dex",50+random(2));   
        set("addition_damage",75+random(20));  
        set("addition_shield",50);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "�Y��", "����", "���l"}) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();

    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision("\n$N"HIY"�@�ӭ��ĦV�e�A$n�����W�N�h�F�@�Ӥ����y�媺�����K\n"+NOR,me,target); 
      target->receive_damage("hp",200+random(45), this_object()); 
      target->apply_condition("blooding", target->query_condition("blooding") + random(8));
      return 1; 
    }
}

void die()
{
        object me=this_object(),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(30) ){
         case 0:
          new(__DIR__"eq/bat_mask")->move(me);
         }
        if(!random(7)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);  
        }     
        ::die();
        return;
}        

