// yayi.c  �x���ŧ�
inherit NPC;

void create()
{
	set_name("�ŧ�", ({ "ya yi", "ya" }));
	set("gender", "�k��");
	set("age", 25);

	set("long", "�@�Ӱ��j�²r���~�l�A�]���[�b�x�����ơA�y�W�w�g�i�ұo�@�L���C\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	setup();
	carry_object(__DIR__"obj/yayifu")->wear();
}
	
