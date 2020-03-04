// kill.c

#include <ansi.h>
#define PK_AREA "/open/world1/alickyuen/match/area"

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
          int i,num=0;
	object obj,owner,*inv;
          string callname,fuzzyname,*items,tar;
	if( !arg )
		return notify_fail("�A�Q���֡S\n");

	if(!objectp(obj = present(arg, environment(me)))) {
		inv=all_inventory(environment(me));
		i=sizeof(inv);
		if(sscanf(arg,"%s %d",tar,num)==2) {
			arg=tar;
		}
		while(i--) {
                        // �缾�a���ϥ� auto id complete 
                        if( userp(inv[i]) ) continue;

			items=inv[i]->parse_command_id_list();
			if(fuzzyname=COMMAND_D->auto_string_complete(arg,items, 2)) {
				if(!num)
				{
					write("[" + arg + " => " + fuzzyname + "]\n");
					obj = present(fuzzyname, environment(me));
				}
				else
				{
					write("[" + arg + " " + num + " => " + fuzzyname + " "+num+"]\n");
					obj = present(sprintf("%s %d",fuzzyname,num), environment(me));
				}
				break;
			}
		}
		if(!obj) return notify_fail("�o�̨S���o�ӤH�C\n");
	}

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�ݲM���@�I�M���ä��O�ͪ��C\n");
	if( strsrch(file_name(environment(me)), PK_AREA) == -1 )
	{
	if(userp(me) && me->query("level")<3)
	{
		if(me->query("level") < obj->query("level")-10)
			return notify_fail("�зR���ͩR�C\n");
	}

 	if(!me->can_fight(obj))
		return me->can_fight(obj);

	if(!userp(me) && (owner=me->query("creater")) && userp(obj) )
	{
		if(userp(owner))
		{
 		 if(!owner->can_fight(obj))
 		 tell_object(owner,"�A���i�H�������H!!\n");
		 return owner->can_fight(obj);
		}
	}

	if(userp(me) && userp(obj))
        {
	        if(me->is_fighting(obj)) return notify_fail("�[�o�C\n");
           if(obj->query_temp("invader") && !obj->query_temp("killer") )
              shout("\n"HIR+me->query("name")+HIR"("+me->query("id")+")�ܹD: "
                        +HIR+obj->query("name")+HIR"("+obj->query("id")+")�A�~�M���ʤ�ʸ}, �u�O�ӷ��Y�W�ʤg!!!\n"NOR);
           else if(obj->query_temp("killer"))
              shout("\n"HIR+me->query("name")+HIR"("+me->query("id")+")�|�D: "
                        +HIR+obj->query("name")+HIR"("+obj->query("id")+")�A�o�i�c�����H�ǥh���a!!!\n"NOR);
           else
	           shout("\n"HIR+obj->query("name")+HIR"("+obj->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!! "
	                     +me->query("name")+HIR"("+me->query("id")+")�Q�ѱ���!! \n"NOR);

 	       me->set_leader(0); //�Ѱ�follow
 	       obj->set_leader(0); //�Ѱ�follow
		obj->set_temp("no_follow",1);//�H�W�T��add by luky
	}
	}
	callname = RANK_D->query_rude(obj);

	message_vision("\n$N���$n�ܹD�R�u"
		+ callname + "�T���餣�O�A���N�O�ڬ��T�v\n\n", me, obj);

	me->kill_ob(obj);
	obj->kill_ob(me);

	return 1;
}
int help(object me)
{
  write(@HELP
���O�榡 : kill <�H��>

�o�ӫ��O���A�D�ʶ}�l�����@�ӤH���M�åB�|�ձ������Mkill �M fight �̤j��
���P�b������N�|�u�M��j�a�����M�]�N�O���M�|�u�����ˡC�ѩ� kill �u�ݳ��
���@�[���@�N�i�H���ߡM�]���A�����H�ϥ� kill ���O���|�}�l�԰��M�q�`�p�G
���O NPC ���ܡM�L�̤]�|�P�˹�A�ϥ� kill�C

���H��A�ϥ� kill ���O�ɷ|�X�{���⪺�r��ĵ�i�A�M���@�Ӫ��a�Ө��M�p�G
�A�S����@�W�ĤH�ϥιL kill ���O�M�N���|�N���u�����˩α���( �ϥΪk�N��
�~)�C

��L�������O: fight

���� fight �� kill ���Ϥ��Ь� 'help combat'.
HELP
    );
    return 1;
}
 
