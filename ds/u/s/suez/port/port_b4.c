#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�a�U���D");
	set("long",@LONG
�X�������Q���@�ӴN�԰հ԰ժ����F�_�ӡA�I�R��Ӫ��]�p���o���t
���a���W�K�F�ǳ\�޲�����^�A�@�}�H�������q��B�j�ӡA��W�J�誺�_
���ϧΧ����H�򰩮��M�A�o�̦��G�M�a�U���D����L�a�褣�Ӥ@��....
LONG 
);	
	set("light",0);
	set("exits",([
	    "south":__DIR__"port_b5",
	    "west":__DIR__"port_b2"
		]));
	set("world","world1");
	set("objects",([
	    __DIR__"npc/bat":5,
		]));

	setup();
}
void init()
{
        add_action("do_search", "search");
}
void do_search(object me,string arg)
{
	switch(arg){
	 case "here":tell_object(me, "�A�o�{�o�̦� ��,�ϧ�.\n" );break;
	 case "��":tell_object(me, "�A�o�{�����M�O�q������j�X�Ӫ�!\n" );break;
	 case "�ϧ�":tell_object(me, "��L���ϧγ��O�H���J��A���o�Ӧ��G�O���]�k�}...�H\n" );break;
	 case "���":tell_object(me, "�N�o������O��ߪ��Pı�ڡI�����򭷷|.....�H\n" );break;
	 case "�]�k�}":
		tell_object(me, "�A�J���ˬd�o���]�k�}....\n" );
		me->start_busy(3);
		tell_object(me, "�A���e�������M�����F�I�A�@�Ӥ�í�^��t�@���h�I\n" );
		me->move(__DIR__"port_b6");
		break;
	 default:tell_object(me, "�o�̪�"+arg+"���G�S����S�O���C\n" );break;
	}
}