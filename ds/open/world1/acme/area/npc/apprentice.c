#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���Z�ĤT�N�̤l" , ({ "apprentice" }) );
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("age",18);
        set("int",19);
        set("str",5);
        set_skill("sword",10);
        set_skill("godsword",10);
        set_spell("god-fire",25);
        set_skill("parry",5);
        set_skill("dodge",10);
        set("long","�L�O���Z�вĤT�N�Ĥl�A���b�o�̶Խm�Z�\\�C\n");
        set("chat_chance", 3);
        set("chat_msg",({
            "���Z�ĤT�N�̤l�ܹD�G�����\n",
            "���Z�ĤT�N�̤l�⤤�u�����N�V��H�C\n",
        }) );
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            (:command("exert godsword"):),
            (:command("cast god-fire"):),
            "���Z�ĤT�N�̤l�ܹD�G�S�̡̭I��o�å뵹�_�F�I\n",
        }) );
        setup();
        carry_object(__DIR__"wp/sword2.c")->wield();
}
