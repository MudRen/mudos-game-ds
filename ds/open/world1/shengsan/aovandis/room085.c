// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�Ův�u�|�۫ݩ�"NOR);
	set("long", @LONG
�A�Ө�Ův�̱`�`�E�|�����ҡA�o�̥��O�Ův�u�|�C�A��ı�쨭�Ǧ�
�ظ޲����]�O�b���Ǿ_���ۡC�b�ж����������Ө�e�۬��R�Ṣ���O�l�A
�ӻO�l���W�����B�_�������]�ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room048",
	    "north": __DIR__"room102",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}