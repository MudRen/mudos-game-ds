/**
 * Shadow's area [��o���� - a3]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�Ŧa"NOR);
	set("long",@LONG
��L�F�@�j���o�H���~���A���e���O�@�j�����Ŧa�C�C�j���E
�����B�D�̵}�i���A�@��²�檺�����u��o���m�b�a�W�A���Ǫ��j��
�U��i�ݥX���H�b�����s�@�֪�����A�������s�~�P�n�n�ױת����
���H�i�H�Q����~���x�������A�����o�|�P���I�R�o���A�ϩ��m���b
�ū������A���A���T�ߥͯǴe�۳o��s���o�ͤF����ơC
LONG
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"east": __DIR__"a4",
		"north": __DIR__"a7",
		"leave": __DIR__"a2",
	]));

	setup();
}
