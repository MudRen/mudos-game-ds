#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�T�C��"NOR,({ "ki yin shun","ki","shun" }));
        set("long",
                "�L�O�@��~�������N�M�k�������߮���H�A�P�Ѩʤ��M�Z�ó�\n"
                "�������S�̡A�X�٬��u�̶P�T�ǡv�C\n"
        );
        set("nickname",HIG"�̶P�T�Ǥ��@"NOR);
        set("age",27);
        set("level",35);
        set("gender", "�k��");
        set("str",70);                  
        set("dex",90);                  
        set("con",120);                
        set("int",80);                  
        set("exp",27893);        
        
        set("combat_exp",6000);         
        set("evil",-10);  
               
 set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",40);
        set_skill("combat",100);     


        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"�N�M�a�b�ӤW�b����@���I�q���y�C\n",
  name()+"���D: �A�̭n�n�n�[�o�C \n",
 (: command("...") :),
(: command("hmm") :),
(: command("sigh") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�T�C���ϥX�W�Ū��[���ޤM���ԡC\n",
         (: command("...") :),
           }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
        } 

