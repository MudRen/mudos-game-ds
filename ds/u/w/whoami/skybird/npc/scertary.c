
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�k����",({"scertary",}));
 set("long","�A�Ĥ@������o, �z! ���@�r���v�ϧA�b�F....
             �Ӧo���u�@��O�]��M�ܱj.....\n"
            ",\n"
    );
 set("attitude","peaceful"); 
 set("age",20);
 set("gender","�k��");
 set("combat_exp",124753+random(38358));
 set("level",10);
 set("title","���y��");
 set_skill("unarmed",55);
 set_skill("force",85);
 set_skill("parry",70);
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",20);
 set("chat_msg", ({"�k���ѼL�̳�����: �P���@�n�U�Ȫ����|�]�ܭ��n.....\n",
                   "�k���ѩ�_�Y�ӻ�: �аݧA������ƶ�..? .\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert slash-wood cross-slash":),
                         (:command,"exert slash-wood all-slash":),
                         (:command,"exer
t cloudmove ghostmove":),
                         (:command,"say �ۭt�k��!! �Ǫk�C!! ":),
 }));
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}