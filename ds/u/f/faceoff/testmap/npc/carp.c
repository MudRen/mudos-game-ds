#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�U��",({ "carp" }) );
         set("level",13);
        set("race", "���~");
        set("age", 2);
        set("long", "�@���U��, �����׽��A��, �@���O�ӤH���̷R�C\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/carp_meat");
}