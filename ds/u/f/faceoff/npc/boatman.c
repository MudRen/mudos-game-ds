#include <ansi.h>
inherit NPC;
void create()
{
 set_name("��Ѥj",({"boat man","man"}));
 set("long","�L�O�L���q���߮�@�a����ҡC\n");
 set("age",41);
 set("gender","�k��");
 set("level",10);
 set("chat_chance",20);
 set("chat_msg", ({"��Ѥj��I�I����: ��S�}�O�Ѥl����? ���ت��N��Ѥl�F�W�@�[!.\n",
	           "��Ѥj��I�I����: �h�ݮ��F�q���t��l�̰�! �L����, �@�iñ�X���]�o���U��.\n",
                            (:command("pig"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","����? �S�Ӥ@�өǦѤl��? �L����"+HIG+"�°�"+NOR+"......!\n"NOR);

	set("inquiry/�°�","�N�O���Ө���l! �ִ�����L��"+HIG+"Ŷ�ަ�"+NOR+", �O���t��l�s���]�񤣥X�@��!\n"NOR);

	set("inquiry/Ŷ�ަ�","�N�O�o����ู��! �n���O���F�q����Y�ն���, ��|�s�@�i"+HIG+"ñ�X��"+NOR+"���o���X��?.\n"NOR);

	set("inquiry/ñ�X��","���]�O���F�q����H�o�X�Ӫ����F��! �����S���o������, �ڥ��O�¤ߧ��....\n");


 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}

