inherit NPC;
void gun_handle();
void create()
{
	set_name("�A��𶤪�",({"tower leader","leader"}) );
	set("long",@LONG
�L�N�O�o�̪��A�涤���A�������Ӧ��o������u�L�A���_���Ӥ@�_�@
�_���A���O�Ⲵ���������A�ݰ_�ӤQ���F�m�C 
LONG);
	set("age",37);
	set("level",25);
	set("race","human");
	set("evil",-10);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�o�̤��O�A���ӨӪ��a��A�֥X�h�C");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: gun_handle :)
	}) );
	setup();
	set_skill("gun",80);
	set_skill("perception",80);
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/bulletclip_small");
	carry_object(__DIR__"../wp/gun_21")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_9")->wear();
	carry_object(__DIR__"../eq/iron_armor_21")->wear();
	carry_object(__DIR__"../eq/iron_boots_10")->wear();
	carry_object(__DIR__"../eq/iron_leggings_7")->wear();
	carry_object(__DIR__"../eq/iron_helmet_8")->wear();
	carry_object(__DIR__"../eq/iron_roundshield_7")->wear();
	carry_object(__DIR__"../eq/glasses_night_2")->wear();
	add_money("dollar",3250);
}

void gun_handle()
{
	object gun;
	gun=present("ck rifle",this_object());
	if(!gun) return;
	if(!gun->query_temp("loaded"))
	{
		command("reload clip");
		return;
	}
	command("shoot");
	return;
}