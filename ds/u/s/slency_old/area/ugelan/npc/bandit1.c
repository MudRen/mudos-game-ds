// garrison.c
#include <ansi.h>
inherit NPC;

void create()
{	
	set_name("�s��", ({ "bandit" }) );
	set("con", 19);
        set("age",30);
	set("str", 20);
	set_skill("blade", 50);
	set_skill("parry", 10);
	set_skill("unarmed", 50);
	set_skill("dodge", 20);
	set("attitude", "aggressive" );
	set("long",
	"�b�˪L���`�X�S���s��\n"
	"�L�ݰ_�Ӻ��y�Ͳ�, �@�ƥ��ڤڪ��ˤl�C\n"
	);
        setup();	
	carry_object(__DIR__"wq/blade1")->wield();
}
