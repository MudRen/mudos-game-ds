// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
ť���l���q�s�n�A�A�w�g���D�o�̬O��m��l���a��C�b�e�̥s��
�P�ɡA���Ǥp�B�ͫܿ��Ħa��ۨe�̥s�A���]���@�Ǥp�B�ͦ]���`�ȦӤj
���_�ӡC���F�n�K�i�^��ʪ��骺�D���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"zoo4",
"north" : __DIR__"zoo19",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
