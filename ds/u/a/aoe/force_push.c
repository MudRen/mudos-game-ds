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