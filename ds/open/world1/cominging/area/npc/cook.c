#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�Ѽp",({ "cook" }));
	set("long","�@�Ӧ~���w���ڪ��p�v�C\n");
	set("race","�H��");
	set("age",32);
	set("level",6 );
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"sweat" :),
  (: command,"say �n���r�I" :),
  (: command,"�ȭ����ӯ��ܨ�ťť�a." :),
  (: command,":)" :),
}));
	setup();
	add_money("coin",20);
}