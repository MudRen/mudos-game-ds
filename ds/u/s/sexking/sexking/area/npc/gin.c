#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�Ѩʤ�"NOR,({ "tain gin gin","gin","tain" }));
        set("long",
                "�L�O�@��~�������N�M�k�������߮���H�A�P�Z�ó��M�T�C��\n"
                "�������S�̡A�X�٬��u�̶P�T�ǡv�C\n"
        );
        set("nickname",HIC"�̶P�T�Ǥ��@"NOR);
        set("age",23);
        set("level",30);
        set("gender", "�k��");
        set("str",30);                  
        set("dex",100);                  
        set("con",90);                
        set("int",65);                  
        set("exp",18213); 
        set("attitude", "peaceful");
        set("combat_exp",6000);         
        set("evil",-30);                 

        set_skill("blade",100);          
        set_skill("parry",70);          
        set_skill("dodge",80);  
        set_skill("perception",30);
        set_skill("combat",90);        
        
        set("talk_reply","�u�n�A���n�Z�ê��񪺪Z�h�̴N�n�F....");

        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"���D: �ڪ��Z�\\�̮z�A�����̶P�T�Ǥ��@�u�O�\\������C\n",
  name()+"���D: ���O�]�������������Y�r! \n",
  name()+"���D: �ٰO�o��~�ڭ̤@�_���ѤU��b�O���I�U���A�u�O�ּ֧r�C\n",
(: command("smile") :),
(: command("blush") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�Ѩʤ����������G�n�[�S���n�n���Ԥ@���F�I�������Ф��n����I\n",
         }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
}



