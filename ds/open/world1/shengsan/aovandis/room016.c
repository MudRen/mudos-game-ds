// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�F������"NOR);
	set("long", @LONG
�o�̬O���Z�}�����F�������A�¾몺�����`�`�b�o�̶i�i�X�X�A�n��
�֡A�]�n�۵M�C�o�����M�O�����A������׫o�]�����L�������Ӫ���
��A�Ʀܦ��L���ӵL���ΡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room015",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/gateguard" : 2,
	]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}