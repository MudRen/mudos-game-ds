#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�j�T��", ({ "dog" }) );
        set("race", "���~");
        set("age", 7);
        set("long", "�@���i�R�w�j�T���C\n");
        set("str", 30);
        set("cor", 20);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 500);
        set("potential", 10);
        set_temp("apply/attack", 15);
        set_temp("armor", 3);
        set("chat_chance", 10);
        set("chat_msg", ({
                HIY"�j�T����ۧA�g�p�G�L!�L..�L..�C"NOR"\n",
                (: random_move :),
        }) );
        setup();
}

