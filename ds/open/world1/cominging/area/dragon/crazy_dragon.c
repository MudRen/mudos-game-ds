#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�g�s��"HIM"��"HIY"�g�s��"NOR);
	set("long", @LONG
    �o�جO�g�s�|�󪺭��� �Сi�g�s��j
���M�g�s���b���򦳫ܤj���W��A���禳���֤H�x���D�Ԩg�s���A
�ҥH����N�O�t�d�g�s���|�P���w���C�S�]�`���U���U��������
�ӬD�ԡA�ҥH�����O�|���ءA�̦h���⪺�a��C
�A�ݨ�|�P��W�����F�U���L���A�٦����Ʊi�۴ȡC
�������~�A�S����S�O���B�C
LONG
	);
	set("exits",([
  "southwest" : __DIR__"dragon.c",
	"down" : __DIR__"bank",
]));
	set("item_desc",([
  "�۴�" : "�Υ��J�����@�i�Ȥl�A�A�ݨ���䪺�s���d�ܸU�ơA���J�誺�v�ťi�u�O�F�`�r�I\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	setup();
}
