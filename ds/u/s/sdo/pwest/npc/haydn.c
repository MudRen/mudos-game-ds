#include <ansi2.h>

inherit NPC;

string do_book(); // void -> string by -alick@ds-

void create()
{	
	set_name("���y", ({ "haydn"}) );
	set("long", @LONG
�{�b���b�A���e���H�N�O�������y�C�L�O�b�o�̦�̤[���H�A�p�G��
�Q�n���D���򱡳��A�ݥL�N��F�C�ӥB���p�D�������L���@��S��
�n�͡A�����|��b�L�a�G�ӡC
LONG);
	set("level",30);
	set("age",70);
	set("race","�H��");
	set("gender","�k��");
	set("combat_exp", 5000);
	set("title","����");

	set("talk_reply","�u�O�дo��...\n");
	set("inquiry", ([
		"�g���˪L" : "�g���˪L�N�O���o�@�j�����˪L�C\n",
		"�дo" : "�N�O�̪񦳤@�s�Ǫ��E�b����������A�����|�b��������v�h\n"
    			"�A�u�O�H�дo�C�����D�֯���ѨM...\n",
		"���y" : "�N�O���H�A�Q�n�Ӥ@�M�ܡH\n",
		"�q�L��k" : this_object()->do_book(),
	]));

	setup();
}

string do_book()
{
	object book,me;
	me=this_player();

	if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==1) 
	{
		book->add_quests_note("fogforest",
			"�����D��J�����̤j���D�O����....�A�]�\\�ڸӥ|�B��ť�@�U�C\n");
		me->set_temp("sdoquest/step1",2);
		return "�q�L����k��....�i�O�ڤ��७�ժ��i�D�A�C�o�˧a�A\n�p�G�A��ѨM�����̤j�����D�A�ڴN�|�i�D�A���C\n";
	}
}

int accept_object(object me,object ob)
{
        object obj,book;
        obj=this_object();
	if(!objectp(book=present("adventure notebook",me))) return 0;
        if(ob->name()!="�P�«H")
        	return notify_fail("���§A�A���O�ڤ��ݭn�o�ӡC\n");
        if(obj->is_busy() )
        	return notify_fail("�ڲ{�b�S�šI�I\n");
        message_vision("$N���F$n�@��"+ob->query("name")+"�C\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        message_vision(
        "$n�C�Y�ݵ۷P�«H�A�ݧ����ҤF�@�|�A���$N���D�G�y�A�������X�F���֤ߤO�A�ڤ]���n�N�����f�A�F�Q�n\n"
        "���D�p��q�L�g���˪L�A��G�ӥh��(inquiry)��Y�R�a�I�o�|�i�D�A���C\n",me,obj);
        if(book)
        {
        	book->add_quests_note("fogforest",
        	"�ש�i�H���D�q�L�g���˪L����k�F�A�֥h���X��Y�R�a�C\n");
               	me->set_temp("sdoquest/step2",2);
        }
        return 1;
}
