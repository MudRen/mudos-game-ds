#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ȤH" , ({ "traveler" }) );
        set("level",4);
        set("race","�H��");
         set("gender","�k��");
        set("age",35);
        set("long","�L�O�@�쥿�b�������ȤH�C\n");
        set("chat_chance", 3 );
        set("chat_msg",({
           "�ȤH���D�G�֨�F�I�F�䤣���B�N�O�ѫ��F�C\n",
           (:command("sweat"):),
        }) );
        setup();
}

