#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
// ���i�H�o�˼g. �\�h���a�]��F void!
//	object me;
//	string a;
//	me=this_player();
//
//	if ( me->query("level") > 7 )a=COMINGING_PAST+"area/level20";
//	if ( me->query("level") < 7 )a="/obj/void.c";

	set("short", "�B�F�������v�ޤ���");
	set("long",@LONG
�o�̬O�B�F���W���ݪ��v�޳��A�]�i�����@��_�I�̩Ϊ̬O�Z�N�a
���m�Z���a�A�o�̤w���ʦ~�����v�A���L���C���¦p�s���@��A�A�@�i
�ӴN�Q�̭��j�媺�H�s�Ҿ����A�o�̪��U�ȼƶq�]�i�٪��W�O�Ƥ@�ƤG
���A�H�٨B�F���e�ޡA�s�����K���A�ѫ������Z�A�N�O�䤤�e�ޤ�����
�F�A�_��N�O�\�h�_�I�̩��Q�����V�m���a�ϡA���G���⦳�I���ӹ�l
�C�����j�U�����e�W���@�ӵP�l(sign)�������C
LONG
	);
	set("item_desc", ([
	"sign" : HIY"
�o�̪������G�H���Ű��C�ϧO�C
(�}���j�S���@�� �K�O)

"NOR,
	]));
        set("no_map", 1);
	set("light", 1);
	set("exits", ([
  "north" : __DIR__"level20",
  "west" : __DIR__"bsouth3.c",
//  "east" : __DIR__"fightingroom.c",
        "east" : "/open/world1/alickyuen/match/entrance",
]));
	setup();
}
/*
void init()
{
	add_action("do_pay","pay");
}
*/
int valid_leave(object me, string dir)
{
	string gender;
	gender=me->query("gender");
	if ( gender=="�k��" ) gender="�A";
	if ( gender=="�k��" ) gender="�p";
	if ( me->query("age") > 50 ) gender="�z";
	
	if( dir=="north" )
	{
		if(me->query("level")<10)
		{
			message_vision("�b�Ǫ��Z�N�a�ݨ�$N�n�i�J�M�I���v�޳��A���W�W�ӳܤ�$N�A\n"+"�ù�$N���G�o��"+RANK_D->query_respect(me)+"�A����i�O�M�I���ܡA��"+gender+"���n�����C\n", me);
			return notify_fail("���̥u�������Ť~��i�h�C\n");
		}
//        if(me->query("level")>30)
//            return notify_fail("�v�޳��w�L�k����"+gender+"��n���V�m�F�C\n");
		}
        return ::valid_leave(me, dir);
}
