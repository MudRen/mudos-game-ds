/**
 * Shadow's area [��o���� - a4]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�˫�"NOR);
	set("long",@LONG
���e�O�@�l�}�ª��˫ΡA�b���檺������o��~���Y�D�A���ή�
�Ү�ت��@�����o�����L�H�~���a�F�ήǦ��@�j��A�X���p��A
�i���`�`�A���W�٦��B���@�y�A�J�Ӥ@�@�������@�H�v��ߨ�W�C
LONG
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"west": __DIR__"a3",
		"east": __DIR__"a6",
		"enter": __DIR__"a5",
	]));

	setup();
}
