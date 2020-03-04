#include <ansi2.h>
#include <path.h>
inherit NPC;
void create()
{
        set_name(HIG"�줧�u�@�~"NOR, ({ "wood beast","beast" }) );
        set("long","�L�W�^�����Ӫ��u���~���@�A�O�̷Ź����@���C\n");
        set("race", "���~");
        set("gender","����");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("int", 60);
        set("combat_exp", 30000);

	set_temp("apply/armor", 10);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"�u���~���M�������ݵۧA�A�A�����q���z�e�b�Q����C\n"NOR,
	}));
        setup();

}

void die()
{
	object ob,obj,room;
	room=load_object(SDO_PAST+"nonhero/grav6");
  
	message_vision( "$N"+HIG "�{���e�A�g�D�X�{�@�}�����A�����v���զX���@���ޡC\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_shield.c");
	obj->move(environment(this_object() ) );
	room->delete_temp("opened");
	
	::die();
	return;
}