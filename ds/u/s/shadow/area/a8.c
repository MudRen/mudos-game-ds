/**
 * Shadow's area [��o���� - �P�j�T�a - a7]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�P�j�T�a"NOR);
	set("long",@LONG
�Τ��a��²��o�۷������b�A���W���@���p�o�O�H�Τ@���w
�g½�}���T�r�g�A�@�i��ɤ�²�檺�p��A�Ϋ��٦����s�m�������s
���n���C
LONG
	);
	set("light", 0);
	set("exits",([
		"south": __DIR__"a7",
	]));

	set("objects",([
	__DIR__"npc/zhou":1,
	]));

	setup();
	
}
