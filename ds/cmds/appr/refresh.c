// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
  {
   object ob;
        
	if( !arg ) {
	   me->delete("wound");
		message_vision(HIY"$N����D: �줧���F��! �ڥH�d�@�����W�l��A.. �Ϊڭ������S, ����j�a���B..\n"NOR
		+"$N���W���ˤf�����_��F..\n",me);
	   return 1;    }
	  else {
	    ob = present(arg,environment(me));
	    if (!ob) ob = find_living(arg);
	    if (!ob) return notify_fail("�S���o���a�άO�ͪ��C\n");
	    else ob->delete("wound");
 		message_vision(HIW"$N���P��X�{�F�X�D�H��⪺����, ���W���ˤf����¡�X�F�C\n"NOR,ob);
	        return 1;    
	     }     
}

int help(object me)
{
write(@HELP
���O�榡 : refresh
 �o�i�H���A���ˤf�_��.    �Ϊkrefresh <��H>
 
HELP
    );
    return 1;
}
