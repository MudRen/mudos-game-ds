// yufeng.c �ɸ�

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "�ɸ�" NOR, ({"yufeng","feng","bee"}) );
	set("race", "���~");
	set("age", 8);
	set("long","�o�O�@�u�ɦ⪺�e���A���Y�񴶳q�e���j�o�h�A\n�ͻH�W�Q�H�Φy�w�릳�r�C\n");

	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"�ɸ��b�A�Y����F�@��A���G�o�{�o���O�i���e���a��A�N����a�����F�C\n",
"�ɸ���¶���A�᭸�������A���G�]���ۭ��b���e�W�C\n",
	}) );

	setup();
}
