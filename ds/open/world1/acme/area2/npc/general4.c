#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����N" , ({ "water general","general" }) );
        set("title",HIC"�i���Z�Уi �K���N"NOR );
        set("long",
                   "�L�O���Z���@�k�K���N���@�������N�A\n"
                   "�L�ݰ_�Ӥ߰���ơA���O�����q��A��\n"
                   "�P�����H�A���_�ƨӥ��O�H�u�A�@���h\n"
                   "�Y�C\n"
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
        set("chat_chance",5);
        set("chat_msg",({
            "�����N���ۻy�a���D�G�o�ӬI�������⨸�Ф@�z�H�è���h�F�C\n",
            (: random_move :),
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
      carry_object(__DIR__"wp/longsword.c")->wield();
     carry_object(__DIR__"eq/shield2.c")->wear();
}
