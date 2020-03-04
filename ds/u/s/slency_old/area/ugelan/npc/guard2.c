// garrison.c
#include <ansi.h>
inherit NPC;

void create()
{
	set("chat_chance", 4);
	set_name("�c���ͽ�", ({ "palace guard","guard" }) );
	set("con", 19);
        set("age",30);
	set("str", 20);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set("long",
	"�Ӯc�c���u��, ����H�i�X�Ӯc\n"
	"�L�ݰ_�Ӷ������j, �۷����H���I���ˤl�C\n"
	);
        setup();	
	carry_object(__DIR__"wq/guardsword")->wield();
}

void init()
{
	add_action("do_guard", "go");
}

int do_guard(string arg)
{

	if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
	write( name() + "�N�A�d�F�U�ӡC\n");
	command("say �o��ȫȽФ�B, �Ӯc�T�a���ǥ��N�i�X, �ЧA���n�����ڡC");

	return 1;
	}
