#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"����"NOR, ({ "fire-element","fire","element" }) );
        set("long",@LONG
������¶�ۤ��V�����A�O�|�j�������@�C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("attitude","aggressive");
        set("level",40);
        set("age",10000+random(100));
        set("evil",-20);
        set("title",HIR"��"NOR); 
        set_skill("unarmed",200);
        set_skill("dodge",200); 
        set_skill("parry",200);       
        set_skill("combat",200);
        set("combat_exp",500000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/fire-key");
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
                    +HIR"$N���M�V��@�D........\n" NOR                    +HIR"~ �F ! ! ~ ���@�n........�I�I\n"NOR
                    +HIR"�@�D�����e�V$n�ӥh�A�y���Y�����N��..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",600+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N���M�V��@�D........\n" NOR                    +HIR"~ �F ! ! ~ ���@�n........�I�I\n" NOR                    +HIR"$n�������{�L$N�������A�����٬O�Q�l�V���N��......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",300+random(100), this_object());
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
    HIC"\n�i���������j"+HIR "�����u �� �v���ͩR�A�N�����b"+ob->name(1)+"����̡C\n\n"+NOR     
       ,users());
        ob->add("popularity",10); 
     message_vision( "$N"+BLU  "�������몺�A�C�C�a . . . �C�C������ .  . "NOR ,this_object() ); 
        ::die();
        return;
}

