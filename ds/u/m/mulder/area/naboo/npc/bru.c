
inherit NPC;

void create()
{
	set_name( "�c�~",({"bruiser"}));
	set("long","�o�Ӵc�~�����ۤQ�����ơA�ݨӤ��n�����C");
	set("gender","�k��");
	set("race","�H��");
	set("level",14);
	set("age",30);
	set("evil",100);
	set("chat_chance",50);
	set("chat_msg",({
"�c�~��M�^�Y���A�@��\n"
"�ֺu~~�o���O�A�Ӫ��a��\n"
}));
set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (:command("say �Ѥl�A�]����?�A���o���@��"):),
        }) );
	setup();
}
