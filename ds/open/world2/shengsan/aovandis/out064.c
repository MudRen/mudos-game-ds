// ���Z�}������
// LV 1~50
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "��D����a");
	set("long", @LONG
�o�������O�͡A�èS��������}�o�A�A�����䦳�@�j���Z������
�L�C�ݰ_�Ӧ��G�O�ӫܭ�l���˪L�A��W�i�J�i��|���I�M�I�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "east" : LUKY_NOW"area_1/room11",
	    "west" : __DIR__"out063",
            ]));

	set("outdoors","land");	// ����
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}