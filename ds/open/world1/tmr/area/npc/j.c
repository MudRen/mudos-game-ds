// junkman.c

inherit NPC;

void create()
{
	set_name("�B����Y", ({ "junkman" }));

	set("age", 66);

	set("long",
		"�@����ܼ���B����Y�M�a�߬B�o�����͡M�p�G�A�@�N���U�o�ˤ@��\n"
		"�ѤH�L�n�@�I���ͬ��M�Ϊ̬O�@�N�����W���Ův�̸`�٤@�I�O����\n"
		"�M�Ч�A���W�h�l���F�赹�L�C\n"
	  );

        set("chat_chance", 20);
        set("chat_msg", ({
                "�˯���Y�[�ܹD�R����}��������\n",
                "�˯���Y���L�̹ʾ��ۡM�����D���Ǥ���C\n",
                "�˯���Y���⮻��F���W�����l�M�@�}��o��󪺡C \n",
                (: random_move :)
        }) );
	setup();


	// Always flee.
	set("max_gin", 100);
	set("max_kee", 100);
	set("max_sen", 100);
}


