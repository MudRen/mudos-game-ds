// pwd.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
  {
   object ob;
        
	if( !arg ) {
	   me->set("hp",me->query("max_hp") );
	   me->set("mp",me->query("max_mp") );
	   me->set("ap",me->query("max_ap") );
		message_vision(HIY"$N����D: ı���a! �������F.. �N���ª����s, �`����ӫ��d..\n"NOR,me);
	   return 1;    }
	  else {
	    ob = present(arg,environment(me));
	    if (!ob) ob = find_living(arg);
	    if (!ob) return notify_fail("�S���o���a�άO�ͪ��C\n");
	    
	         ob->set("hp",ob->query("max_hp") );
	         ob->set("mp",ob->query("max_mp") );
                 ob->set("ap",ob->query("max_ap") );
 
		message_vision(HIW"$N���P��X�{�F�X��H�Ŧ⪺����, �ͩR��_�F���֡C\n"NOR,ob);
	        return 1;    
	     }     
}

int help(object me)
{
write(@HELP
���O�榡 : full
 �o�i�H���A��_�����mp,ap        �Ϊkfull <��H>
 
HELP
    );
    return 1;
}
