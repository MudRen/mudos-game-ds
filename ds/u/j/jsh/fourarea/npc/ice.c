#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "element" }) );
        set("long",@LONG
�����л\�۳��������A�O�|�j�������@�C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("attitude","aggressive");
        set("level",50);
        set("age",10000+random(75));
        set("evil",20);
        set("title",HIC"�B"NOR); 
        set_skill("unarmed",200);
        set_skill("dodge",200); 
        set_skill("parry",200);       
        set_skill("combat",200);
        set("combat_exp",500000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/tear-ice");
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision("\n"
                    +HIC"$N�}��L��.....�����L�N�F�@�U...\n" NOR    
                +HIC"�@�������B�y���V$n........�I�I\n"NOR
                    +HIR"$n�Q�ƥH�d�����B�y�{��A�y���Y�������..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",1000+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
     +HIC"$N�}��L��.....�����L�N�F�@�U...\n" NOR               
     +HIC"�@�������B�y���V$n........�I�I\n"NOR                
     +HIR"$n���{�k�����]�Ӷ]�h�A���O�ƶq�u�O�Ӧh�F�A�٬O�Q����X��......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",500+random(100), this_object());
      return 1;
    }
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
    HIC"\n�i���������j"+HIW "�����u �B �v���ͩR�A�N�ĤƦb"+ob->name(1)+"����̡C\n\n"+NOR     
       ,users());
        ob->add("popularity",10); 
     message_vision( "$N"+BLU  "���ĤƯ몺�A�C�C�a . . . �C�C������ .  . "NOR ,this_object() ); 
        ::die();
        return;
}

