#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�i���̶P�Ԫ�",({ "adv bear man","bear","man" }));
        set("long",
                "�L�O�@��w�i���צ�ԳN�����j�Ԫ̡A���`�ϥηt���C\n"
        );
        set("age",39);
        set("level",26);
        set("gender", "�k��");
        set("str",25);                  
        set("dex",65);                  
        set("con",35);                
        set("int",55);  
        set("exp",5342);               
        set("attitude", "peaceful");
        set("combat_exp",3000);         
                        
        set_skill("blade",65);
        set_skill("throwing",65);
        set_skill("parry",30);          
        set_skill("dodge",60);  
        set_skill("perception",10);
        set_skill("combat",60);        
        
        set("talk_reply","�S�ơC");

        set("chat_chance",20);
        set("chat_msg", ({
  
  name()+"�i����A�ڭn��[�o�~��C\n",
  name()+"�}�l�L���R��C\n",
  name()+"�}�l��s��W���ԳN�K�ޤ��� �C\n",
(: command("hmm") :),
(: command("soga") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "�Ԫ̿E�ʪ����G�ڭ̶̨P�y�ԳN�O���|�Q�A���˪��I�I\n",
         (: command("wiled blade") :),
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
        carry_object(__DIR__"wp/yi_blade");
        carry_object(__DIR__"eq/bear_cloth")->wear();
}
void die()
{
        message_vision("$N�`�U�̫�@�f��:�ǥu�ǧڤѸ�M��..���]����\n",this_object());
        ::die();
}

