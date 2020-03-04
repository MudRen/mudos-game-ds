#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"�]"NOR, ({ "evil" }) );
        set("long",@LONG
���~����b�a���U�A�P�ѧ��D�P�X�@��A�ͩʦn�j�A��ÿB
�����ͪ��A�u���u���v�o�ӿ�k�C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("attitude","aggressive");
        set("level",45+random(10));
        set("age",200+random(100));
        set("evil",-20);
        set("title",HIC"��"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/evil-armor")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     //carry_object(__DIR__"obj/evil-eye");   
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear(); 
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
                    +HIR"$N���M�V��@�D........\n" NOR     
                    +HIR"~ �F ! ! ~ ���@�n........�I�I\n"NOR
                    +HIR"�@�D�����e�V$n�ӥh�A�y���Y�����N��..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",300+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N���M�V��@�D........\n" NOR         
           +HIR"~ �F ! ! ~ ���@�n........�I�I\n"NOR                    +HIR"$n�������{�L$N�������A�����٬O�Q�l�V���N��......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(100), this_object());
      return 1;
    }
}
void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
 HIC"\n\t\t\t  "+ob->name(1)+"�P����^���j�Ԥ��]�Ʀʦ^�X��A�������V���]�����F�I�I\n\n"+NOR   
    HIR"\n\t\t       �@�x���H�F���]�����F�`���A���]���n�˦a�A���F�q�}�H���`���e�X�I�I\n\n"+NOR   
    HIW"\n\t\t\t\t\t�@�ۤƬ��L�ƥե��A�}���ӳu�I�I\n\n"+NOR,users());  
   //HIG"\n\t\t\t\t\t �����b�V���F�t�a�w�w�m��ù��n\n\n"+NOR
        ob->add("popularity",6); 
        ::die();
        return;
}

