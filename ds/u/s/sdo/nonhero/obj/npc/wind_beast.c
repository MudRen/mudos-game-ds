#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(HIC"�����u�@�~"NOR, ({ "wind beast","beast" }) );
        set("long","�L�W�^�����Ӫ��u���~���@�A��ʱӱ��C\n");
        set("race", "���~");
        set("gender","����");
        set("level",30);
        set("age",200+random(20));

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("dex", 60);
        set("combat_exp", 30000);
	set_skill("dodge", 100);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIR"�u�å��~�����t���ʡA�ϧA�����Y������C\n"NOR,
	}));
        setup();

}

void die()
{
	object ob,obj;
  
	message_vision( "$N"+HIC "�{���e�A�g�D�X�{�@�}�����A�����v���զX���@���H�ҡC\n" NOR ,this_object() );

	obj=new(__DIR__"obj/rust_leggings.c");
	obj->move(environment(this_object() ) );

	::die();
	return;
}