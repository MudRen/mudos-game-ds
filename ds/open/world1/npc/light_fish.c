#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"���n��"NOR,({ "fish" }) );
         set("level",14);
        set("race", "���~");
        set("age", 1);
        set("long", "�o�O�����֨����@�س���, �q�`���O�~��b���}�����C\n");
        set("limbs", ({ "���_", "���_", "���_", "����", }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 5);
        setup();
      carry_object(__DIR__"../obj/light_cloth");
}