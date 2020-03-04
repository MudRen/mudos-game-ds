#include <path.h>

inherit ROOM;
//string look_sign(object me);
void greeting(object me);
void create()
{
	set("short", "�ɪů���");
	set("long", @LONG
�o�̬O���]���]�������C�\�h�@�۪��H�^�̳����w�b�o���R��ר��A
�o�̪��F��ܱj�A�ҥH�`�`�l�޳\�h�t����E���b���������窺����C
�o�̦���y�����A���O�O�x�ޥͩR����[Shengsan]�M�x�ަ��`����[Luky]
���J��(statues)�C

                      ��  
                        ��  
                     _�[_.O.           k
                    /\__.\/ ��      O  |
                    \/__\         ()Y==o
                     | :|          /_\ |   
                     | :|          _W_ |   
                   �g�i�i�g      �g�i�i�g
                   �i�i�i�i      �i�i�i�i
 �áááááááááááááááááááááááááááá�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hall",
	]) );
	set("item_desc", ([
		"statues": "  ��y�»ɥ��y���J��(statue of luky)(statue of shengsan), �A��\n"+
		           "�즳�ǥb�z���F�饿��¶�ۨ䤤�@���J������(pray)�ۡC\n\n",
	]) );
	set("hide_item_desc", ([
		"statue of luky": @STATUE_L
  �@�L�Q���Y�ª��J���A�@����ޤ@����١A�N���O�ǻ����D�_���ɪ��]��
  ���λ��C
STATUE_L,
		"statue of shengsan": @STATUE_S
  �A�ܦn�_������o��ӯ����|��b�@�_�A�M�����Y�ª��J����_�ӡA�o�L
�J�����G�O���\�h�A���H�@�ئw���ΪA���Pı�C
STATUE_S,
		"luky": @STATUE_L2
  �@�L�Q���Y�ª��J���A�@����ޤ@����١A�N���O�ǻ����D�_���ɪ��]��
���λ��C
STATUE_L2,
		"shengsan": @STATUE_S2
  �A�ܦn�_������o��ӯ����|��b�@�_�A�M�����Y�ª��J����_�ӡA�o�L
�J�����G�O���\�h�A���H�@�ئw���ΪA���Pı�C
STATUE_S2,
		
	]) );
	set("light",1);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}

void init()
{
 add_action("do_pray","pray");
 if(this_player()->is_ghost()) call_out("greeting",20,this_player());
}

void greeting(object me)
{
        if( !me ) return;
	if(environment(me)==this_object() && me->is_ghost())
		write("�[1m[����] �A�w�g���h�F����A�U pray luky ���O�i�H���A�_���C�[0m\n");
	return;
}

int do_pray(string arg)
{
	object me;
	me=this_player();
 
 if(!arg) return notify_fail("�A�Q����@���J����ë�O?\n");
 if(arg=="luky")
 {
	if(me->is_ghost())
 	{
 	 me->reincarnate();
        me->delete_temp("kill_love");
	 message_vision("�[1m$N�@�۪��V���`������ë�A��M�@�}���~�Ӯg�b$N���W�A$N�_���F�C�[0m\n", me);
	 return 1;
	} else return notify_fail("�A�@�۪����J����ë�Aı�o�߱����R�F�\\�h�C\n");
 }
 
 if(arg=="shengsan")
 {
 	if(me->is_ghost()) return notify_fail("�[1m�ѤW�ǨӦB�N���n��: �[33m�ڥu�����U���ͩR���H�A�A�٬O���L�����A�a�C�[0m\n");
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
 	 me->reincarnate();
	 message_vision("�[1;32m$N�@�۪��V�ͩR������ë�A��M�@�}���~�Ӯg�b$N���W�C�[0m\n", me);
	 tell_object(me,"�A�����骬�p�����^�_�F�C\n");
	 return 1;
	} else return notify_fail("�A�@�۪����J����ë�Aı�o�߱����R�F�\\�h�C\n");
 }
 if(arg=="statues" || arg=="statue") return notify_fail("�A�Q����@���J����ë�O(shengsan),(luky)?\n");
 return 0;
}

int valid_leave(object me, string dir)
{
        if( dir=="down" && me->is_ghost() )
                return notify_fail("�A�٬O����C(pray luky�i�H�_��)\n");
        return ::valid_leave(me, dir);
}
