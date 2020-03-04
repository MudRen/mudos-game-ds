#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѤH",({"old man","man"}));
 set("long",@LONG
�@�Ӭݰ_�Ӭ۷��Z���ѤH.
LONG
    );
 set("attitude", "peaceful");
 set("age",72);
 set("gender","�k��");
 set("level",20);
 set_skill("sky-dagger",20);
 set("chat_chance_combat",200);
 setup();
}

void init()
{
        add_action("do_ask","ask");
	add_action("do_say","say");
}

int do_ask(string arg)
{
      object me;
      me=this_player();
      if (arg != "man about name") return 0;
      message_vision(YEL"$N��ѤH�ݰ_�L���W�r�C\n"NOR,me);
      message_vision(YEL"�ѤH���D: �ѤҪ��W�r���󭫭n, ��n�A���C\n"NOR,me);
      me->set_temp("know_name",1);
	return 1;
}

int do_say(string arg)
{
      object me;
      me=this_player();
      if (arg != "����۷�����P, �ߦ��ѱ��Q�d�@") return 0;
	if(me->query_temp("know_name") == 1) 
	{ 
	message_vision(YEL"$N�ۨ��ۻy����: ����۷�����P, �ߦ��ѱ��Q�d�@�C\n"NOR,me);
	me->set_temp("speak",1);
	 call_out("speak",1,me);
             return 1;
	}
	else
	{
	message_vision(YEL"$N�ۨ��ۻy����: ����۷�����P, �ߦ��ѱ��Q�d�@�C\n"NOR,me);
	message_vision(YEL"���ѤH���@�L�ʩ�J�C\n"NOR,me);
	    return 1;
	}
}


void speak()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=me->query_temp("speak");
      switch( i ) {
          case 1:
            command("say �� ! �p�S�̬O��B�o���o�y�ܪ� ?!");
            message_vision(YEL"�ѤH���M�@�_ , �W���D : ���O�L���ƤF ...�󥲦b�G..\n"NOR,me);
	    message_vision(YEL"�ѤH�W���D : �٬O�Q�p�S�̮M�X�ܨӤF...�ѤҦ椣��m, ������W, �m�s�W�����K�O !\n"NOR,me);
            obj->set("name","�s����",({"lung ain uin","lung","uin"}));
	    obj->set("title",BLU"�p�Q�@��"NOR);
	    obj->set("long","��ӥL�N�O�ѱ��ĤQ�C�N�x�� -- �p�Q�@�� �s���� !! \n�A�o�{�L���W�G�M���@�ѫD�Z����, �G\�M��\�\\�O\��\���x��, \n�N�O���@�� !! \n");
		break;
		}
}
