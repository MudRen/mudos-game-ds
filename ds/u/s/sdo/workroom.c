#include <ansi2.h>
inherit ROOM;

void create()
{
	set("short", HIB"�]���a��"NOR);
	set("long", @LONG
�o�Ӧa��N�O�ǻ����]�����X�S�a�I�C���M���I���¡A���O�o��
�H���@�ثܦw�ߪ��Pı�C�A�o�̥i�H�H�A���������ǧA�Q�����Ʊ��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
  		__DIR__"lion.c" : 1,
	]));
	set("exits", ([ /* sizeof() == 5 */
  		"enter" : __DIR__"workroom1",
  		//"east" : __DIR__"pwest/path1.c",
  		"wizroom" : "/d/wiz/hall1",
  		"south" : __DIR__"workroom2",
  		//"down" : __DIR__"area/h_d.c",
	]));

	setup();
	call_other("/obj/board/sdo_b", "sdo");
}
