//updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�INorth"NOR);
	set("long", "�Ө�o�̡A�A�P��Q�����R�A�t�A�P��D�`�κZ�C�b�o�̪����ߡA�A
�ݨ�@�ӧi�ܪO�A�W���g�ۡm���_���q�F���j�ӡn�C�n���K�O�����ߡC\n");
 set("exits",([ 
"north":__DIR__"dst8.c",
"south":__DIR__"dmid.c",
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
