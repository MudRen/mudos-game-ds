#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIY"�����u�@�~"NOR, ({ "gold beast","beast" }) );
        set("long","�L�W�^�����Ӫ��u���~���@�A�ʱ��ݼɡC\n");
        set("race", "���~");
        set("gender","����");
        set("level",30);
        set("age",200+random(20));
	set("attitude", "aggressive");

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"�u�å��~�C�q�@�n�A���A���I�J�D�`����I\n"NOR,
	}));
        setup();

}

void die()
{
	object obj,room;
	room=load_object(SDO_PAST+"nonhero/grav5");
  
	message_vision( "$N"+HIY "�{���e�A�g�D�X�{�@�}�����A�����v���զX���@����j�C\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_pike.c");
	obj->move(environment(this_object()));
	room->delete_temp("opened");

	::die();
	return;
}