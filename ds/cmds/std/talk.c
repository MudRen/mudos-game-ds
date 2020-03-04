// talk.c ���F�����ȧ��ܤƥH��NPC��Ͱ�, �[�F���@���O.
// 
//  �H�U��NPC�s�W���, ������talk �i�H����Ҧ��ʧ@.
//
// ��1. talk_action [�^���ʧ@]
//
//     �YNPC���[�J���禡, �h talk �ɷ|NPC���榹�禡���ʧ@.
//     return 1 �h���|�X�{ talk_reply�T��, �Y��return 0; �h���槹action��|�I�sreply
// 
// �d��:(/u/l/luky/npc/passenger.c)
//
// int talk_action(object me)	
// {
// command("smile "+me->query("id") );
// return 1;
// }
//
// ��2.talk_reply [�^���T��]
// 
//      �YNPC���]�w���r��( set("talk_reply",<�T��>); ) �h�btalk�ɷ|���X��<�T��>�r��.
//	�r�ꤤ�i�H��$N(NPC�W��) $n(���a�W��) �����N��;
//      �Y�S���], �h�|�HNPC���A�׳]�w�ӨM�w�|���T��, �Y�A�׬�"killer"�h�|�}�l����.
//
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int flag=0;
          string dest, attitude, words,*keyword;
	object ob;
	mapping keywords;
	mixed reply,output;
	
	if( ! arg )
		return notify_fail("�A�ۨ��ۻy�F�@�|��ı�o�ܵL��C\n");
	if( sscanf(arg, "with %s about %s",dest,words) != 2 )
	{
	 	if(sscanf(arg, "with %s",dest) != 1)
		return notify_fail("���O�榡�Rtalk with <�Y�H>\n");
	}
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("�o�̨S�� " + dest + "�C\n");
	if( !living(ob) )
		return notify_fail("�o�Ӫ��󤣯��͡C\n");
	if( ob == me )
		return notify_fail("�A�ۨ��ۻy�F�@�|��ı�o�ܵL��C\n");
	if( userp(ob) )
	{
	  if(words) 
	  {
	   message_vision(YEL"$N�V$n��: "+words+"\n"NOR,me,ob);
	  }
	  else
	  {
	   tell_object(ob,me->query("name")+"���G���Ʊ��n�M�A�Q�סC\n");
	   write("�A�V"+ob->query("name")+"���X��Ѫ���ĳ�C\n");
	  }
	  return 1;
	}
	else
	{
	 if(keywords=ob->query("inquiry"))
	 {
	 	flag=1;
	 	keyword=keys(keywords);
	 }
	 if(!userp(me) && words)
	 message_vision("$N�V$n��: "+words+"\n",me,ob);
	 else
	 message_vision(YEL"$N��$n��: �A�n.. ������a��ڥi�H�ĳҪ���?\n"NOR,me,ob);
	 
	 if(ob->talk_action(me)) return 1;
	 reply=ob->query("talk_reply");
	 if(functionp(reply)){
	 	output=evaluate(reply);
	 	if(stringp(output))
	 	{
	 		message_vision(HIY"$N��$n��: "HIG+output+"\n"NOR,ob,me);
	 		return 1;
	 	}
	 }
	 else if(stringp(reply))
	 {
	  message_vision(HIY"$N��$n��: "HIG+reply+"\n"NOR,ob,me);
	  return 1;
	 }
	 else
	 { 
	  if(flag)
	  {
		words=HIY+"$N��: "+HIG+"�p�G�Q��ť����y"+implode(keyword, "�B")+"�z�����D�A�i�H��(ask)�ڡC\n"+NOR;
		message_vision(words,ob,me);
		return 1;
	  }
	  if( ob->query("race")=="�H��" || ob->query("race")=="human" )
	  {
	  	attitude = ob->query("attitude");
	  	switch(attitude)
	  	{
	  	 case "friendly" :
	  	 		message_vision(YEL"$N���ۻ�: �A�ӫȮ�F, �ثe�@�����ܶ��Q���γ·бz�F�C\n"NOR,ob);
	  	 		break;
	  	 case "peaceful" :
	  	 		message_vision(YEL"$N�N�۲������ۻ�: �U�z����, �Z�Ƴ��ٺⶶ�Q�C\n"NOR,ob);
	  	 		break;
	  	 case "heroism"	 :
	  	 		message_vision(HIW"$N�N�N����: �ڪ��Ʊ��ڦۤv�|�ѨM, ���һդU�O�ߡC\n"NOR,ob);
	  	 		break;
	  	 case "aggressive" :
	  	 		message_vision(HIM"$N�N��@�n: �K..�A���ѨM�A�ۤv���x���a�C\n"NOR,ob);
	  	 		if(random(6) > 3) ob->kill_ob(me);
	  	 		break;
	  	 case "killer" :
			 	message_vision(HIC"$N�j��: �A�]�Ӥ����D�Ѱ��a�p�F!! �A�Ѥl���Ƥ��ΧA��!!!!\n"NOR,ob);
				ob->kill_ob(me);
				break;
		 default :
		 		message_vision(YEL"$N��: ��..�٦n��!! �ڷQ�����٦���L�H��ڧ�ݭn�A�����U�a�C\n"NOR,ob);
				break;
	        }
		return 1;
	  }
	  else
	  {
	   message_vision("$N�@�y��M.. ���Gť����$n�����ܡC\n",ob,me);
	   return 1;
	  }
	 } 
	}
	return 0;
}

int help(object me)
{
	write(@Help
���O�榡�Rtalk with <�Y�H>

  �M�Y��H�����q, �q�`��A�o�{�Y�ӤH���G���x����, �i�H�Φ����O�o�����D
  ���Ҧb, �H�K�ѨM���D(����)�C���ɹ��]�i��|���X���A�X�G�N�ƪ������C

Help
	);
	return 1;
}
