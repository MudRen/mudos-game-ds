/**
 * Shadow's area [��o���� - a5]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�˫Τ���"NOR);
	set("long",@LONG
�˫Ϊ������u���@��²�檺�\�]�A�@�i�����ֲ֪��G��A��i��
�_�Ӥ��ư�T���˴ȡA�A�n�_�a���U�|�g�A���M�o�{�ɩ��U���@�Ӭ�
��j���c�l�A���O���G�w�g�W�F��A���Y�W�������ûk�����z�S�X�o
�_�c�w���۷�[�����~�N�I
LONG
	);
	
	set("light",0);
	set("exits",([
		"out": __DIR__"a4",
	]));
	
	/* �]�m�@���_�c */	
	set("objects", ([
		__DIR__"item/box": 1,
	]));
        

	setup();
}

