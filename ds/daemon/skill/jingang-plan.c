//����ù�~�}(jingang-plan.c)  -By Tmr- 2002/1/26
// ���ʡB��N�B�j�O�B���

#include <ansi.h>
#define BASIC 4 //�򥻤H��
string type() { return "knowledge"; }


inherit SKILL;
inherit SSERVER;

int do_perform(object *obj,object env);

string *attck_msg = ({
        "$N�@�n���S�A���s�K�x��V$n�I�I\n",
});

string *start_msg = ({
     HIC   "�ư��u�j�O����ù�~�v�ά۪�$N�o�ʧ�աI�I\n" NOR,
     HIC   "�ư��u��N����ù�~�v�ά۪�$N�o�ʧ�աI�I\n" NOR,
     HIC   "�ư��u������ù�~�v�ά۪�$N�o�ʧ�աI�I\n" NOR,
     HIC   "�ư��u���ʪ���ù�~�v�ά۪�$N�o�ʧ�աI�I\n" NOR,
});

void delete_all(object* ct)
{
	int i;
	for(i=0;i<sizeof(ct);i++)
                ct[i]->delete_temp("doing_jingang_plan");
}

int form_array(object me)
{
        int i;
        object *t,ob,env;
        object *ct=({});

	if(!me)
			me=this_player();
      if(!me->is_fighting() ) 
                    return notify_fail("�A�èS���b�԰��A�L�k�ϥγo�Ӱ}�k�C\n");
      

        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S�ŧG�}�C\n");
        t=me->query_team();
        env=environment(me);

        //�qteam ���A��X�i�H�ϥΰ}�k���H��
        //���Y��b���]�n����C
        for (i=0;i<sizeof(t);i++)
        {
			ob=t[i];
			// �H�ư��F
			if( sizeof(ct)==BASIC ) break;
			// �S���o�ӤH
			if( !ob ) continue;
			// ���H���L��
			if( ob->is_busy() ) continue;
			// ���b�P�@�өж�
			if( env != environment(ob) ) continue;
			// �w�g�ǳƵo�ʰ}�k�F
			if( ob->query_temp("doing_jingang_plan") )  continue;

                        if( !ob->is_fighting() ) continue;
                        if( !ob->query_skill("jingang-plan") ) continue;
                if( ob->query("ap") < 300 || ob->query("hp") < 300 ) continue;


			ct += ({ob});
			if(wizardp(me) )
				write( ob->query("name")+"("+ob->query("id")+")\n");
        }
        if(sizeof(ct) < BASIC)
			return notify_fail("�A�S�����������ͯ�ϥγo�Ӱ}�k�C\n");
        else 
		{
	        message_vision(HIG "\n$N������X�F�԰�A���n���S�G�u�G�y����ù�~�}�z�I�I�v\n" NOR,ct[0]);
		    message_vision("$N���|�H�H�Y���ڦX�A�����A�ǳƵo�ʰ}�k�I�I\n",ct[0]);
			for(i=0;i<BASIC;i++)
			{
				ct[i]->start_busy(1);
				ct[i]->set_temp("doing_jingang_plan",1);
			}
			call_out("do_perform",3,ct,env); //�޵o�}�k
		}

        return 1;
}

int do_perform(object *ct,object env)
{
		object *targets,ob;
		object target;
         int i,sk_lv,attack_lv;
		int j;
		
		target = offensive_target(ct[0]);
          if( !target || !arrayp(targets = ct[0]->query_enemy()) )
		{
			message_vision(CYN"�ѩ�S���i�H�������ﹳ�A��Ӱ}�k���F�U�ӡC\n" NOR,ct[0]);
			delete_all(ct);
			return 1;
		}
    
        for (i=0;i<sizeof(ct);i++)
        {
        ob=ct[i];
		sk_lv=ob->query_skill("jingang-plan");
		
		// �M�w����������
		if( sk_lv < 25) attack_lv=0;
		else if( sk_lv < 50) attack_lv=1;
		else if( sk_lv < 75) attack_lv=2;
		else attack_lv=3;
		
		// �üƨM�w����������
		attack_lv=random(attack_lv+1);

        message_vision(start_msg[attack_lv],ob);

	    if(		!ob
                                     )
		{
			message_vision(CYN"$N���Τ@���A��Ӱ}�k���F�U�ӡC\n"NOR,ob);
			delete_all(ct);
			return 1;
        }

		if( env != environment(ob) )
		{
			tell_object(env,CYN +"�ѩ�"+ob->query("name")+"���b�{���A��Ӱ}�k���F�U�ӡC\n" NOR);
			delete_all(ct);
			return 1;
		}

		
		// �U�H����target code....
		switch(attack_lv)
		{
			case 0:	// �j�O����-���[bar
				ob->add_temp("apply/bar",2);
					message_vision(HIB "$N�o�X�u�j�O����q�v�A�������O�q���M�W�j�F�ƭ��I�I\n" NOR,ob);
					ob->attack();
				ob->add_temp("apply/bar",-2);
				break;
			case 1:	// ��N����-attack 3 ��
				// �W�[�R���v
				ob->add_temp("apply/bio",1);
				ob->add_temp("apply/hit",20);
				message_vision(HIR "$N�⵲�u��N����v��L�A�n�ɧ�ռ@�W�I�I\n" NOR,ob);
				ob->attack();
				ob->attack();
				ob->attack();
				ob->add_temp("apply/bio",-1);
				ob->add_temp("apply/hit",-20);
				break;
			case 2:	// ������-�ɦ�
				message_vision(HIG "$N���S�L���A���t�a�H�u��������v���������˸ɦ�C\n" NOR,ob);
				for(j=0;j<sizeof(ct);j++)
				{
					ct[j]->receive_heal("hp",200);
					ct[j]->receive_heal("ap",200);
					tell_object(ct[j],CYN "�]�Aı�o���W���˶ի�_�F���֡^\n" NOR);
				}
				break;
			case 3:	// ���ʪ���- Attack all emeny
				// bonze �޵o�p�Ӳĥ|��
				/*
				if(ob->query("class2")=="�ⶳ�x" && 
					ob->query_skill("buddha-skill") > 90)	{
					message_vision("�p�Ӳĥ|��...",ob);
				}
				else 
				*/
				{
					message_vision(HIW "$N�C�Y���F�ƹM�u���ʪ���G�v�A�n�ɥX�{�@�Y���s�еL�q�ۡI�I\n" NOR,ob);
					message_vision(@LONG
                                    ��  ����                                   
                                   ���i���i�i                                   
                               ���i�i�i�i�i�i                                   
                       ���i�i�i�i�i�i�i�i  ��                                   
                     ���i��[0;1;5;34m�[1;5m�[0m ���i�i�i�i����                                    
              ���i�i�i�i�i�i�i�i�i�i�i�i��   �l                                 
              �i�i�i�i�i�i�i�i�i�i�i�i�i�i��  �l                                
                ��  �� �� �i�i�i�i�i�i��  �w �l                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mh[1;5m�[1;5mg[1;5m�[1;5mf[1;5m�[1;5me[1;5m�[1;5mc[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[0m�i�i�i�i�i�i�� �w �l                                
[0;1;5;31m�[1;5m][1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mg[1;5m�[1;5mf[1;5m�[1;5me[1;5m�[1;5md[1;5m�[1;5mc[1;5m�[1;5mb[1;5m�[1;5mb[1;5m�[1;5mb[0m�i�i���i�i�i�� �w �l                                
[0;1;5;31m [1;5m [1;5m�[1;5m^[1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m�������i�i�i�i�i�� �w �w �l                                 
[0;1;5;31m [1;5m [1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m  �i�i���i  �i �w �w �w �l                                    
[0;1;5;31m�[1;5m][1;5m [1;5m [1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[0m��  �i�i��  �w �w �w �l                                         
[0;1;5;31m [1;5m [1;5m�[1;5m^[1;5m�[1;5m�[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5mi[1;5m�[1;5m�[0m���i�i��   �i�i �w �w �w �l                                       
                           �i�i �w �w �w �l                                     
                           �i�i�w �w �w �w�l                                    
                           �i�i �w �w �w  �m          

LONG
					,ob);
					message_vision(HIW "$N�L�q�ۤ@�i�f�A�Q�X�@�D�������P���T���u���N�V�ĤH�I�I\n" NOR,ob);
                                          for(i=0;i<sizeof(targets);i++)
					{
						if(!ob->can_fight(targets[i]))	//�@�O�_�i���������
							continue;
						if( random(100) > -COMBAT_D->dodge_factor(targets[i],"dodge") ) // �{�פ���
						{
							targets[i]->receive_damage("hp",200);
							targets[i]->start_busy(1);
							message_vision(RED "$N�z���@�n�G�s�A�Q�����]��F�I�I\n" NOR,targets[i]);
						} else {
							message_vision(GRN "$N���I�a�k�F�}�h�I�I\n" NOR,targets[i]);
						}
					}			
				}
	
				break;
			default:
				message_vision(CYN"$N���Τ@���A��Ӱ}�k���F�U�ӡC\n"NOR,ob);
                        delete_all(ct);
				return 1;
		}

        if(!ob->is_fighting(target) )   ob->kill_ob(target);
        if(!target->is_fighting(ob) )	target->kill_ob(ob);
		//����mark
		ob->receive_damage("hp",100);
		ob->receive_damage("mp",100);

		ob->set_temp("doing_jingang_plan",0);
             ob->improve_skill("jingang-plan",random(ob->query_int()));
        }       
                        delete_all(ct);
        return 1;
}


