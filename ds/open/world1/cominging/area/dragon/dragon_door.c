#include <ansi.h>
#include <path.h>
inherit ROOM;

int dragon(object me);

void create()
{
	set("short", HIC"�g�s����"NOR);
	set("long",@LONG
�A����o�̡A�ݨ�@�����ذ����j���A���W������s�Χ��A��
�⪺�W���U�g�ۨg�s�C��A�ݨ��o��Ӧr�ɡA���Y�@�_�A��ӳo�̴N
�O����W�����j�W���g�s���C�ǻ��g�s����L�M�q�A�n�������A�Ҧ�
�Z�L���H���Q�J�������C���L�`�n�J�g�s���A�o�������@�s�ꪺ����
�~�i�J���A�A�J�ӦҼ{�L��A�M�w�i�h�ոաC�b���Ǧ��X�L�۷�A��
���J����ӵL��A�ݮݦp�͡C�g�s�����~��ѳ���ҳ��A�åB�ɱ`
���g�s������u�õۡC
LONG
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
  "enter" : __DIR__"dragon_garth.c",
  "west" : TMR_PAST+"area/street5.c",
]));
	set("item_desc",([
  "�s�Χ��": "��Ӫ��@�ӧ��A�W����ۨg�s��r�A���G�����H��W�h�C\n",
  "�۷�": "�@�L�ѦW�v�зV�שҨ覨���@�L�۷�A�J���p�u���@��A�i�H�ר����ΡC\n",
  "����": "�b���Ǫ�����A����W���\\�h��ø�e�A���G�b�������ҡC\n",
]));
set("no_goto",1);
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	setup();
}

void init()
{
	::init();
        dragon(this_player());
}

int dragon(object me)
{
   object ob;
	if(!me) return 1; if(wizardp(me) ) return 1; // �n�P�_ me �O�_�s�b�~��A��wizardp/userp -alick
   if(!userp(me)) // for mob. �קK�O�����۳�ͪ��i�J.
   {
   	if(ob=me->query("creater"))
   	{
   		if( !objectp(present("dragon plate",ob)) )
		{
			message_vision("�g�s�����u�äj��: �Q�V���N��? ���A���j�Y�ڧa, $N�C\n"NOR,ob);
			me->move(TMR_PAST+"area/street5.c");
	        	tell_room(environment(me),me->name()+"�Q�g�s�u�û��F�X�ӡC\n",({ me }));
			return 1;
		}
	}
   }
    else
   {
	if( !objectp(present("dragon necklace",me)) && me->query("club/name")!="�g�s��" )
	{
        message_vision(HIW"�g�s�����u�è�$N���O�g�s�����S�̡A�ߧY�N$N�e�ܵ�W�C\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
	        tell_room(environment(me),me->name()+"�Q�g�s�u�õ���F�X�ӡC\n",({ me }));
		return 1;
	}
	
	if( me->query_temp("killer") )
	{
		message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�����F�H�ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
	        tell_room(environment(me),me->name()+"�Q�k�J���|�i�O�Q���F�X�ӡC\n",({ me }));
		return 1;
	}
	
	if( me->query_temp("invader") )
	{
		message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�������L�d���a, �ҥH�Ȯɤ���i�J���|�C\n"NOR,me);
		me->move(TMR_PAST+"area/street5.c");
		tell_room(environment(me),me->name()+"�Q�k�J���|�i�O�Q���F�X�ӡC\n",({ me }));
		return 1;
	}
	call_out("meeting",2,me);
	return 1;
   }   
}

void meeting(object me)
{
if(!me) return;
	switch( me->query("club/level") )
	{
		case 0:
		case 1:
			message_vision(HIY"�g�s�u�ù�$N���R"+"�S�̽жi�I�жi�I\n"NOR,me);
		break;

		case 2:
			message_vision(HIY"�g�s�u�ù�$N���R"+"�o���D�S�̽жi�I�жi�I\n"NOR,me);
		break;

		case 3:
			message_vision(HIY"�g�s�u�ù�$N���R"+"�@�k�жi�I�жi�I\n"NOR,me);
		break;

		case 4:
			message_vision(HIY"�g�s�u�ëܦ�§������$N���R"+"�o��g�s���ѽжi�I�жi�I\n"NOR,me);
		break;

		case 5:
			message_vision(HIY"�g�s�u�ù�$N���`�q§���R"+"�����D�j�H�z�n�r�I\n"NOR,me);
		break;

		case 6:
			message_vision(HIY"�g�s�u�ù�$N���`�q§���R"+"���D�j�H�z�n�r�I\n"NOR,me);
		break;
	}
	return;
}
