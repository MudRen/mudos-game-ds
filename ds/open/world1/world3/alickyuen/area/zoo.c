// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
�o�̥��O�ʪ��骺�X�J�f�A��A�Q���J������J�f���۫ݳB���ɭԡA
�A�~�ݨ�b���䦳�@�ӧi�ܵP(sign)�A�W�����M�g�ۤ@�ǥO�A�N�Q���쪺
�F��K�K
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zoo2",
  "west" : __DIR__"zoo3",
  "out" : __DIR__"enter2",
]));
set("objects",([
__DIR__"obj/sign":1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
