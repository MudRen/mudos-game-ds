// 2006.6.7 �ק�  by Jangshow// �W�[���v�ʱ� EQ
// 2006/12/92 �ק�  by Tmr �����ߨ�
// npc/eq/dragon-boots.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM "�I�G" NOR,({"dab aqua dragon","dragon"}) );
      set("title",HIM "���s" NOR);
        set("long",@LONG
�u���s  �I�G�v���@�ӥj�ͪ��A�ʳߪ᭻�A�~�󦿡B�򤧤��A�q���G
�Q�|�ءA�����@�H����A�@���ئp���A���������H�H�����W�����C
LONG    
        );
        set("race", "���~");    
        set("unit","��");
        set("age",300);
        set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�s��","�I��", "����" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",90);
        add("addition_shield",120);
        add("addition_damage",80);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
        if( random(100) > 95) 
        carry_object(__DIR__"eq/dab-aqua-boots")->wear();
        carry_object(__DIR__"wp/dab-aqua-claw")->wield();
        carry_object(__DIR__"eq/dab-aqua-armor")->wear();
}
void die()
{
         object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }  

        message("world:world1:vision",
   HIG"\n�i�Z�L�����j"+HIW "�ӥj�ͪ��u���s  �I�G�v���b"+ob->name(1)+"���⤤�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
       message_vision( "$N"+HIR "�{���e�A�g�R�F�X�j�f�A��...." NOR ,this_object() );
      obj=new(__DIR__"obj/dragon-blood");
      obj->move(environment(this_object() ) );
      obj=new(__DIR__"obj/dragon-blood");
      obj->move(environment(this_object() ) ); 
/*
       if( random(100) > 95) {
                d=new(__DIR__"eq/dragon-boots");
                d->move(environment(this_object()));   
                message_vision("$N"+NOR"�����W���U�F�@���㨬"NOR,this_object()); 
        }
*/
        ::die();
        return;
}

