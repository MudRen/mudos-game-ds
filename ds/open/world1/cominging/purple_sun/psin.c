#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�s�Ǵ˪L");
	set("long", @LONG
�o�̬O�@�y���Ǫ��˪L�A�b�˪L�ҳ�¶���a�O�ǻ����e���������a
�A�b���񦳵۳\�h�a�椧�ͪ��A�]���@�Ǧb�A��������¶�ۡA�˪L����
���G�L�z�A�դѶ����p�ɴX�G�ݭn�Ψ����ӷӫG�樫�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"psin2.c",
  "east" : COMINGING_PAST + "area/river7.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
