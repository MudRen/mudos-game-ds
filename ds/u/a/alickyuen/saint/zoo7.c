//updated by alickyuen130/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
�o�̬O�@���ө����J�f�A���P�ɤ]�O�����]���J�f�C�p�G�A�Q�R�F��
���ܴN�i��ө��A�A�]�i�H��W�h�������]�ݬݡCť���o�����]��������
���ܦh�A�ӨC�ѳ��n���|��������t���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"zoo9",
  "east" : __DIR__"zoo3",
  "enter" : __DIR__"zoo8",
]));
set("objects", ([
__DIR__"npc/zooer.c" :1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
