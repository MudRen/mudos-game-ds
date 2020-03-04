// �������ɤ��N -Luky-
// 

#define WALLNAME "��������"

#include <ansi.h>
#include <obj.h>
inherit SKILL;

int cast(object me, object target,string dir)
{
	if( !target ) return notify_fail("�A�������w�@�Ӥ�V�~��I�i�����ɳN�C\n");

	if( !target->is_room())
		return notify_fail("���k�N�u��Ω�ж��C\n");
	if( living (target) )
     		return notify_fail("���k�N����Ω�ͪ��W�I\n");
	if( environment(me)->query("no_magic") )
     		return notify_fail("�o�Ӧa�褣�i�H�I�k�I\n");
	if( environment(me)->query_temp("wall/"+dir))
		return notify_fail("�o�Ӥ�V�w�g�����ɤF�I\n");
	if((int)me->query("mp") < 40 )
		return notify_fail("�A���k�O�����T\n");

	 if( me->is_busy() )
	    return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
	    
	me->add("mp", -40);
	me->start_busy(2);
	message_vision("\n[1;35m$N���|����... �}�l�I�i�������N...[0m\n\n",me);
	call_out("do_wall",2,me,target,dir);
	return 1;
}

int do_wall(object me, object target,string dir)
{
  object env,wall1,wall2;
  string msg,other_dir,*exit,*dirs,file;
  mapping exits;
  int i;
  
  if(!me) return 0;
  if(!env = environment(me) ) return 1;
  if( env->query("no_magic") )
  {
     	tell_object(me,"�o�Ӧa�褣�i�H�I�k�I\n");
     	return 1;
  }
  if( env->query_temp("wall/"+dir))
  {
	tell_object(me,"�o�Ӥ�V�w�g�����ɤF�I\n");
	message_vision("$N���������ɳN�I�i�ŧi���ѡC\n",me);
	return 1;
  }
	if( random(me->query_int()+20) > me->query_int() )
	{
		message_vision("$N���������ɳN�I�i���ѤF�C\n",me);
		return 1;
	}
	
	env->set_temp("wall/"+dir,WALLNAME);
	tell_room(env,"��M���@�}�j��, �A�ݨ줭�D�����ʦ�F"+to_chinese(dir)+"���X�f�I\n");
	wall1 = new(WALL_LIGHT);
	wall1->move(env);
	wall1->set("dir",dir);
	call_out("break_wall",me->query_skill("lightwall",1)+me->query_int()*2,wall1);
	exits = target->query("exits");
	if(mapp(exits))
	{
	 file = base_name(env);
	 dirs = keys(exits);
	 exit = values(exits);
	 for(i=0;i<sizeof(exit);i++)
	 {
	  if(exit[i]==file)
	  {
	   target->set_temp("wall/"+dirs[i],WALLNAME);
	   tell_room(target,"��M���@�}�j��, �A�ݨ줭�D�����ʦ�F"+to_chinese(dirs[i])+"���X�f�I\n");
	   wall2 = new(WALL_LIGHT);
	   wall2->move(target);
	   wall2->set("dir",dirs[i]);
	   call_out("break_wall",me->query_skill("lightwall",1)+me->query_int()*2,wall2);
	  }
	 }
	}
	me->improve_skill("lightwall",1+random(me->query_int()/6));
	return 1;
}

int break_wall(object wall)
{
	if(environment(wall))
	{
	 tell_room(environment(wall),"�������ɶ}�l�ܱo�z���ӳv�������F�I\n");
	 environment(wall)->delete_temp("wall/"+wall->query("dir"));
	 destruct(wall);
	}
	return 1;
}