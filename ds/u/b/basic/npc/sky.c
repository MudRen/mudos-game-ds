#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�̤ѱN" , ({ "sky general","general" }) );
        set("long",
                  "�L�O�Ѧa�|�N���@�A\n"
                  "�ݰ_�Ө����B�����O�����誺�C�֦~\n"

            );
        set("title",HIR"�Ѧa�|�N��"HIC"�̤ѱN"NOR );
        set("level",34);
        set("race","�H��");
        set("gender","�k��");
        set("age",20);
        set_skill("sword", 75);
        set_skill("parry", 75);
        set_skill("dodge", 80);
        set("chat_chance", 5);


        setup();
       carry_object("/u/b/basic/wp/sword")->wield();
}
