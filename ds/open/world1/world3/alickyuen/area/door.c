// update 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�IEast"NOR);
	set("long", @LONG
�Ө�o�̡A�A�w�g�ݨ�@�Ӥj�j���P�l�g�ۡy�ʪ���z�T�Ӧr�A�P��
�|�B�񺡤F���C���⪺�p�O�w�C�b���W�]�Q�����R�A�b�ߤW��O�t�H�ؤ�
�v���C���F�K�i�H��F�ʪ��骺�J�f�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dst13.c",
  "east" : __DIR__"enter",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
