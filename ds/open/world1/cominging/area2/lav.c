#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�T�Z");
	set("long", @LONG
�o�̬O�u�ö�Ǫ��p�T�Z�A�b�o�̩_��L��A���O���@����U�~�A
�b�A�����䦳�Ǥ��֯ȡA�i�H���U�A�u����v�A�Q��U���N�O�@������
�D�D�A�N���T�O�H���ǷQ�æR�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"tower.c",
]));
	set("item_desc",([
  "���֯�" : "�M�����H�W�� 1 ���M�Ϊ��ȡA�����W���٦��ǩ@�ئ⤣������C\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

void init()
{
	tell_object(this_object(),"��M�@�}�_'��'�L�񪺮���ĤJ�A���󤤡A�y�ɾ�ӤH���G�N�n�����Pı�C\n");
}