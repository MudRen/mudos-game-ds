#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(RED"�����u�@�~"NOR, ({ "fire beast","beast" }) );
        set("long","�L�W�^�����Ӫ��u���~���@�A�ͩʨIí�C\n");
        set("race", "���~");
        set("gender","����");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        HIR"�u�å��~�b�A���|�g�娫�A���������I\n"NOR,
	}));
        setup();

}

void die()
{
          object obj;
  
	message_vision( "$N"+RED "�{���e�A�g�D�X�{�@�}�����A�����v���զX���@�󲯥ҡC\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_armor.c");
	obj->move(environment(this_object() ) );

	::die();
	return;
}
