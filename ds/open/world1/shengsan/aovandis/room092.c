// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Ю{§��"NOR);
	set("long", @LONG
���f�z�g�i�L�z�����u�Ӯg�b�A���P��A��Ǫ����ध�W�\��ۧA��
���������~�A�ܩ_�S�A�]�ܲӿ��C�n�䪺���٦��@�y�p���������A����
�W���Ӥ�������������ѤW�ӤU���ӲӤ��y�o�ަ���ʡC
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room088",
	    "west" : __DIR__"room099",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}