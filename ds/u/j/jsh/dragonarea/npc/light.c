#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����l", ({ "son of light","son","light" }) );
        set("long",@LONG
�Y�s�����Y������A�i�H����q�����������������C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("level",45);
        set("age",50+random(2));
        set("title",HIY"�s" HIG"���ǤH"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",200); 
        set_skill("parry",100);       
        set_skill("combat",200);
        set("combat_exp",1000000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/dragonblade")->wield(); 
     carry_object(__DIR__"obj/pants")->wear();
     carry_object(__DIR__"obj/ring")->wear();
     carry_object(__DIR__"obj/cloth")->wear();   
     carry_object(__DIR__"obj/hands")->wear();  
     carry_object(__DIR__"obj/armor")->wear();
     carry_object(__DIR__"obj/boots")->wear(); }

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
                    +HIW"$N�ϥX���s�k���ʨB�s\n" NOR    
                +HIW"�L�ƪ��}�}��V$n........�I�I\n"NOR
                    +HIW"�y���Y�������..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(200), this_object());
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�ϥX���s�k���骢�s\n" NOR       
             +HIR"�@�i�i�����]�x��V$n�I�I\n" 
NOR               
      +HIR"�y���Y�����x��......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    } 
     if(random(hitchance*10) > tdex+tcon)

    {
      message_vision("\n"
                    +WHT"$N�ϥX���s�k���Ъ��s\n" NOR       
             +WHT"$N���鹳�O���_�ӯ몺ŧ�V$n�I�I\n" NOR    
                +WHT"�y���Y�������\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
else
    {
      message_vision("\n"
                    +HIB"$N�ϥX���s�k����v�s\n" NOR       
             +HIB"����e��A�b�ݤf�����@��šA[��]���@�n�A���V$n�I�I\n" NOR              
      +HIB"�y���Y��������\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
if(random(hitchance*10) > tdex+tcon)

    {
      message_vision("\n"
                    +HIC"$N�ϥX���s�k�������s\n" NOR       
             +HIC"�j�q���𺥺����E�A���U�w�몺�g�V$n�I\n" NOR                
    +HIC"�y���Y��������\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
 else    {
      message_vision("\n"
                    +HIG"$N�ϥX���s�k�������s\n" NOR       
             +HIG"$N�H�֥��C�A��$n��������A�ש󤣼ĦӤ��ۡI�I\n" NOR   
                 +HIG"�y���Y��������\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
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
    HIR"\n�i �Y �s �� �j"+HIW "�����l���b"+ob->name(1)+"����̡C\n\n"+NOR     
       ,users());
        ob->add("popularity",4); 
     message_vision( "$N"+HIB"�p�n���� : �b�ľQ���᭱ . . . . . . "NOR ,this_object() ); 
        ::die();
        return;
}

