#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�g���p��"NOR);
	set("long", @LONG

�o�̬O�@���p�p���p�١A��M�`���p�٤��P���O�A�o�Ӥp���ٷ|��
�\�h���a�U�ǨӦs��F��A�j���O�򭷤������a�A�o���p�٬O�e������
���|�j�٤��@�A�Τ��ШF�G���F�C�Ӧa��A���G�|�P�@����������A
�O�A�ݤ��M�A�]�N���ۡC

LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry41.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

void init()
{
	call_out("delay",2,this_player());
}

void delay(object me)
{
	if( environment(me)!=this_object())return;
	else {
		write(HIY"�a�U�x�ëǦ��G�����n�T�C\n"NOR);
		return;
	}
}