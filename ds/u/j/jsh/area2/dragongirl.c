#include <ansi.h>

inherit NPC;

void create()
{
       set_name(HIY "�p�s�k" NOR,({"dragon girl","girl"}) );
       set("title",HIC "�j��" NOR);
         set("long",@LONG
 �u�p�s�k�v�O�j�ӥD�H���@�A���A�u���A�P�{�̷��L�����ҩd�A��
 �R�N���¡A���|�]���ҴB�������ӧN���L�A�Ϧӧ�[�R�@�A�i���L
 �̲`�~�j�ӡA���M�O�H���D�F�A���M�����C
LONG    
         );
         set("race", "human");    
         set("unit","��");
         set("age",45);
         set("level",40); 
         set("max_ap",4100);
         set("combat_exp",500000);         set("attitude", "heroism");    
         set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��" }) ); 
         add("addition_armor",150);
         add("addition_damage",200); 
         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
         (: command("exert girl-sword") :),     
         (: command("exert girl-sword") :),
         (: command("wield sword") :),
         (: command("wield sword") :),
         (: command("wield sword") :),})); 
        set_skill("girl-sword",100);

         setup();
         carry_object(__DIR__"sword3")->wield();
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
    HIR"\n\n         ��  ~    ~    ~  "+HIC"�p�s�k"+HIR"���e��"+ob->name(1)+"�s�z�F�X�n�C\n\n"+NOR
         ,users());
         ob->add("popularity",1); //�n��
      message_vision( "$N"+HIR "   �{���e�A���������I��۷��L...." NOR ,this_object() );
         ::die();
         return;
}

