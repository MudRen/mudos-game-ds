#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�̶P�Ԫ�",({ "bear man","bear","man" }));
        set("long",
                "�L�O�@��צ�ԳN���Ԫ̡A���`�ϥηt���C\n"
                
        );
        set("age",39);
        set("level",20);
        set("gender", "�k��");
        set("str",20);                  
        set("dex",60);                  
        set("con",30);                
        set("int",50); 
        set("exp",3421);                
        set("attitude", "peaceful");
        set("combat_exp",2000);         
                        

        set_skill("throwing",60);   
        set_skill("parry",20);          
        set_skill("dodge",50);  
        set_skill("perception",10);
        set_skill("combat",50);        
        
        set("talk_reply","�ڦb�R��...�ЧO�n�ڡC");

        set("chat_chance",20);
        set("chat_msg", ({
  
  name()+"�����D�G�߮���H��̱j���H�åЫ۪šA�ڬO�@���l�]�l���W�r�C\n",
  name()+"�}�l�L���R��C\n",
  name()+"�}�l��s��W���ԳN�K�ޤ��� �C\n",
(: command("hmm") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�Ԫ̿E�ʪ����G�ڭ̶̨P�y�ԳN�O���|�Q�A���˪��I�I\n",
         (: command("baga") :),
    }) );
        setup();
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword");
        carry_object(__DIR__"wp/hand_sword")->wield();
        carry_object(__DIR__"eq/bear_cloth")->wear();
}
