
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ�������",({"bird waiter","waiter"}));
 set("long","�A�ݤF�ݲ��e�������p��, �u�Q�_�ѱ����ҿת�[�@��, �G�b, �T���P],\n"
              "�o�y�ܨ�, �ݨӳo�y�ܯu���O�û���.\n"
    );
 set("attitude","peaceful"); 
 set("age",18);
 set("gender","�k��");
 set("level",10);
 set_skill("unarmed",30);
 set("chat_chance",5);
 set("chat_msg", ({"�����Ϯ�Ԫ��K���F��W�����M.\n",
                            "�����ϱN��l���F�@�� .\n",
                   (:command("sweat"):),
 }));

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
