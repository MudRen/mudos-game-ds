#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���j��",({"yung da ma","ma"}) );
        set("long",
            "�o�O�I���������A�o���b�N�ۤp��A�o���ۤ@�Y�������Y�v\n"
            "�A�y���@���J�몺���ΪΪ��C\n"
            );
        set("age",30);
        set("race","�H��");
        set("level",5);
        set("gender", "�k��" );
        set("chat_chance",5);
        set("chat_msg",({
            "���j�����D�G��ߡI�i�O�S�ۤF�C\n",
        }));
        setup();
carry_object(__DIR__"eq/boots2")->wear();
}
