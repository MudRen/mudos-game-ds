#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
string *dodge_msg = ({
 "$n�@�ۡu�j�v�۶��v�b$N�����L�Ӫ��b���A�H�����e�v���Z���{�L�I�I\n",
 "$n�k�}�����}�@�֡A�@�ۡu�v�S�L�Ρv��Ө��黴�������F�b�o�A��$N���������šC\n",
 "$n����$N����ե��k�j�ۡA�e���Ʋ��A���O�@�ۡu�v\�H\��\��\�v�I�I\n",
 "$n�k��@�̡A����@�\�A�X$N�y�����ߡA�@�ۡu��v�L��\�v��\��\�������$N�I��C\n",
 "$n�}�@��A���@�Y�A�u�]�L�üv�v�Ͼ�ӤH�������p�J$N��ժ��������C\n",
});
int exert(object me, object target, string arg)
{
	
	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="shadow_step")
			return notify_fail("�ޡI�A�ΰg�k�F�ڡI�A�ڥ��S�b�μv�èB�ڡI\n");
		me->map_skill("dodge");
		me->reset_action();
                       if(me ->query_temp("skill/shadow_step")>0)
                        {
                             me->set_temp("invis",0);
                             me->delete_temp("skill/shadow_step");
                         }
		message_vision("\n"HIC"$N�C�����ءA�w�w�R�ǡA�}�B�C�C�񻴡A���k�@��A����F�u�v�èB�v\�C\n"NOR,me);
		return 1;
	}
            if(arg=="hint off")
             {                         
                           if(!me ->query_temp("skill/shadow_step")>0)  return notify_fail("��T�\��POSE�T���j�a�ݬݧA�èS�����_�ӳ�T\n");
                        
                             me->set_temp("invis",0);
                             me->delete_temp("skill/shadow_step");
                             message_vision(HIB"\n$N��M�q�·t�������w�w���X�C\n"NOR,me);

                             return 1;
                  }
            if(arg=="hint" )
           {
                if((me->query_skill("shadow_step")+me->query_skill("dodge"))<77) //dodge���]�i�H�ϥγo��
                   return notify_fail("�V�O�A�V�O�A�A�V�O�T���[���N�ӧA�@�w�i�H�ϥΡu���ܵ�v�v�T\n");
                if(me->query_temp("skill/shadow_step")>0) 
                   return notify_fail("�۫H�ۤv�a�T�A���T�w�g�æn�F�T\n");
                if( me->query_skill_mapped("dodge")!="shadow_step")
                    return notify_fail("�A���Ρu�v�èB�v���ϥΡu���ܵ�v�v�ڡS\n");
                  if( me->is_fighting() ) 
	 {
	                if(!target) target = offensive_target(me);
                              if(!target) return 0;
                         if(me->query_skill("shadow_step")<71) return notify_fail("�A�٨S����i�H�b�԰����ϥΡu���ܵ�v�v���a�B�C\n");
                        message_vision(CYN"\n$N��M�@�Y���A�Ϥ@�ۡu���ܵ�v�v�T������񪺶¼v�����T\n"NOR,me);
		        me->receive_damage("ap",7+random(3));  //�ΤF�o�۷|�l ap �M mp
                                   me->receive_damage("mp",50+random(3)); 
                                me->remove_all_killer();
                                target->remove_all_killer(); 
                          me->set_temp("invis",random(2)+1);
                          me->set_temp("skill/shadow_step",1);
                       return 1;
	 }
                else
                        {
                         message_vision(CYN"\n$N�ϥX�v�èB���u���ܵ�v�v�A������ӤH�N�o�ˮ��������F�C\n"NOR,me);
                          me->receive_damage("mp",7+random(3));
                          me->set_temp("invis",random(1)+1);
                          me->set_temp("skill/shadow_step",1);
                        	return 1;
                        }
           }
	if(me->query_skill("dodge")<5) return notify_fail("��I���O�n�˧A���ߡA���O�A��Dodge��b������I\n");
	if(me->query_skill_mapped("dodge")=="shadow_step")
		return notify_fail("���n��i�A���P�C�ݲM���A�A�w�g�b�Ρu�v�èB�v�F��I\n");
	if(me->query("ap")<5 || me->query("hp")<10) return notify_fail("�A�ְաI��}��ť�ϳ�A�w�g�Ϥ��X�u�v�èB�v�����֤F�C\n");
        if(!me->skill_active( "shadow_steps",(: call_other, __FILE__, "delay", me ,3:), 3))
                return notify_fail("�O��O��A���t�h���F�ڡI\n");
	me->map_skill("dodge","shadow_step");
	me->reset_action();
	message_vision(HIC"$N�@��@��ϥX�F�u�v�èB�v�A��Ө����ܱo�Ʋ����w�C\n"NOR,me);
	me->receive_damage("ap", 3);
	me->receive_damage("mp", 3);
	me->start_busy(1);
	return 1;
}

void delay(object me,int cost)
{
        int a;
        a=me->query_skill("shadow_step");
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="shadow_step")
	{
	 return;
	}
	if(me->query("ap")<10)
	{
	 	me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIB"$N�}�B�@���A�����@�^�A�Τ��X�u�v�èB�v�F�K�K\n"NOR,me);
		tell_object(me,"�A�٦���O���ܡA�i�H�}�l�Ҽ{��i�C\n");
		return;
	}
      if ( me->is_fighting() ) me->receive_damage("ap",7); 
        me->skill_active( "shadow_step",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
        if(ob->query("adv_class")==1) return 70; 
        else return 97;                         
}
/*
      �v�èB�A�O���s�ħڤ����L���ܤƪ����k�A�g�Ѥ@�Ǥp�ʧ@�z�Z�������������Y�ӶX��
       �s�y�{�ת����|�C��ۦ��h�b�X�G�N�ơA���h�h�i�A�����h�k�A�ݨӦ��G�O�ۤv���ĩ�
       �ĥh�A��h�O�ĩۤ��إ���ĩۤ����A�G�H�i���h�C�h�b�]���i�ϼĤH�X�G�N�ƪ��ĪG
       �C�ǲ߼v�èB���H�A�Ʀܥi�H�N�o�����s�L���ܤƪ��S�I�B�Φb���è������W�Ať���m
       ��Y�ص{�ת��H�Ʀܥi�H�b�԰����v�æۤv�������H�����԰��C
*/