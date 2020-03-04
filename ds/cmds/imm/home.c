// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
         string msg;
        if(!arg || arg==me->query("id"))
	{
	  if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
		return notify_fail("�A�S���ۤv���u�@�ǡC\n");
	  if(!me->query_temp("invis"))
	  {
	    if( stringp(msg = me->query("msg_home")) ) message_vision(msg + "\n", me);
		else message_vision("$N�N�N��l, �^��ۤv���u�@�Ƕ}�l�Υ\\�F�C\n", me);
	  }
	  me->move(user_path(geteuid(me)) + "workroom");
	}
	else
	{
	  if( file_size("/u/"+arg[0..0]+"/"+arg + "/workroom.c") <= 0 )
		return notify_fail("�S���o�ӤH���u�@�ǡC\n");
	  if(!me->query_temp("invis"))
	  {
	    if( stringp(msg = me->query("msg_home")) )  message_vision(msg + "\n", me);
		else message_vision("$N�N�N��l, �]��"+arg+"���u�@�ǥh����l�F�C\n", me);
	  }
	  me->move("/u/"+arg[0..0]+"/"+arg + "/workroom");
	}
	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : home �� home <�Ův>

�Q�Φ��@���O�i�����^��ۤv���u�@�ǡC�Ψ��L�Ův���u�@��,�p�G
�A�S���ۤv���u�@��,�Ш�/u/�U���إߦۤv���u�@��
�p�G�A���]�w 'msg_home' property, �h�b�����H���|�ݨ쨺�ӰT��.
HELP
    );
    return 1;
}
