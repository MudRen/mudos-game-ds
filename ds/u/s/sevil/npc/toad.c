#include <ansi.h>
inherit NPC;
void create()
{
    set_name(HIB"����"NOR, ({ "toad" }) );
        set("title", HIW"���J���d��"NOR );
        set("nickname", HIR"�୮���Ǫ�"NOR);
        set("long", "�@���୮������A�ݤF�O�H�Q��L�@�}�C\n");
	set("level", 10);
    set("age",3);
	set("chat_chance", 8);
        set("gender","�k��");
    set("limbs", ({ "�Y��", "����", "����" }) );
    set("verbs", ({ "bite", "claw" }) );
    set_skill("unarmed",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
        add_money("coin",100000);
}

void init()
{
	call_out("delay",2,this_player());
}
void delay(object me)
{
    tell_object(me,this_object()->name()+HIC"��A���G�o�򦭴N�Ӭݨ��J�j�H��!!\n"NOR);
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}
