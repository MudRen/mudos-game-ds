#include <ansi.h>
//updated 28/12
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�IPath"NOR);
	set("long", @LONG
�o�̬O�@�����x����D�A�|�P���H�����o�������q�A�ݨӳo�̹��ӥ�
���C�b�o�̩��_�i�쥻�����F���`���A���A����ť�쨺�䦳�ܦh�H�b�j�s
�j�W�A���G�O�b���@�F�A�L�h�i�঳�M�I...���n�i�H�^��A��Ӫ������ߡC
LONG
);
 set("exits",([ 
"north":__DIR__"rd1.c",
"south":__DIR__"dst10.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	setup();
	replace_program(ROOM);
}
