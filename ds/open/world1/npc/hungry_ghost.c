#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�j����", ({ "hungry ghost","ghost" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",18);
        set("age",500);
        set("evil",5);
        set("attitude","aggressive");
        set("long",@LONG
�b�Զä��j��������A�b�H���g���F�Ӧh�h�W�o�S������
���A�]�Ӥ��o��J���j�C
LONG
);
        set("chat_chance",10); 
        set("chat_msg",({
                "�j�������Ū����餣�_���X���Y�U�h���F��C\n",
        }) );
        setup();
}

