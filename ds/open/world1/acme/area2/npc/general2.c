#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��s�N" , ({ "kop general","general" }) );
        set("title",HIC"�i���Z�Уi �K���N"NOR );
        set("long",
                   "�L�O���Z���@�k�K���N���@����s�N�A\n"
                   "�L���p�j�s�몺�z�ߤ��n�A�ʧ餣�^�A\n"
                   "���}�����A���R�h�R�A����N��A���R\n"
                   "�X�y�A�O�ӿw�ꤧ�H�C\n"
            );
        set("level",25);
        set("race","�H��");
        set("gender","�k��");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("mirage-steps",60);
        set_skill("godsword",60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
        set("chat_chance", 6);
        set("chat_msg", ({
                "��s�N���ۻy�a���D�G�o�ӬI�������⨸�Ф@�z�H�è���h�F�C\n",
            (: random_move :),
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
  carry_object(__DIR__"wp/longsword.c")->wield();
     carry_object(__DIR__"eq/armor.c")->wear();
}
