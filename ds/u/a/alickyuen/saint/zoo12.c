// Room: /u/a/alickyuen/area/zoo12.c
//update by alickyuen 9/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CSecret�ICyberZoo"NOR);
	set("long", @LONG
�n���e���~���X�F�o�ӯ��O�g�c�A�A�t�ΤF�@�f��A�`�⨫�o�X�ӤF
�C�A�{���B�b���O�襤�A�|�B�ݬݫ�A�A�o�{�n�䦳�@�ǷL�z�����C�ݨ�
�O�X�f�A�I�I�B��a�T
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo13",
  "out" : __DIR__"zoo11",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
