#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"�g�s��"HIM"��"HIC"�|ĳ��"NOR);
	set("long", @LONG
    �o�جO���D�̮i�}�|ĳ���|ĳ�ǡA�A�ݨ��ǳ��O��s����ȡC
�ӥ�������i�Ӯv�ȡA�A�߷Q�A�o���ӬO���D�M�����D������F�C 
LONG
	);
	set("exits",([
  "south" : __DIR__"dragon.c",
]));
	set("item_desc",([
  "�Ӯv��" : "�@�i�Τ��Y�Ұ������@�i�Ȥl�A�W���Q�ۤ@�i�����O����~�֡C\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	setup();
}
