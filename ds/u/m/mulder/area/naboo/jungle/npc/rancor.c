#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"�ť["NOR, ({"rancor"}) );
        set("race", "���~");
        set("age",10);
        set("level",10);
        set("attitude","aggressive");
        set("long",HIY"�@���i�Ȫ����׳��~�C�L���@�藍����Ҫ����u�A���j���y���M�U�Q�����C\n"NOR);
        set("limbs", ({ "�Y��", "����", "�e��", "��}", "����" }) );
        set("chat_chance",65);
        set("chat_msg",({
	(: "random_move" :),
        }) );
      set_skill("mob_bite",10);
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (:command("exert mob_bite sacer"):),
           	 }) );
        set("verbs", ({ "bite", "claw"}) );
        setup();
}
