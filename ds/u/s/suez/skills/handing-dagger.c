/*
    �o�ӧޯ઺�S�I�O���ӷU���A�o�X�j�O���������|�U�j�A�p�G����100�[�W���ޯ൥��100
    �h�i�H��75���k�������O�A���O����random���v�T�A�]���i��u��5�Ӥw�C�ۦ��������O
     �[�W�ޯ઺�v�T�A�̦h���W�L10�A��O�Q���S�¤O���ۦ��C�ѩ�O�T���誺���ȡA�ҥH����
     60���e�A�����|���h�j�¤O�A���h20���k�A��60����A�¤O�W�[�����֡C�ڧƱ��O�d���S
     �I�A�p���ӱj�զ��ޯ���Ӫ����n�ʡA�ϧO�H�O�q�y���ˮ`���Z�̩ۦ��A�ϹB��γt�צ���
     �s������P�����P���B�C���ޯ�ڬO�H���u�j�j�Z�v�ӨӡA�b���S�O�P�¡C
 */
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int h = this_player()->query_dex()/5;
int h = h*h*h;
int h = h*7/800;
int h = random(h)+this_player()->query_skill("handing-dagger")/20;//�����O���p�⦡

mapping *action = ({
	([
	"action": "$N��M�N��W��$w����_�ӡA���w�@�n�A�ϥX�u�֦r�Z�v�T�u���L�ƤM�vŧ�V$n",
	"damage":		1+h,
	"dodge" :		40,
	"parry" :		-10,
	"attact_type":  "bar",  
	"damage_type":  "���",
	]),

	([
	"action": "$N��M�V���ƶ}�A���F�@�n�Q�u�e�C�v�]����$N�p�󲾰ʡA�@�D�H���w���W�F$n���V��",
	"damage":		4+h,
	"dodge" :		30,
	"parry" :		-20,
	"attact_type":  "bar",  
	"damage_type":  "�ζ�",
	]),

	([
	"action": "$N�����@�{�A�X$n�⤤�ۦ��N�ɥ��ɤ��ɡA�@���u�}�r�Z�v����$n�ۦ��W���}��",
	"damage":		1+h,
	"dodge" :		20,
	"parry" :		20,
	"attact_type":  "bar",  
	"damage_type":  "���",
	]),

	([
	"action": "$N�N$w�|�P�����A�b�y�e���A�f���ܤF�@�n�u���v�A��ӤH�S�p�q�{�p���@��V$n�ĤF�L��",
	"damage":		5+h,
	"dodge" :		-30,
	"parry" :		-30,
	"attact_type":  "bar",  
	"damage_type":  "����",
	]),

	([
	"action": "�u��$N���@��A�k�@��A�ϥX�u�j�r�Z�v�T����$n�ݲM�䨭���A�@��$w�w�V$n���F�L�h�K",
	"damage":		2+h,
	"dodge" :		30,
	"parry" :		30,
	"attact_type":  "bar",  
	"damage_type":  "�d��",
	]),

	([
	"action": "$N�Y�@�C�A�}�@��A�����p�J$n���h���A�@�ۡu�J�r�Z�v�����ı��d���F�ƩۡK",
	"damage":		3+h,
	"dodge" :		-20,
	"parry" :		40,
	"attact_type":  "bar",  
	"damage_type":  "����",
	]),
});

int exert(object me, object target,string arg)
{
	int damage,d,w;
            
	object weapon;
		
	weapon=me->query_temp("weapon");
	if(!weapon) return notify_fail("�u�J��P�v���F��H�~�ٻݭn�@��P���~��I�i�C\n");
	if( weapon->query("skill_type")!="dagger") return notify_fail("�A�T�w�n���o�F��I�i�u�J��P�v�ܡS\n");

	if( arg=="off" )
	{
		if( me->query_skill_mapped("dagger")!="handing-dagger")
			return notify_fail("��T�S���A�A�{�b���T�S���ϥΡu�J��P�v�C\n");
		me->map_skill("dagger");
		me->reset_action();
		message_vision("$N�N��W���P����F����A�Ȯɤ�����ϥΡu�J��P�v�F�C\n",me);
		return 1;
	}

	if( me->query_skill("dagger")<1 )
		return notify_fail("�A�s�P�����γ����|���K\n");
	if( me->query("ap") < 10 || me->query("mp") < 20 )
		return notify_fail("�A���`�N�O�����A�L�k�o���u�J��P�v���ۦ��C\n");


	// �ĤG�� exert
	if(me->query_skill_mapped("dagger")=="handing-dagger")
	{
                       if( !target ) target = offensive_target(me);
                         if(!target)   
			return notify_fail("�A�J�Ӫ��ˬd�F��W���P���A���ʬ��ʤ�áA��T�{�b�ϥΡu�J��P�v����S���D�T\n");	       
		if( me->query_skill("handing-dagger") < 70 )
			return notify_fail("�A�{�b�Q�ϥΡu�g�r�Z�v�ܡS�ӦM�I�F�T�A�ڥ��٤����ۦ��A�L�k�N���̳s�e�_�ӡC\n");
		if( me->query("ap")<50 )
			return notify_fail("�A�ܷQ�ϥX�u�g�r�Z�v�A���O���l�N�O��ť�ܡC\n");
		if( me->query("mp") <150 )
			return notify_fail("�A���`�N�O���������A�L�k�ϥΡu�g�r�Z�v�K\n");
                          if(!me->can_fight(target))
                                       return me->can_fight(target);
		me->start_busy(1);
		me->receive_damage("mp",70);//�]���|�����ˮ`�A���Ӹ��j

             d=target->query_dex();
	damage = (random(me->query_skill("handing-dagger"))+me->query_dex() *4/3);//��ª��¤O�p��
            damage=damage-random(d);

	message_vision(HIR"$N�V��@��A��W���P�������@���A�u�֯e�}���j�J�v���Z�X�@���u�g�Z�v�b�@�L�e������\�p\�U��M�o�X�T\n"NOR,me);
	if( target->query_skill("dodge") > random(me->query_dex()*5) )//�W�[�ݩʹ�R���v���v�T�A�å[�j�R���v
	{
		message_vision(HIW"$P�V����@���A�׶}�F�o�ƨg�������C\n"NOR,target);
                        me->start_busy(2);
		return 1;
	}
           
	target->receive_damage("hp",damage, me );
                       w=damage*2/d;
                      if (target->query("wound/foot")>25) w=0;//����ˮ`��
	target->receive_wound("foot",w);  //�����ˮ`�A�ǥѶˮ`���L�������W�[�ڤ�R���v
             /*switch(random(4)) {
		case 0: target->receive_wound("hand",(random(damage/d)));break;
		case 1: target->receive_wound("head",(random(damage/d)));break;
		case 2: target->receive_wound("body",(random(damage/d))); break;
		case 3: target->receive_wound("foot",(random(damage/d)));break;
		}        //�H���������P����ˮ`
            */
	message_vision(HIR"$P���A���H�ۤP������ե|���ӥX�T���b�a�W�yø�X�@����d���T\n",target);
	target->start_busy(1);
	me->start_busy(2);//�קK���a�s�o�A���a�Ȱ����^�X�j���H
	me->improve_skill("handing-dagger",1+random(me->query_int()/3+me->query_dex()/4));
	me->improve_skill("dagger",1+random(me->query_int()/3+me->query_dex()/4));

		return 1;

	}
	
	me->map_skill("dagger", "handing-dagger");
	me->reset_action();
	message_vision("\n"HIG"$N�N�⤤��"+weapon->query("name")+HIG"�Ϥⴤ��A�s�u����B�b�é�S�A���O�u�J��P�v���_�⦡�T\n"NOR,me);
	me->receive_damage("mp",20);
	me->start_busy(1);
	me->skill_active( "handing-dagger",(: call_other, __FILE__, "delay", me ,4 :), 1);
	return 1;
}

void delay(object me,int cost)
{
	object weapon,target;

	if(!me) return;
	weapon=me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type")!= "dagger" )
	{
		me->map_skill("dagger");
		me->reset_action();
		return;
	}
	
	if(me->query_skill_mapped("dagger")!="handing-dagger")  return;
	
	if(me->query("ap")<10)
	{
		me->map_skill("dagger");
		me->reset_action();
		tell_object(me,"\n�A�����ॢ�F�`�N�O�A�L�k�A�~��ϥΡu�J��P�v�F�C\n");
		return ;
	}
	me->receive_damage("ap", cost);
	me->receive_damage("mp", cost-2);
	me->skill_active("handing-dagger",(: call_other, __FILE__, "delay", me ,cost:), 4);
	return;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        int a;
        a=(ob->query_dex())*2/3;
	if(a>70) a=70;
	if(ob->query("adv_class")==2) return 100;
        else if(ob->query("adv_class")==1) return a;
}
/*
     �P���D��Ԥ���....�J��P��N�P���äJ�⤤........
     �ۦ��S�֤S��....�۩۷m��.....�p�G���O�������֤��H....
     �h�b�L�k���....�ۦ��@���C�Z
     �� �e �} �� �j �J �g
     �ֳZ���p�d��@�X
     �e�Z���p�{�q����
     �}�Z��ĩۤ��ߥH�}��
     ���Z�ˤv���w�M�H����
     �j�Z�H�Ĭ����I�j��....�e�ᥪ�k��������...
     �J�Z�J�Ĥo������......�ı��d�娾���Ө�...
     �g�Z�@�L���k.....�P���Y�����L.....
     �����Ѧ�ӱq��h....�D�ĦX�e���Z���j���ӥͤ�����......
*/