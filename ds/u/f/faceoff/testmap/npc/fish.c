#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"���u��"NOR,({ "gold line fish","fish" }) );
         set("level",10);
        set("race", "���~");
        set("age", 1);
        set("long", "�o�O�������̱`���쪺����, �P�ɥ����׻��]�O�̬��G�����C\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"obj/fish_meat");
}