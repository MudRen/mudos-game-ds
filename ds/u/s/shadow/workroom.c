/**
 * Shadow's Workroom [v.1]
 */

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�Q����"NOR);
	set("long",@LONG
�A�Ө�F�@�ӫշt�����j�Ŷ��A�±����H�e�Ů����o�A�X�G�ݤ�
�L��C�A���פ��w�a��¶�@�g�A��M���I�q����ǨӾ_�Ѫ��۱��n��
�A���ر���C�N�b�A�i�W�������ɡA�e�j���x�}�b�A���e���a�����A
�u�ѤU�Ů��j�������Ԯ�^�A�a�g���@��j�˱N�x�C�B����p����
�e�A���j�����ߩܵۺ��ª��Z�ҡA���n�u�u�B�L����A�y�a�}�@�C
���_�M�A�������a�ݵۧA�I��W���F�@�T���p�]couplet�^�A����
�z�S�X�o�઺�D�H�O�֡C
LONG
	);
	set("light",1);
	set("exits",([
		"out": __DIR__"meetroom_east",
	]));

	set("item_desc",([
		"couplet":
		HIG"
		�e      ��   
		��      ��   
		�x      �Q   
		��      ��   
		��      �H   
		�|      ��   
		��      �u"
		NOR"\n",
	]));

	/**
	 * �]�p���~�P�ͪ�
	 */	 
	/*
	set("objects",([
	__DIR__"npc/wuji":1,
	]));
	*/
	set("valid_startroom", 0);
	setup();
 
	/**	 
	 * �I�s�䥦������
	 */
	call_other("/obj/board/shadow_b","???");
	
	
}
