// Npc: /u/t/truewind/npc/1.c

inherit NPC;

void create()
{
	set_name("�j��", ({"Big Bill","Bill"}) );
	set("long", "�s�]������A�o�Y�έ�����ҤH�A���_�Ӥ@�f�y���ժ��i�ȡC
�A�p�G�Q���D�o����o�ͪ��Ʊ��A�i�H�յ۸�L���(talk with bill)�C\n");
	set("race", "�H��");
	set("age", 150);
	set("level", 25);
        set("title", "�s������");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("hehe") :),
       (: command("say ���Ѧ����֫ȤH��...") :),
}));


	setup();

}

