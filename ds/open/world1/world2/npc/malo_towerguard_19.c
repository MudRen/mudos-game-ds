inherit NPC;
void greeting(object ppl);
void create()
{
	set_name("�A���ĵ��",({"tower guard","guard"}) );
	set("long",@LONG
�@�Ӧ~�����A�涤���A���b�o�̨��ޡC
LONG);
	set("age",26);
	set("level",19);
	set("race","human");
	set("evil",-15);
	set("exp_point",2);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...

	set("talk_reply","�o�̤��O�A���ӨӪ��a��A�֥X�h�C");
	setup();

	carry_object(__DIR__"../wp/iron_blade_16")->wield();
	carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
	carry_object(__DIR__"../eq/cloth_pants_7")->wear();
	carry_object(__DIR__"../eq/iron_armor_16")->wear();
	carry_object(__DIR__"../eq/iron_boots_9")->wear();
	carry_object(__DIR__"../eq/iron_leggings_7")->wear();
	carry_object(__DIR__"../eq/iron_helmet_8")->wear();
	add_money("dollar",840);
}
