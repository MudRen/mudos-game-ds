#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���ѱN" , ({ "sky general","general" }) );
        set("long",
                  "�L�O���Z���@�k�K���N���@�����ѱN�A\n"
                  "�L�Ϧp�W�իݰ_�����s�A�~��N�R�B��\n"
                  "���A���G�O�ܦ���O���H�A���O�R�K��\n"
                  "����ɡC\n"
            );
        set("title",HIC"�i���Z�Уi �K���N"NOR );
        set("level",25);
        set("race","�H��");
        set("gender","�k��");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("godsword",60);
        set_skill("mirage-steps",60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
     set("chat_chance", 5);
        set("chat_msg", ({
                "���ѱN���D�G�I���A�ڱK�����X�A���W���]�è����Ю{�A�o�ƬO�u�ٰ��I\n",
                "���ѱN���D�G�I���A�A�٤��֧֩ۻ{�I\n",
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
      carry_object(__DIR__"wp/longsword.c")->wield();
  carry_object(__DIR__"eq/surcoat2.c")->wear();
}
