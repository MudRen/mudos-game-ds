// NPC: /d/ruzhou/npc/meipo.c �u�B�z���B�P����
// llm 99/06/04 �ק�

#include <ansi.h>

inherit NPC;
//inherit F_CLEAN_UP;

int do_marry(string arg);
int waiting(object ob);
int do_name(string target);
int do_chase(object ob);
int do_ok(object ob);
int meipo_waiting(object ob,object me,object obj);
int ready_marry(object ob,object me,object obj);
int wait_marry(object ob,object me,object obj);
int start_marry(object ob,object me,object obj);
int do_back(object ob);
int do_bai(string arg);

void create()
{
	set_name("�C�C", ({ "meipo","po" }) );
	set("title", HIM""NOR);
	set("gender", "�k��" );
	set("age", 43);
	set("long",
		"�@������z���ѴC�C�C\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("inquiry", ([
		"���B" : "�C�C���N�N�a�I�Y�D�G���O��... �n���B(marry)��M�n��ڨӰ��C���r�I��\n",
		"marry" : "�C�C���N�N�a�I�Y�D�G���O��... �n���B(marry)��M�n��ڨӰ��C���r�I��\n",
      "�n�O" : "�C�C���N�N�a�I�Y�D�G���O��... �n���B(marry)�n�O��M�n��ڨӰ��C���r�I��\n",
		"���B" : "�C�C�y��@�ܡA���I�j�j�a���D�G���n...���B(unmarry)�H��...�I�ڥi�O�ݧA�̦��B���r�I\n"
      	"���L�A�̭n�O�@�w�n�����ܡA���o�h���{�����B��z�F�I��\n",
		"unmarry" : "�C�C�y��@�ܡA���I�j�j�a���D�G���n...���B(unmarry)�H��...�I�C���O�ڧ@\n"
      	"���A�u�n�ѧڿ�A�u�O�@�ڡI��\n",
      "�O��":"�C�C�H�H���D�G�����B�o�\�j���ơA��O���a��i���֡A�n50 gold�A,�����B\n"
      	"��n��O���ֿ��A�ҥH�n100 gold�C��\n",
	]) );
	set_skill("literate", 100);
	set_skill("dodge", 500);
	set_skill("unarmed", 300);
   setup();
	add_money("gold", 4);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	::init();
	add_action("do_marry", "marry");
   add_action("do_bai","��");
	add_action("do_name","��");
}

int accept_object(object me, object ob)//���
{
   if (!ob->query("money_id"))
     	return notify_fail("�C�C�H�H���D�G���ڦѱC�l���Y���ܤ������\§�A�z�٬O���^�h�a�I��\n");
	if(!me->query_temp("ask_money"))//�ѤU���P�_������H�O�_�ŦX���B����C
   	return notify_fail("�C�C�g�b�a�ݡG���A�Q�z���\�H�յ��ڿ��H��\n");
  	if(ob->value() < 500000)
	      return notify_fail("�C�C�K�F�K���Y���D�G�����Ӥ֤F�a�H50 gold�A���B�o�\�j���ơA�A�ִN����F�C��\n");
	message_vision("�C�C���L����$N���G���o��"+RANK_D->query_respect(me)+"�ڥi�S�ȧA�����A�b�|����٭n�iù�߰�B��\n"
   		"�n���H�B�٦���s�b�A�d���n���ٱo�ߤW�@�I���I�ӥB���٥i�H���A�o�Ч��A\n"
         "�A�i�H��J���� <�Y�H�����W>���C��\n",me);
	this_object()->set_temp("marry/money",me->name());   //�O�����L�����H
  	return 1;
}

int do_name(string target)//�ЫȤH
{
	object me,ob,dest, *all;
	int i;
	me = this_player();
	ob = this_object();
	all = users();

	if (me->is_busy())
		return notify_fail("�C�C���D�G���A�����Z�A�M�ڻ��ܧa�I��\n");
	if( ob->is_fighting()||me->is_fighting() )
		return notify_fail("�C�C���D�G���{�b�S�\�ҡI��\n");
	if( !living(ob) )
		return notify_fail("�A�٬O���Q��k��C�C�Ͽ��a�C\n");
	if((string)ob->query_temp("marry/money")!=(string)me->name())
      return notify_fail("�C�C�פF�קA�G���A�S�S����I��\n");
	if(ob->query("waiting_target"))
		return notify_fail("�C�C�������G�����n��A�ڪ��p���N���٨S�����^�өO�I��\n");
	if( !target || target==" ")
		return notify_fail("�C�C��X�@�i�ЬZ�g�F�L���ݡG���A�Q�н֨Ӱѥ[�A���B§�H�i�D�ڥL(�o)���W�r�I��\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->query("id") )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("�C�C�i�D�A�G���ܿ�ѡA�z�Q�Ъ��H�L�{�b���b�������I��\n");
	if (dest->is_ghost())
   	return notify_fail("�C�C�����a�a�i�D�A�G���ڧڭ̩Ҫ��A�z�n�Ъ��H�w�g���F�A�z�и`�s���K�I��\n");
	ob->set("waiting_target", dest->query("id"));
	ob->set("me_name", me->query("name"));
	ob->set("me_id", me->query("id"));
	message_vision(HIG"�C�C�@�i�߬Z�W�g�W�L�Ӧr�A����@��A�q�F�Y�N���X�@�u�p���N�A�ε۳ߩ��A\n"
   "���h�h�a�@�U�l�����b�ѪŤ��F�C\n" NOR,me);
	call_out("do_chase", 1, ob);
	return 1;
}

int do_chase(object ob)//���N�e�ЬZ
{
	object dest,obj;
	dest = find_player(ob->query("waiting_target"));

	if( !objectp(dest) || !environment(dest) )
	{
		call_out("waiting", 0, ob);
		return 1;
	}
	message_vision(HIY"�ѪŤ���M���L�Ӥ@�u����N�A���b$N���Y�A�N�ε۪��@�i�߬Z����$N�C\n" NOR, dest);
	obj = new(__DIR__"obj/xitie");
   obj->set("name",HIR+(string)ob->query("me_name")+"("+(string)ob->query("me_id")+")"+"�����B�Щ�" NOR);
	obj->move(dest);
	call_out("do_ok", 0, ob);
	return 1;
}

int waiting(object ob)//���N����
{
	object dest;
	dest = find_player(ob->query("waiting_target"));

	if ( objectp(dest)&&dest->is_ghost() )
	{
			ob->delete("waiting_target");
			call_out("do_ok", 1, ob);
			return 1;
	}
	remove_call_out("waiting");
	call_out("waiting", 60, ob);
   return 1;
}

int do_ok(object ob)//���N�e�Z���\�^��
{
	message("vision", "��M�ݨ�����N�q���~���i�ӡA���b�C�C���ǡA�C�C���N�N�a���۪���N���Y�Z\n"
		"���D�G���ЬZ��~�w�g���e��F�I�z�ٷQ�н֡H���Q�ФF�N�}�l���B����(marry sb.)�a�I��\n", environment(), ob);
  	ob->delete("waiting_target");
	ob->delete("me_name");
	ob->delete("me_id");
	return 1;
}

int do_marry(string arg) //�P�_���B
{
	object obj, me,ob,old_target;
	me = this_player();
	ob = this_object();
	if ( (string)me->query("gender") == "�L��")
		return notify_fail("�C�C��F�@�n�G���A�L�ڵL�ʡA���Ӥ��\�B�H�I��\n");

	if (((int)me->query("age") < 18) && (me->query("gender") == "�k��")
		||((int)me->query("age") < 16) && (me->query("gender") == "�k��"))
		return notify_fail("�C�C���H�H�a���D�G���A�̲{�b�٦~���A�H�Z�A���a�I��\n");
	if (me->is_busy())
		return notify_fail("�C�C���D�G���A�{�b���O�����۶ܡH��\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me);
		return notify_fail("�C�C���D�G���n�A�n�A�ѮQ�e�A�h�������B�I��\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("�C�C���D�G���S�ݨ��o�঳�H�o�öܡI��\n");

	if( !living(this_object()) )
		return notify_fail("�A�٬O���Q��k��C�C�Ͽ��a�C\n");

	if( me->is_fighting() )
		return notify_fail("�C�C���D�G�K�K�A�A���٬O�Ʋz���A���B�ͦA���a�I\n");

	if( !environment() || base_name(environment()) != query("startroom"))
		return notify_fail("�C�C���D�G���u��p�A�ڲ{�b�ܦ��A�бz���@�|����Q�ܨӧ�ڧa�C��\n");

	if( (string)me->query("class")=="bonze"||(string)me->query("jobname")=="bonze" )
		return notify_fail("�C�C���D�G�������I��\�A�H�򪺤]�Q�}��٤F��?��\n");

	if( (string)me->query("jobname")=="taoist" )
		return notify_fail("�C�C�n�F�n�Y�D�G���A�פF�D���٬O�Z�ߤ��{�A���I�A�n�O�u�Q�A�٬O�٤F�U�A�ӧa�I��\n");

	if(!arg ||!find_player(arg) )
		return notify_fail("�C�C�ݹD�G���A�Q�M�ֳߵ��}�t�H��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("�C�C���D�G�����B�i�O�n��ӤH�@�_�Ӫ��r�I��\n");

	if( me->query_temp("pending/pro"))
		return notify_fail("�C�C�_�D�G���x�H�A���B§���O���b�i�椤�ܡH�٭n�ݤ��\�H��\n");

	if( obj->query_temp("pending/pro") )
		return notify_fail("�C�C���D�G���A�Q���O�H�ͧ��ܡH��\n");

	if( !obj->is_character() )
		return notify_fail("�C�C���D�G���A�o���O���ۤv�}�R�ܡC��\n");

	if((string)obj->query("class")=="bonze"||(string)me->query("jobname")=="taoist")
		return notify_fail("�C�C���D�G�����I"+ obj->name() +"�i�O�X�a�H�A�O��H�a�}�����F�C\n");

	if( mapp( me->query("couple")))
	{
      if ((int)me->query("couple/married")>2)
	      return notify_fail("�C�C½�F½�ýtï�A�O�U�y���D�G���ڦ��N��A���L�A��\�S�ӤF�H\n"
   	   "�o���ڹ�b�������A���\�F�A�A���B���ƤӦh�F�A���§ʺ����A�O��\n"
      	"��A��z���B����F�A�A�̥h���ﳥ�p�m�a�I\n");
		if ( me->query("couple/have_couple") )
		{
			if ( obj == present((string)me->query("couple/couple_id"), environment(me)) )
				return notify_fail("�C�C�_�D�G���A�̥��ӴN�O�ҩd�r�I�z���٭n�A�ӡH��\n");
			if ((string)me->query("gender") == "�k��")
				return notify_fail("�C�C���D�G���A�w�g�O���Ҥ����F�A�o�������\���B���C��\n");
			else
				return notify_fail("�C�C���D�G���A�w�g�O�������ҤF�A�o�������\���B���C��\n");
		}
	}
	if( mapp( obj->query("couple") ) )
	{
      if ((int)obj->query("couple/married")>2)
	      return notify_fail("�C�C½�F½�ýtï�A�ĤF�f��D�G������A�̻��L�A��\�S���F�A�o\n"
   	   "���ڹ�b�������A�̤��\�F�A�A�O�S���D�A��"+obj->name()+"���B���ƤӦh�F�A\n"
      	"���§ʺ����A�O����A��z���B����F�A�A�̥h���ﳥ�p�m�a�I\n");
     	if( obj->query("couple/have_couple") )
		{
			if((string)obj->query("gender") == "�k��")
				return notify_fail("�C�C���D�G�i���o�w�g�O���Ҥ����F�A�o�������\���B���C\n");
			else
				return notify_fail("�C�C���D�G�i���L�w�g�O�������ҤF�A�o�������\���B���C\n");
		}
	}
	if( !living(obj) )
		return notify_fail("�C�C�n�n�Y���D�G��"+ obj->name()+"�{�b�٨S�M���L�ӡA���٤���T�w�A�����賣�O�ۺ@���C��\n");

	if((string)obj->query("gender") == (string)me->query("gender"))
		return notify_fail("�C�C��D�G���z�I�A�O�P���ʡH�藍�_�A�ѱC�l�B�z���F�o�ơI��\n");

	if(obj == me)
		return notify_fail("�C�C���D�G���A�o���O���ۤv�}�R�ܡH��\n");

	if( !userp(obj) )
		return notify_fail("�C�C���D�G���藍�_�A�A�u��M���a���B�C��\n");

   if(ob->query_temp("marry/money")!=me->name()
   	&&ob->query_temp("marry/money")!=obj->name())   //�u�n�䤤���@�ӤH���L�N��
	{
   	me->set_temp("ask_money",1);
      obj->set_temp("ask_money",1);//������󤣲ťյ��B
   	return notify_fail("�C�C���H�H�a�D�G���B�`�n��@�������ơI�n50 gold�A�������A�ڥi�S�k���A��I\n");
   }

	if((int)me->query("unmarried")>2)
	{
   	me->delete("unmarried");
      me->delete("married");
      me->set("couple/married",2);
      message_vision("�C�C½�F½�ýtï�A��$N���D�G���B�äj�ƫ�\�|�H�A�o���H�H�K�K�H�{�b\n"
      "�A���A�̦Z�@�����|�A�A���B�A�ڳo��N�����A�쵲�B�F�I��\n",me);
   }
	if((int)obj->query("unmarried")>2)
   {
   	obj->delete("unmarried");
      obj->delete("married");
      obj->set("couple/married",2);
      message_vision("�C�C½�F½�ýtï�A��$N���D�G���B�äj�ƫ�\�|�H�A�o���H�H�K�K�H�{�b\n"
      "�A���A�̦Z�@�����|�A�A���B�A�ڳo��N�����A�쵲�B�F�I��\n",obj);
   }
	if(!me->query_temp("marry/answer"))
   {
	   message_vision(HIG"�C�C�u�}�ýtï�A�����o�o�a���D�G�����B�O�@���l���ר��j�ơA�i����\n"
   	"�H�H�K�K�A�_�h�A�o�@�D�N�äF�C�C�ӤH�u��b�ڳo����T�����B����C\n"
	   "���ڬݬݡG"HIC"  "+me->name()+"���L"+(int)me->query("couple/married")+"���B�Q  "+obj->name()+"���L"+(int)obj->query("couple/married")+"���B�Q    "
   	HIG"�n���A\n�̦Z�A�A�̦A�{�u�Ҽ{�@�U�G�O���O�u�ߺ@�N�M��赲�B�H��\n"NOR,me);
   	obj->set_temp("marry/answer",1);
   }
	if( (object)obj->query_temp("pending/marry")!=me )
	{
		if ((string)obj->query("gender") == "�k��")
			message_vision(MAG "\n$N���$n�ݹD�G���A�@�N�����ڶܡH��\n\n"NOR, me,obj);
		else
			message_vision(MAG "\n$N���$n�ݹD�G���A�@�N���ڶܡH��\n\n"NOR, me,obj);

		if( objectp(old_target = me->query_temp("pending/marry")) && old_target != obj )
			tell_object(old_target, YEL + me->name() +
                        "�����F�M�A���B�����Y�C\n" NOR);

		me->set_temp("pending/marry", obj);

		if ((string)obj->query("gender") == "�k��")
			tell_object(obj, MAG "�p�G�A�@�N�����L�A�ЧA�]��" + me->name()
			+ "("+(string)me->query("id") + ")"+ "�U�@�� marry ���O�C\n" NOR);
		else
			tell_object(obj, MAG "�p�G�A�@�N���o�A�ЧA�]��" + me->name() +
			"("+(string)me->query("id") + ")"+ "�U�@�� marry "+(string)me->query("id")+" �����O�C\n" NOR);
      write(MAG"�{�b�A����߱�ۧA���ߤW�H���P�N...\n" NOR);
      return 1;
	}
	message_vision(MAG "\n$N���$n�j�n���D�G�ں@�N�I\n\n"NOR, me,obj);
	message_vision(MAG "�C�C�������D�G�����N�n�A���N�n�A����ڨ�F�䪺�ýt��ӭ�ƫ���a�I��\n"
   	"�����A�C�C�@��@��a���i�F�F�䪺�j��C\n" NOR, obj, me);
	me->delete_temp("ask/marry");
	ob->move("/d/ruzhou/yinyuan-tang");

	me->set_temp("pending/pro",1);
	obj->set_temp("pending/pro",1);

	me->set("couple/couple_name",(string)obj->name());
	me->set("couple/couple_id",obj->query("id"));

	obj->set("couple/couple_name",(string)me->name());
	obj->set("couple/couple_id",me->query("id"));

	if ((string)obj->query("gender") == "�k��")
	{
		me->set("couple/couple_gender", "�d�l");
		obj->set("couple/couple_gender", "�V��");
	}
	else
	{
		obj->set("couple/couple_gender", "�d�l");
		me->set("couple/couple_gender", "�V��");
	}
   call_out("meipo_waiting", 1,ob,me,obj);
 	return 1;

}

int meipo_waiting(object ob,object me,object obj)//�C�C������
{
	if(ob->query_temp("wait_time") == 200 )
	{
		say( "�C�C�ôb�a���D�G���p�ҩd�s����]����H���D�u�O���t�L���H���A�B§�٬O�����}�I\n"
      	"�ѮQ�i�O���ȤF50 gold�F�A������...��\n\n");
		call_out("do_back", 0, ob);
      return 1;
	}
	if( environment(ob)==environment(me)&&environment(ob)==environment(obj) )
   {                                                 //��H���b
      ob->delete_temp("wait_time");
   	call_out("ready_marry", 1,ob,me,obj);
   }
	else
   {
		if( environment(ob)==environment(me)&&environment(ob)!=environment(obj) )
		{
			if( random(10) == 0 )
			say("\n�C�C�ݹD�G��"+me->name()+"�I�A�h�ݰ�"+obj->name()+"��\�٤��L�ӡH���D���@�N�F�H\n");
			ob->add_temp("wait_time",1);               //�䤤�@�Hobj���b
			call_out("meipo_waiting", 1, ob,me,obj);
		}
   	else if( environment(ob)!=environment(me)&&environment(ob)==environment(obj) )
		{                                            //�䤤�@�Hme���b
			if( random(10) == 0 )
			say("\n�C�C�ݹD�G��"+obj->name()+"�I�A�h�ݰ�"+me->name()+"��\�٤��L�ӡH���D���@�N�F�H\n");
			ob->add_temp("wait_time",1);
			call_out("meipo_waiting", 1, ob,me,obj);
		}
		else
      {
	   	ob->add_temp("wait_time",1);
			call_out("meipo_waiting", 1, ob,me,obj);
      }
   }
	return 1;
}

int ready_marry(object ob,object me,object obj)//��ƱB§
{
	object room,npc;

	if(!( room = find_object("/d/ruzhou/yinyuan-tang")) )
	room = load_object("/d/ruzhou/yinyuan-tang");

	message("vision", HIY "\n�C�C���n�s�D�G���֧֧֡A�z�������X�ӤF�A���W���m�߰�I��\n" NOR, room);
	message("vision", HIC"\n�uť��Z�T�_�@�}�}�B�n�A�Q�L�Ӭ�o���m�A�A��A���֨k�֤k�H�H�����a�]�i�ӡA\n"
		"�T�T���aĳ�׵ۡA�S���Y�]�}�F�A�ɤ��ɦa���۬ݤ@��"+me->name()+"�M"+obj->name()+"�C\n\n"NOR, room);
	say("�C�C����s�H���D�G�����n�۫�A�ڭ̳��O�ܦ��g�窺�A�ܧִN�|���m�n���I��\n"
   CYN"�u�����䪺�H�]�Ӷ]�h�A���o���o�F�C\n"NOR);
	call_out("wait_marry", 1, ob,me,obj);
   return 1;
}

int wait_marry(object ob,object me,object obj) //���m�߰�
{
	object room;
	if(!( room = find_object("/d/ruzhou/yinyuan-tang")) )
	room = load_object("/d/ruzhou/yinyuan-tang");
	switch(ob->query_temp("wait_time"))
	{
   	case 0:
    	say(RED"\n�@�Ӥp�a��]�L�ӡA�s�D�G���C�C�A�R���Ȫ��������F�I���C�C���򵹥L�@�ǿ��C\n\n"NOR);
	   ob->set_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
	   break;
      case 1:
     	say(MAG"\n��M�A���䪺�p�h�Q�s�D�G���C�C�A���p�m�K�o�䥿�����H���C�C�@�ݡG���k��A�W�h�I�I��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
      case 2:
     	say(CYN"\n�|�Ӯa����K��a��ۤ@�u�j�c�l�q�Υ~�A���䨫�L�A�C�C�m��D�G���C�ǡB���I�I��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
		case 3:
      say("\n�C�C�@��Ԧ���]�L���@�Ӥp��l�G���ﻫ�Ӫ��߮b�q�F�ܡH�֥h�I��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
      case 4:
     	say(YEL"\n���䪺�H�s�D�G���֮�����ӡA�⭻���I�G�B�I�G�C��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
	   break;
		case 5:
     	say("\n����S�s�_�ӡG���C�C�A���I�����o�e�f�Ӫ��a�I�����ӤF�I���C�C����]�L�h�C\n\n");
      ob->add_temp("wait_time",1);
	 	call_out("wait_marry", 1, ob,me,obj);
      break;
		case 6:
     	say(CYN"\n�C�C�@���p�]�L�ӡA�ݬݷs���s�Q�������A�I�I�Y�^�Y�s�G���֡A���s�H��Ƴ߸ˡC��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
		case 7:
	  	say(WHT"\n�@���H�C��K�}�a��X�F�L�i�j�Ȥl�A�b����W�E�F�@�Ӥj�j��\n"HIR
"			       ��      ��\n"
"			    ����������������\n"
"			    ����������������\n"
"			     ������  ������\n"
"			     ������  ������\n"
"			      ����    ����\n"
"			    ����������������\n"
"			     ������  ������\n"
"			     ������  ������\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
   	case 8:
     	say(YEL"\n�ԧo�֤�}�l�ո��w�֪��֦��A�i�i�X�X���ֻ{�Ѥ��{�Ѫ��H�A�ɯɫ���۶P�G�����߮��ߡI��\n\n"NOR);
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
      break;
		case 9:
  	  	say("\n�L�Ӥp�h�Q���H�H�a�@�����ۮ�ȡA�@�䤬�۫r�ۦզ��A���ɦa�����ݬݷs�H�C\n\n");
      ob->add_temp("wait_time",1);
	  	call_out("wait_marry", 1, ob,me,obj);
		break;
		case 10:
		message("vision", HIY "\n�C�C���n�ݤF�@�n�G������Ʀn�F�ܡH�����H���D�G���n�F�I��\n"
      "�C�C�ߨ����F�n���۹D�G�����Ф�ѥD���B§�K�K�I��\n"
      HIM"�y�ɡA���ֻ���A�@���j�@�A�񭦦�Q�ֹL�ӡA�C��K�}���s���B�s�Q���W�s��A\n"
      "��ֵۦV�j�󤤥����h�C\n"NOR, room);
      call_out("start_marry", 1, ob,me,obj);
      break;
   }
   return 1;
}

int start_marry(object ob,object me,object obj) //�}�l�B§
{
	object moon,room;
   string msg;
	if(!(room = find_object("/d/ruzhou/yinyuan-tang")))
		room = load_object("/d/ruzhou/yinyuan-tang");
	moon=new(__DIR__"yuelao");
   moon->move(room);
	message("vision", "\n�H�ۤ@�}�����j���A�@������ն����Ѫ̡A�֨B��i�󤤡A�b�����֦~�k�k���`���۫��G\n"
   	"�����Ф�ѷݷݡI������\�\��A�������a�ݬ�"+me->name()+"�M"+obj->name()+"�A�I�I�Y�D�G\n"
      "���n�I�n�I���~�k���A�ѧ@���X�I�ѧ@���X�r�I��\n"
   	HIY"\n�C�C�@����A�߼֤S���_�A�uť����Ѱ��n�ť��G���s���K�s�Q�K���K�Ѧa�K�K�I��\n"NOR,room, moon);
   say("�C�C�S�p�n�a���ӷs�H���G�������ǿ�J���� �Ѧa�B�� ����M�� ��誺�W�r���C��\n");
   CHANNEL_D->do_channel(moon, "mudnews",
	   sprintf("���P%s�M%s�ߵ��}�t�A����j§�Y�ɶ}�l�I\n",me->name(),obj->name()));
	me->set_temp("pending/bai",1);
   obj->set_temp("pending/bai",1);
	return 1;
}

int do_back(object ob)//����
{
   ob->delete_temp("wait_time");
   ob->delete_temp("marry/money");
	say("�C�C��F�稭�W�A�S�@��@��a�V���䨫�h�C\n");
   ob->move("/d/ruzhou/hongniang-zhuang");
	return 1;
}

int do_bai(string arg)//����
{
	object me,ob,obj;
	string act;

	me = this_player();
   ob = this_object();
	if (me->is_busy())
		return notify_fail("�C�C���D�G���A�{�b���O�����۶ܡH�����A���I��\n");

	if( me->is_fighting(this_object()) )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me);
		return notify_fail("�C�C���D�G���ѮQ�n�ߵ��A��B�ơA�A���ʪZ�A�e�A�h�������B�a�I��\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("�C�C���D�G�S�ݨ��o�঳�H�o�öܡI\n");

	if( !living(this_object()) )
		return notify_fail("�A�٬O���Q��k��C�C�Ͽ��a�C\n");

	if( me->is_fighting() )
		return notify_fail("�C�C���D�G���K�K�A�A���٬O�Ʋz���A���B�ͦA���a�I��\n");

	if( !environment()||base_name(environment()) != ("/d/ruzhou/yinyuan-tang") )
		return notify_fail("�C�C���D�G���A�o�H�u�O���A����O�n��ýt��~�檺�r�I��\n");

	if( !me->query_temp("pending/bai"))
		return notify_fail("�C�C���D�G�������A�A�Ǥ��\�̧r�I��\n");

	if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
		|| !find_player(me->query("couple/couple_id")) )
	{
   	message_vision("�C�C�ਭ�@�ݡA��Y�a���D�G�����r�I�A���R�H��\��M�]�F�H�B§��\�|��H�j�봲�u�a�C��\n"
      	"�b�@���{���n�A�j�a�ɯ������A�߰�W���F��]�O�@���ӪšC\n",me);
      call_out("do_back",1,ob);
      return 1;
   }

   if(arg==" �Ѧa"||arg==" ����"||arg==" "+(string)me->query("couple/couple_name"))
		return notify_fail("�������P�Z�����������ХΥb���Ů�C\n");

	if(!arg ||(me->query_temp("pending/bai")==1 &&arg!="�Ѧa")
		||(me->query_temp("pending/bai")==2 && arg!="����")
		||(me->query_temp("pending/bai")==3 && arg!=(string)me->query("couple/couple_name")))
		return notify_fail("�C�C���D�G���A�ë����\�r�H�@���Ѧa�I�G������I�T���A���R�H�I�i�O�A���F�I��\n");

	if( (string)obj->query_temp("pending/act")!=arg )
	{
      if((int)me->query_temp("pending/bai")!=3)
      {
			tell_object(obj, MAG"�A����Q�����۩M�A�� " + arg + " �O...\n" NOR);
			write(MAG "�{�b�A�����ݵۧA����Q...\n" NOR);
			me->set_temp("pending/act", arg);
      }
      else
      {
			tell_object(obj, MAG"�A����Q�����۩M�A�����]���L���W�r�^�O...\n" NOR);
			write(MAG "�{�b�A�����ݵۧA����Q...\n" NOR);
			me->set_temp("pending/act", me->name());
      }
		return 1;
	}
	else if((int)me->query_temp("pending/bai")==1)
   {
  		message_vision("���@���K�ѡK�a�K�K��$N�M$n�b�}�}�����n���լի��U......\n",me,obj);
      me->add_temp("pending/bai",1);
      obj->add_temp("pending/bai",1);
      return 1;
   }
	else if((int)me->query_temp("pending/bai")==2)
   {
  		message_vision("���G���K���K��K�K��$N�M$n�b���_�Ӭ۵��@���A�S�w�w���U......\n",me,obj);
      me->add_temp("pending/bai",1);
      obj->add_temp("pending/bai",1);
      return 1;
   }
	else if((int)me->query_temp("pending/bai")==3)
   {
  		message_vision("���ҩd�K��K���K�K��$N�M$n�b�ۤ��`�`���F�@��......\n",me,obj);
		message_vision(HIY "��ѯ������a���D�G���n�A$N�M$n�A�{�b���������ҩd! \n" NOR, obj, me);
		CHANNEL_D->do_channel(this_object(), "chat",
			sprintf( "����%s�M%s�A�@���z�H�ߵ��}�t�C\n        �U��˪B�n�͡A�i��§�즼�{�ﻫ�Ӱѥ[�L�̪��B�b�I\n", me->name(), obj->name()));

		me->add("couple/married", 1);        //���B����
		me->set("couple/have_couple",1);     //�B�_�w�B���A
      me->set_temp("married_party",1);     //���W�O���A�ߨӺ֦ѪO�ݨ�N�|�P�N�}�s�u
      obj->set_temp("married_party",1);    //��H�����A���u���k�ʤ~����
		obj->add("couple/married", 1);       //���B����
		obj->set("couple/have_couple",1);    //�w�B���A

      me->delete_temp("pending/bai");
      obj->delete_temp("pending/bai");
      me->delete_temp("pending/act");
      obj->delete_temp("pending/act");
		me->delete_temp("pending/pro");
		obj->delete_temp("pending/pro");
     	me->delete_temp("ask_money");
   	obj->delete_temp("ask_money");
	   call_out("last_marry",1,ob,me,obj);
		return 1;
   }
}

int last_marry(object ob,object me,object obj)//���󵲧�
{
	object moon,room;
	if(!(room = find_object("/d/ruzhou/yinyuan-tang")))
		room = load_object("/d/ruzhou/yinyuan-tang");
	moon = present("yue lao", room);
	moon->move("/u/llm/workroom");
   ob->delete_temp("wait_time");
   ob->delete_temp("marry/money");
	say("�C�C�۹D�G����ҡI�ֱN�s�H�e��ﻫ���|��B�b�A�کM��ѴN���h�F�A�����I��\n�����@��@��a�V���䨫�h�C\n");
   ob->move("/d/ruzhou/hongniang-zhuang");
	message_vision(HIR"�񭦦�Q�ֵۨ��s�H�A�W�F���f���⳻�j������A�uť��ҭ̤@�n���_��I��\n"
   	"�@��H�j�j�����a�b�V�ﻫ��......\n"NOR,me,obj);
   me->move("/d/ruzhou/jiao1");
   obj->move("/d/ruzhou/jiao2");
   call_out("go_lou",8,ob,me,obj);
	return 1;
}

int go_lou(object ob,object me,object obj)//��s��
{
	object room,npc;
	if(!(room = find_object("/d/ruzhou/xifu-tang")))
		room = load_object("/d/ruzhou/xifu-tang");
	message_vision("\n    �L�F�n���@�|��A�uť��ҭ̤@�n����աI����l��Ө�@�_�A�Q�O����F�a�W�A\n"
   	"$N�M$n�q��l���U�Ӥ@�ݡA��Ӥw�g��F�ﻫ�ӡC��H�S�Q�֧ߵۤ@���W�F�G�Ӻֺ���C\n"
      "�uť��@�}�������n�A�ﻫ�ӦѪO�ߨӺ֯��e�����a��X�ӡG�����ߨ��s�H�I���߮��ߡI\n��",me,obj);
   npc=new(__DIR__"xi-laifu");//�ѪO�X�{
   npc->set("name1",me->name());
   npc->set("name2",obj->name());//����m�W
   npc->move(room);
   me->move(room);
   obj->move(room);
   return 1;
}
