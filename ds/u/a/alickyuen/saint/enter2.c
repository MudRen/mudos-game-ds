//updated
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CDoor�ICyberZoo"NOR);
		set("long", @LONG
�q�L�o�ӤJ�f�A�N�i�H�J�h�ʪ���F�C���J�h���e�A��M�N�O�n�R��
�աC�ѩ�o�̤~�O���}��A�ҥH�{�b�����|�K�y�@�I�A�i�H���O�J�h��
���n�ɾ��ڡI
LONG
	);
 set("exits",([ 
"in":__DIR__"zoo.c",
"out":__DIR__"enter.c"
]));
set("objects",([
__DIR__"npc/zoosr":1,
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
