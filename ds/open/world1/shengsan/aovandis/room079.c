// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ȫ�"NOR);
	set("long", @LONG
�A�b�@���Ȫ��̡A�o�O�������A�ȳ̦n�B�]�Ƴ̧������Ȫ��A�X�~��
�檺�H�@�w���|��J�b�o�̸ɥR�@��Ү��Ӫ���O�C�d�O�p�j�ˤ������e
���A�|�Pı�컫�ܦp�k���Pı�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room068",
	    "up"   : __DIR__"room104",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}