#include <ansi2.h>
inherit ROOM;
inherit F_SAVE;

string str;
int roll1,roll2,comp1,comp2;
mapping game_record;

string query_save_file() 
{
        return DATA_DIR+"game/sdo_snowman";
}
void create()
{
	set("short", "���s�W");
	set("long", @LONG
�o�̬O�@�y���s�W�����x�A�|�P�կ���@���A�R���ۥV�Ѫ���
�^�C�A�ݤF�ݥ|�P�A�����֪��C�Ȧb�ﳷ�H�B�����M�A��������֥G
�C�o�̦��@���a�Q�D�����F�_�ӡA�ݨӴN�O���ɪ��a�I�F�C
LONG
	);
	set("exits", ([
		"south" : __DIR__"chris2",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);
	set("outdoors", "land");

	setup();
}
void init()
{
	::init();
	add_action("do_build","build");
}
int do_build(string str)
{
	object me,room;
	me=this_player();
	room=find_object(__DIR__"obj/record_board.c");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("�A�{�b�٦b���C\n");
	if (!str) return notify_fail("�A�Q������F��H\n");
	if (str=="body" && me->query_temp("sdogame/build")=="body") return notify_fail("�A�{�b�w�g�O�b������F�I\n");
	if (str=="head" && me->query_temp("sdogame/build")=="head") return notify_fail("�A�{�b�w�g�O�b���Y���F�I\n");
	if (str == "body" || str == "head")
	{
		add_action("do_roll","roll");
		add_action("do_compress","compress");
	}
	if (str=="body")
	{
		tell_object(me,"�A����}�l�ʤⰵ���H������F�I\n");
		me->set_temp("sdogame/build",str);
	}
	if (str=="head")
	{
		tell_object(me,"�A����}�l�ʤⰵ���H���Y���F�I\n");
		me->set_temp("sdogame/build",str);
	}
	if (str=="snowman")
	{	
		me->start_busy(6);
		
		roll1=me->query_temp("sdogame/roll1");
		roll2=me->query_temp("sdogame/roll2");
		comp1=me->query_temp("sdogame/comp1");
		comp2=me->query_temp("sdogame/comp2");
		
		if (roll1<=0 || roll2<=0 || comp1<=0 || comp2<=0) return notify_fail("�A�Q�n�s�@��������H�ڡH\n");
		
		tell_object(me,HIW"�A��F���W�����A�p���l�l���⳷�y�������Y��b���y����������W�C\n"NOR);
		
		if ((roll1+comp1) < (roll2+comp2)) 
		{
			tell_object(me,HIW"�y�ԡI�z���@�n�A���y�������Y���F�U�ӡA���F�@�a�I\n"NOR);
			return 1;
		}
		if ( comp1 < (comp2 *4/5))
		{
			tell_object(me,HIW"���H���Y�n���ӭ��F�A�⨭������F^^;...\n"NOR);
			return 1;
		}
		else
		{
			message_vision(
			HIW"$N�⳷�y�������Yíí����b����W�A�ߤF�Ⱖ��K���b���骺���䳣�����u�C\n"NOR
			HIW"���۾ߤF�T�ӥ��Y�A��@���H�������M��l�A�@��$N�S�s�����H�X�{�F�I\n"NOR,me);
                        room->measure(me);
			return 1;
		}
		return 1;
	}
	return 1;
}
int do_roll(string str1)
{
	object me=this_player();
	string str;
	str=me->query_temp("sdogame/build");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("�A�{�b�٦b���C\n");
	if (!str1 || str1 != "snowball") return notify_fail("�A�Q�u����H\n");
	me->start_busy(1);
	if (str == "body")
	{
		roll1=me->query_temp("sdogame/roll1");
		comp1=me->query_temp("sdogame/comp1");
		if ( (roll1-1) > (comp1 * 3/2) || random(15)==0 )
		{
			tell_object(me,"�A�@�Ӥ��p�ߡA�⥿�b�u�����y�˴��F�C\n");
			me->delete_temp("sdogame/roll1");
			me->delete_temp("sdogame/comp1");
		}
		else
		{
			tell_object(me,"�A�����y���G�ܤj�F�ǡC\n");
			me->set_temp("sdogame/roll1",roll1+1);
		}
	}
	else if (str == "head")
	{
		roll2=me->query_temp("sdogame/roll2");
		comp2=me->query_temp("sdogame/comp2");
		if ( (roll1-1) > (comp1 * 3/2) || random(15)==0 )
		{
			tell_object(me,"�A�@�Ӥ��p�ߡA�⥿�b�u�����y�˴��F�C\n");
			me->delete_temp("sdogame/roll2");
			me->delete_temp("sdogame/comp2");
		}
		else
		{
			tell_object(me,"�A�����y���G�ܤj�F�ǡC\n");
			me->set_temp("sdogame/roll2",roll2+1);
		}
	}
	else
	{
		tell_object(me,"�A�Q������F��H\n");
	}
	return 1;
}
int do_compress(string str2)
{
	object me=this_player();
	string str;
	str=me->query_temp("sdogame/build");
	
	if (!me) return 0;
	if( me->is_busy() ) return notify_fail("�A�{�b�٦b���C\n");
	if (!str2 || str2 != "snowball") return notify_fail("�A�Q���ꤰ��F��H\n");
	me->start_busy(1);
	if (str == "body")
	{
		if ( random(10) == 0 )
		{
			tell_object(me,"�A�@���p�ߡA�⳷�y���a�F�C\n");
			me->delete_temp("sdogame/roll1");
			me->delete_temp("sdogame/comp1");
		}
		else
		{
			tell_object(me,"�A�⳷�y��������F�ǡC\n");
			me->set_temp("sdogame/comp1",comp1+1);
		}
	}
	else if (str == "head")
	{
		if ( random(10) == 0 )
		{
			tell_object(me,"�A�@���p�ߡA�⳷�y���a�F�C\n");
			me->delete_temp("sdogame/roll2");
			me->delete_temp("sdogame/comp2");
		}
		else
		{
			tell_object(me,"�A�⳷�y��������F�ǡC\n");
			me->set_temp("sdogame/comp2",comp2+1);
		}
	}
	else
	{
		tell_object(me,"�A�Q������F��H\n");
	}
	return 1;
}
