// This is a room made by roommaker.
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�DSOFT�I�a�U�@��"NOR);
	set("long", "�o�̬O�s�����a�U�@�ӡA�o�̤�A���Q�����j�o�h�F�A�b�A����Ǧ�
�@�j�Ƥ@�j�ƪ��ж��A�p�G�A�n��i�h�N���ӭn�I�ڤF�C�A���۬ݵۡA��
�S���o�{����S�O���F��C\n");
set("exits",([ 
"up":__DIR__"inn",
"east":__DIR__"inn5",
]));
set("objects", ([
__DIR__"npc/keeper" : 1,
]));
set("no_fight",1);
set("light",1);
	setup();
}
