// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Z�}��������"NOR);
	set("long", @LONG
�o�̬O���Z�}�������ߦa�a�A�A�ݨ�|�P����W���O������J���Ҩ�
���A���Ӫ��۬W�N�b�s�����|�P�z�ߵۡA�C�@�ӥ۬W�N���p�q�F�Ѩ��˪�
���j�A�o���G�H�x�۬Y�ت��N�q�C�A�b�o�̷Pı�쫰�������j�Χ��R....
�q�o���_�������h�i�H�ݨ���ѽ��ת����j�ؿv���A�F���U���������F
�谼���A�������n���Y�i��F�o�������������F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room010",
	    "west" : __DIR__"room017",
	    "south": __DIR__"room002",
	    "north": __DIR__"room042",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}