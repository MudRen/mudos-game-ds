// Room: /u/t/tmr/area/inn_2f.c

#include <path.h>
#define FACEOFF_PAST "/open/world1/faceoff/"
inherit ROOM;

void create()
{
	set("short", "�G��");
	set("long", @LONG
�o�N�O�¤ѼӪ��G�ӤF�A���h�ȤH��@�Ӥֱo�h�A�j�h�O�@�ǴI
�a���l�άO�Ʃx�l�̡A�Τ@�ǰ������h�A�ʵ۵���������滷���A�e
�{�@���w�Ԫ���^�A�A�X�ߦn�w�R���H�ζ��C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inn_3f",
  "down" : __DIR__"hotel",
  "west" : __DIR__"fc1",
  "south" : __DIR__"fc2",
  "north" : WD_PAST+"magic-card/room1",
  "east" : __DIR__"big2room",
]));
set("objects",([
	__DIR__"npc/kore.c" : 1,
]) );
	set("light",1);
	set("no_clean_up", 0);

	setup();
	load_object("/obj/board/announce_b"); // alick 2003-03-26
}
/*
int valid_leave(object me, string dir)
{
 if( dir=="east" && me->query("not_newbie") )
  return notify_fail("\n�A�w�g�h�L�F, ����A�h�F�I\n");
 return ::valid_leave(me, dir);
}
*/
