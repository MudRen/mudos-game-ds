// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ԥh�V�m��"NOR);
	set("long", @LONG
�^�i�����Z�}���Ԥh���b�o�̻E���V�m�A�L�̬O���Z�}���̫i������
�h�A�Y�檺�V�m�ϥL�̦������Z�}���̱j�����@�s�i�̡C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room098",
	    "south": __DIR__"room019",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}