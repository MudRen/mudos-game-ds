#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ȤH" , ({ "traveler" }) );
        set("level",4);
        set("race","�H��");
        set("gender","�k��");
        set("age",35);
        set("long","�L�O�@��Ȧ�@�ɦU�a���H�C\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "�ȤH���D�G�z�I�n�����Ѧ��r�I\n",
           (:command("smile"):),
        }) );
        setup();
}

