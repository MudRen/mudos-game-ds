#include <ansi.h>
inherit NPC;

void create()
{          set_name(HIC"���j"HIY"�ӫ�"HIR"�E��"NOR,({"tsz juioa","ts","ju"}) );
      set("title",HIC"���j"HIY"�ӫ�"NOR);
set("long" ,"�u���j�ӫ� �E�סv���@���j�ͪ��A���b�L�j�}���P�a���P��
  ,�E�� �N�s�b�F,�������@�N�Q��,����� ��z ���M ���L��
  �H�Ѧa�٬ӡC
\n");
               set("race", "�H��");    
        set("unit","��");
        set("age",6542879);
        set("level",50);
        set("attitude", "heroism");    
         
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
        carry_object("/u/t/tako/tiger-blade")->wield();
        carry_object("/u/t/tako/tiger-armor")->wear();
}
void die()
{
   object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIG"\n�i�Z�L�����j"+HIW "���j���ҡu�E�סv���b"+ob->name(1)+"���⤤�C\n\n"+NOR
        ,users());

        }





