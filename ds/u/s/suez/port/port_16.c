#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short","�ĤG�X�Y");
	set("long",@LONG
�o�̬O�ĤG�X�Y�����ݡA�q�`���|������H�ӡC�H�e���M�O�S�����
�D�A���O�H���ĺ��Ĵ����o�i�A�X�J���H�]�U�ӷU�����A���@�ǯ��椣�}
���H�N�E���b���A�����ĺ��Ĵ����Ǹo���ͦa�C���L�W���@�ǲ�a�����F
���ǤH�ѬO�}�a�L�̪��f���A�ФF�X�W�_�I�̨ӡu�M���v�@�U�C�ثe�o��
�u�ѤU���ê�����Ӥw�C
LONG 
);
	set("exits",([
	    "east":__DIR__"port_17",
		]));

	set("world","world1");
	set("outdoor","land");
	set("chance",37);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"npc/hoodlum",
	}) );
	setup();
}