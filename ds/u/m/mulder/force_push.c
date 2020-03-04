// force_push.c
// mulder �ڥu���A�g�Q�����̳Q����O��ж����{��...
// �ѤU�������A���Ӧۤv�g�o....�٦�...�Q�����̯ण��쨺���ж�
// �]�n�A�ۤv�⥦����...�N���l...
//					Shengsan@DS
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
	mapping exit=([ ]);
	string to_dir,to_dir_name,*dir,*dir_name;
	int i;
	object env;

	if(!me) me=this_player();

	env = environment(me);

	if(env->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");

	if ( !target ) target = offensive_target(me);
	if ( !target )	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	exit = env->query("exits");
	dir_name = keys(exit);
	dir = values(exit);

// debug ��....
//	for(i=0;i<sizeof(dir);i++)
//	{
//		write(i+" :"+dir[i]+"\n");
//	}
	i = random(sizeof(dir));
	to_dir = dir[i];
	to_dir_name = dir_name[i];
	target->move(to_dir);
	write( target->query("name")+"�Q���W���O���� "+to_dir_name+" �F\n");

	return 1;
}
if(me->query_spell("force_push",1) < 90)
{
damege
};
else
move

{
 int inn,sk,cost,mk;
 
 if(!me) me=this_player();
 inn=me->query_int();
 mk=me->query_spell("force_push");
 sk=mk/10+1;
 cost=(mk/3)+10;
 
 if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");
 
 if ( !target ) target = offensive_target(me);
 if ( !target )	return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

	//�ˬd�O�_�i�H����
 if(!me->can_fight(target))
		return me->can_fight(target);

 if( (int)me->query("mp") <  cost )
	    return notify_fail("�A���k�O�����C\n");
	    
 message_vision(HIG"\n$N�����@�{�A��V$n\n"NOR,me);
 me->start_busy(2); //�I�k�ʧ@�ɶ�
 me->receive_damage("mp",cost);	//�I�k��MP
 me->set_temp("power_cast",2+mk/20);
 call_out("delay",3,target,me,mk);
 return 1;
}

int delay(object target,object me,int mk)
{
	
 int inn,sk,damage;
							
 if(!me) return 0;					
 if(!target) return notify_fail("�ؼЮ����F�C\n");	
 if( environment(me) != environment(target) )		
	  return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
 if(!me->query_temp("power_cast") || me->query_temp("power_cast") < 1) 
 {
  message_vision(HIW"$N"HIW"�]������ж˦ӶäF���, �L�k���Q�I�iForce Push�C\n"NOR,me);
  return 1;
 }
 me->delete_temp("power_cast");
 sk=mk/20+random(mk/20)+1;
 inn=me->query_int();
 
 message_vision(HIG"\n$N�A�ӥX�����A���V$n�I�I\n\n"NOR,me,target);

    damage= inn +random(mk+inn);
    damage = damage- target->query_sheild()/2 -random(target->query_sheild());
    if(damage<1) damage=random(inn/2);

 if(damage > 0)
 {
    // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
    if( inn + random(mk*2 + inn*2)  > random(-COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int()))
    {
	// �W�[�����ˮ`���v�T
	damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
       target->receive_damage("hp", damage, me ); 
       message_vision(HIC"  �u��$N�{�פ���$n�������A$N�V�᪽���áu�ڡv���@�n�j�s�I"NOR,target);
       if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	tell_object(me,HIY"("+damage+")"NOR);
       if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
	tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
       message_vision("\n",target);
       if(wizardp(me) && me->query("env/debug")) tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
       COMBAT_D->report_status(target);		//���target���A
       target->start_busy(1);
    }
    else
	{
       		message_vision(GRN"  �u��$N�Q���T�V�a�{�׶}$n�������C\n"NOR,target);
	}
 } else message_vision(GRN"�u��$N���{�k�סuForce Push�v����աA���O�]���F�C\n"NOR,target);


 if( random(40+inn) > 20 )
 {
         me->improve_spell("god-fire",inn/2+random(inn)+1);
 }
 if(!target->is_fighting(me)) target->kill_ob(me);
 if(!me->is_fighting(target)) me->kill_ob(target);
 return 1;
}

