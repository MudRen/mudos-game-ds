// Room: /u/a/alickyuen/area/rd2.c

inherit ROOM;

void create()
{
	set("short", "ST�CRoad�IPath");
	set("long", @LONG
�Ө�o���e�諸�D���A�o�{�A��ݨ쪺���@�������b�o�ءA��Ӧ���
�K�OSAINT����|�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//  "northeast" : __DIR__"rd3", �i���q��future���D��
 "west" : __DIR__"dr1",
  "south" : __DIR__"rd1",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
