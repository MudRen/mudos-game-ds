#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�I�A�N" , ({ "marsh general","general" }) );
        set("title",HIC"�i���Z�Уi �K���N" NOR);
        set("long",
                   "�L�O���Z���@�k�K���N���@���I�A�N�A\n"
                   "�L��Ω�~�A�y�e���N�A�ݰ_�ӷQ��\n"
                   "��C\n"
             );        
        set("level",25);
        set("race","�H��");
        set("gender","�k��");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("mirage-steps",60);
        set_skill("sword", 60);
        set_skill("godsword", 60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
        set("chat_chance", 6);
        set("chat_msg", ({
                "�I�A�N���ۻy�a���D�G�o�ӬI�������⨸�Ф@�z�H�è���h�F�C\n",
            (: random_move :),
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
      carry_object(__DIR__"wp/longsword.c")->wield();
     carry_object(__DIR__"eq/waist2.c")->wear();
}
