// updated 26/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CChurch�ISecret"NOR);
	set("long", "�i�ӳo�̫�A�A�Pı��o�˲��`���t�C�A���TŸ�ݤF�_�ӡC�P���P�ɡA
�A�|�B�ݬݫ�o�{�F�n�����@�ǥi�Ȫ��F�西�ݵۧA�L�L�L\n");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"church2.c",

]));
set("light",1);

	set("objects", ([ /* sizeof() == 1 */
 // __DIR__"npc/lu.c" : 1,
]));
	setup();
	replace_program(ROOM);
}
/*--���j�ɥN���ͪ��a�����b��
�����઺�ݵۧA--�ݨӤ������e�A�O�L�k���w�a���X�h�F�C�t�Q��k�a�T�i���٦���k���}��
*/