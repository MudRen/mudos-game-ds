#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѹ�" , ({ "mouse" }) );
        set("level",10);
 set("race", "���~");
        set("limbs", ({ "�Y��", "����","�ݳ�","�p��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
    set("chat_chance",10);
        set("age", 50);
        set("long","�@���D�`��ż���ѹ��C\n");
        setup();
}

