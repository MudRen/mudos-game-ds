#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�I�L��", ({ "shi wu shou","shi","shou" }) );
        set("gender", "�k��" );
        set("long",
            "�L�O�I�������ˡA�L���өʩM�I���o�O���[���O�A�L�H�y\n"
            "�W�Q�A�G���~�~��b���A���F�����~�ɪ����Z�Ӧb�~�Y�]\n"
            "�F�G�D�}�ΡA���Z�H�O�����}�Ѫ��C\n"
           );
        set("age",70);
        set("level",35);
       set_skill("unarmed",95);
        set_skill("parry",70);
        set_skill("dodge",85);
        set("chat_chance_combat",90);
        set("chat_msg_combat", ({
              "�I�L���H���D�G�c��I�h���a�I\n",
         }) );
        setup();
carry_object(__DIR__"eq/boots")->wear();
carry_object(__DIR__"eq/cloth")->wear();
}
