#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѤH��" , ({ "old-man","man" }) );
        set("level",1);
        set("race","�H��");
        set("gender","�k��");
        set("age",67);
        set("long","�R�U�Ѫ��ѤH���@�C\n");
        set("chat_chance", 5);
        set("chat_msg", ({
             "�ѤH�һ�:�ѤH���A�쩳�|���|�U��??\n",
                       }));

                setup();
        
}

