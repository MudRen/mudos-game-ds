#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"�Z�ó�"NOR,({ "wu tan ya","ya","wu" }));
        set("long",
                "�L�O�@��~�������N�M�k�������߮���H�A�P�Ѩʤ��M�T�C��\n"
                "�������S�̡A�X�٬��u�̶P�T�ǡv�C\n"
        );
        set("nickname",HIR"�̶P�T�Ǥ��@"NOR);
        set("age",25);
        set("level",35);
        set("gender", "�k��");
        set("str",40);                  
        set("dex",70);                  
        set("con",100);                
        set("int",70);                  
        set("exp",19208);        
        
        set("combat_exp",6000);         
        set("evil",-10);  
               
 set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",90);  
        set_skill("perception",35);
        set_skill("combat",100);     


        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"���D: �̧̧A�~�������Z�\\�N�p�������A���X�X�~�@�w��W�V�ڭ̪��C\n",
  name()+"���D: ������!�T�C���L��b�ӱj�F!�A�٭n�n�n�m�ߤ~�i��W�V�L�C \n",
  name()+"���D: ���L�n�h���ڭ̴X�ӤQ�X�X�Y���ּ֥����A�u�Q�A�ԴX���C\n",
(: command("smile") :),
(: command(":)") :),
(: command("addoil") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�Z�ó����Ī����G�n�[�S����H�԰��F�I�N��Ԧ��ڤ]�̤ߡI\n",
         (: command(":)") :),
           }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
        } 

