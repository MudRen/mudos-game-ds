/**
 * Shadow's area [�򩳥@�� - �L�y - a3]
 */
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"�L�y"NOR);
	set("long",@LONG
�o�઺����X��ݽ��A�}�U��۪��O�n�������d�g�C�n��P����
������C���ର�`�Ŧ�A�Q�����`�N�|�ؼW�A�U�U���i�_�I�C���̪�
������¶�b�A���䥴��A�@�I�]���ȧA����ӡA�Ѻ񪺴���ˬM�X�|
�P���s�����q�A���A���ѱo�g�Ĥj�۵M�����I
LONG
	);
	set("light", 0);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits",([
		"east" : __DIR__"a4",
		"south" : __DIR__"a1",
	]));

	setup();
	replace_program(ROOM);
}

