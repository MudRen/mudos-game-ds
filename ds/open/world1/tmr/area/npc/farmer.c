inherit NPC;

void create()
{
	set_name("�A��",({"farmer"}) );
	set("long",
"�@�쥿�s�y�B���}���b�и̴������A�ҡA�@�L���W�������I�v�A�O�H\n"
"���Ѧa���q�߸̷P�¹A�Ҳצ~�����ҡC\n"
	);
	set("age",33);
	set("level",5);
	set("race","�H��");
        set("attitude", "peaceful");
	set("unarmed",20);
	set("chat_chance",5);
	set("chat_msg",({
 	"�A�Ұ��n�u�D�G�u�S�����ȡ@���v�C\n",
 	"�A�Ұ��n�u�D�G�u���w�ݤU�g�@���v�C\n",
	(:command("sweat"):),
 	"�A�Ұ��n�u�D�G�u�֪��L�����@���v�C\n",
 	"�A�Ұ��n�u�D�G�u�ɲɬҨ��W�@���v�C\n",
	}) );
	set_skill("unarmed",20);
	setup();		
        add_money("coin",100);
}
int accept_fight(object who)
{
	if(!is_fighting())
	{
		command("angry");
		say("�A�һ��D�G�u�o��"+RANK_D->query_respect(who)+"�A�p�����O�U�o���Цa�A�N�����H�F�C�v\n");
	}
	return 0;
}
