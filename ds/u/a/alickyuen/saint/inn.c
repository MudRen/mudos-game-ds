// This is a room made by roommaker.
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�DSOFT"NOR);
	set("long", "�o�OSaint���ߤ@�@���j�s���A�]���`���ܦh�H�b�y�s�A�b�����[
�O�H�ӤH���C�o�̬ݰ_�Ӧn���ܻ��ت��ˤl�A�b�o�j�󦳤@�Ӧ۰ʰ���
�A�A���ݭn���ܥi�h�ݬݡC�b�j��U�����ӬO�ж��������a��C\n");
set("valid_startroom", 1);
set("exits",([ 
"south":__DIR__"dst11",
"down":__DIR__"inn2",
]));
set("objects",([ 
__DIR__"obj/seller1" : 1,
]));
set("no_fight", 1); 
set("light",1);
	setup();
	replace_program(ROOM);
}
