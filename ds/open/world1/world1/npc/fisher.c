inherit NPC;

void create()
{
	set_name("����",({ "fisher" }) );
	set("long","�@�ӥ����b�e��B���۳���A�y���a���������ȡC\n");
	set("race","�H��");
	set("age",25);
	set("level",3);
	set("attitude","friendly");
	
	set("chat_chance",10);
	set("chat_msg",({
	(:command("say ���೽��֤W���A�n�����ݲK�f�֡C"):),
	(:command("say �ͥ��̤j�֨ơA���~�G�u�W�糽���v�A�������I�I�C"):),
	}) 
	);
	set_skill("staff",10);
	set_skill("parry",10);
	set_skill("dodge",5);
	set_skill("unarmed",5);
	setup();
	carry_object(__DIR__"../wp/rod")->wield();
	carry_object(__DIR__"../eq/suncap")->wear();
}
