#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�饻�p��",({ "japen child","child","japen" }));
        set("long",
                "�L�O�@�Ӥ饻�p�ġA�D�`�Q�����@��j�̡A���V�O���m�M�k�C\n"
                "�C\n"
        );
        set("age",7);
        set("level",8);
        set("gender", "�k��");
        set("exp",864);     
        
        set("combat_exp",500);         
        set("evil",-20);  
               
 set_skill("blade",25);          
        set_skill("parry",10);          
        set_skill("dodge",30);  
        set_skill("perception",5);
        set_skill("combat",25);     


        set("chat_chance",30);
        set("chat_msg", ({
  
  name()+"��:�ڭn�V�O�m�\\�A�������۪ť��ͤ@�˱j���H�C\n",
  name()+"���_��W����M�A��ۯ�H��h�C \n",
  name()+"���������ʤ⤤����M�A�Q���V�O�C\n",
(: command("sweat") :),
(: command("ya") :),
(: command("jump") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�饻�p�Ĥj�s�G�ϩR�ڡI�����ӱϧڡI\n",
         (: command("sob") :),
         (: command("help!") :),
           }) );
        setup();
        carry_object(__DIR__"wp/toy_blade")->wield();
        } 
void die()
{
        message_vision("$N�{�����e�����ڳڪ���:���٤��Q���r.....\n",this_object());
        ::die();
}
