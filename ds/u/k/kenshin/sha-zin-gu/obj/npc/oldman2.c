#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѤH��" , ({ "old-man","man" }) );
        set("level",1);
        set("race","�H��");
        set("gender","�k��");
        set("age",73);
        set("long","�R�U�Ѫ��ѤH���@�C\n");
        set("chat_chance", 5);
        set("chat_msg", ({
             "�ѤH����:�ѤH�ҬO�A���|�U�a!!\n",
                       }));

                setup();
        
}

