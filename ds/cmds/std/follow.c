// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string arg1, who;
	if(!me) return 0;
	if( !arg ) return notify_fail("�Х� help follow �d�\\���O�Ϊk�C\n");
	if(sscanf(arg,"%s %s", arg1, who)==2)
	{
	 if(arg1!="stop") return notify_fail("�Х� help follow �d�\\���O�Ϊk�C\n");
	 if( !objectp(ob = present(who, environment(me))) )
		return notify_fail("�o�̨S�� " + who + "�C\n");
	 if(me != ob->query_leader()) return notify_fail(who + "�{�b�èS�����H�A��?\n");
	 ob->set_leader(0);
	 write("�A�M�w���A��"+ who +"���H�A�F�C\n");
	 tell_object(ob,me->query("name")+"�M�w���A���A��ۥL��ʤF�C\n");
	 return 1;
	}

	if( arg=="none")
		if( me->query_leader() ) {
			me->set_leader(0);
			write("Ok.\n");
			return 1;
		} else {
			write("�A�{�b�èS�����H����H�C\n");
			return 1;
		}
        if( arg=="no" || arg=="NO" || arg =="No")
        {
         if(me->query_temp("no_follow")) 
          return notify_fail("�A�w�g�O[�ڵ�]���H���A�F�C\n");
          me->set_temp("no_follow",1);
          write("�A�]�w��[�ڵ�]���H���A�C\n");
          return 1;
        }
        
        if( arg=="yes" || arg=="YES" || arg=="Yes")
        {
         if(!me->query_temp("no_follow"))	
         return notify_fail("�A�w�g�O[����]���H���A�F�C\n");
         me->delete_temp("no_follow");
         write("�A�]�w��[����]���H���A�C\n");
         return 1;
	}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("�o�̨S�� " + arg + "�C\n");

	if( !ob->is_character() )
		return notify_fail("����S���H...." + ob->name() + "�C\n");

	if( userp(me) && ob->query_temp("no_follow") )  // add by Luky.
		return notify_fail(ob->query("name")+"�ڵ��M�A�@�_��ʡC\n");

	if( ob==me )
		return notify_fail("���H�ۤv�S\n");

	me->set_leader(ob);
	message_vision("$N�}�l����$n�C\n", me, ob);

	return 1;
}

int help (object me)
{
        write(@HELP
���O�榡 : follow [<�ͪ�>|none|no|yes]
 
�o�ӫ��O���A����H�Y�H�Υͪ��C
�p�G��J follow none		�h������H�C
�p�G��J follow no		�h�]�w�ڵ��Q���H�C
�p�G��J follow yes  		�h�]�w���\�Q���H�C
�p�G��J follow stop <id>	�N���H�̥϶}�C
HELP
);
        return 1;
}
