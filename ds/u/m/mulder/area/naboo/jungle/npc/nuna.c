#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"�|��"NOR, ({"nuna"}) );
        set("race", "���~");
        set("age",12);
        set("level",9);
        set("attitude","aggressive");
        set("long", HIY"�|��Naboo�˪L���g���ͪ��C\n"NOR);
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("chat_chance",45);
        set("chat_msg",({
	(: "random_move" :),
        }) );
      set_skill("mob_bite",10);
      set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
       	 }) );
        set("verbs", ({ "bite", "claw","crash" }) );
        setup();
}
