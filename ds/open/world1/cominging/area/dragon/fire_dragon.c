#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�g�s��"HIM"��"HIY"���s��"NOR);
	set("long", @LONG
    �o�جO�g�s�|�󤧤@ �Сi���s��j
���ҿסu��j���\�K �v�A�����礣�ҥ~�C
�����������F�@�v�p�Q�A�����������˳�(EQ)�h�R�A�ӥ��󪺳d���C
�N�O�n�N�ǳW�������[�H�D�@�A�H�O�������n�A�C
�A�ݨ�󤤩񦳳\�h�D��A�ݱo�A�򰩮��M�C
����W���۳\�h�@�l..�A�߸̷Q....���D...�o�O.........    
LONG
	);
	set("exits",([
  "northwest" : __DIR__"dragon.c",
]));
	set("item_desc",([
  "�@�l" : "�@�Ǳa����⪺�@�l, �Q�O���L���֤H���I\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	setup();
     call_other("/obj/board/dragon_quest_b.c", "???");
}
