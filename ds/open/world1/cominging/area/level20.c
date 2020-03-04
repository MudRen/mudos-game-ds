#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short", "�v�ޤ��Ű�");
	set("long", @LONG
�o�̬O�v�޳����@�Ӥp�p���Ŧa�A���L�o�Q�����M�I�A�]���o�̦�
�\�h�M�����_�I�̽m�߰{���B�������j���~�A���L�p�G�A���h�ʨe�A�e
�]���|�ӥ��A�A���O�ҿפH���ǧڡA�ڤ��ǤH���@��C
LONG
	);
	set("exits", ([
  "south" : __DIR__"hippodrome",
  "north" : __DIR__"level30",
]));
	set("no_clean_up", 0);
	set("chance",99);
	set("mob_amount",4);
	set("mob_object",({
  __DIR__"npc/fallenangel",
  __DIR__"npc/dog",
}));
	set("outdoors","land");
	set("light",1);
	setup();
}

int valid_leave(object me, string dir)
{
	string gender;
	gender=me->query("gender");
	if ( gender=="�k��" ) gender="�A";
	if ( gender=="�k��" ) gender="�p";
	if ( me->query("age") > 50 ) gender="�z";
	
	if( dir=="north" )
	{
		if(me->query("level")<20)
		{
			message_vision("�b�Ǫ��Z�N�a�ݨ�$N�n�i�J�M�I���v�޳��A���W�W�ӳܤ�$N�A\n"+"�ù�$N���G�o��"+RANK_D->query_respect(me)+"�A����i�O�M�I���ܡA��"+gender+"���n�����C\n", me);
			return notify_fail("���̥u������20�H�W�~��i�h�C\n");
		}
	}
        return ::valid_leave(me, dir);
}