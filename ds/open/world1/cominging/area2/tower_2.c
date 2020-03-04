#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�u�ö�"HIY"�ܮw"NOR);
	set("long", @LONG

�A�@�B�B�����W���䪺�۱�A�@�}�}���n�T�H�ۧA���}�B���T�_�A
�����D�çL���S���`�N��A�o�̬O�u�ö𤧤��A�o�̨S������F��A�@
�Ө��Y�A���䦳�X�����~�����l�A�ݪ��컷�B���ɿ��M�n�誺�˪L�s��
�ۡA�����ۨǷϤ��A�M�@�Ǥ}�B�b�C

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"tower_3.c",
  "down" : __DIR__"tower.c",
]));
	set("objects",([
  __DIR__"npc/partol_g.c": 2,
]));
	set("item_desc",([
  "���l" : "�o�O�@�����l�A�i�H�[��컷�B�ɿ��A�]�i�H�ݱo��n��˪L���s��ۡA�ӫK��u�áC\n",
  "�۱�" : "�@�����Υ��Y��������l�A�W���Q�ۤ@�h�_��C\n",
  "�Ϥ�" : "�@����n���Ϥ��A�O�b�~�ĤJ�I�ɩ�Ϊ��C\n",
  "�}" : "�@�ǥΤ찵�����}�A���O���ǳ��w���ε����ӻG��C\n",
  "�b" : "��b�a�W�@�ιΩ�b�@�_���b�A�i��i�H���_�ӧa�C\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_2");
	setup();
}

void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, arrow, guard;

	me = this_player();
	arrow = new(__DIR__"npc/obj/arrow2.c");

	if( arg!="�b" && arg!="arrow" ) return 0;
	arrow->move(me);
	message_vision("$N�߰_�F�a�W���@�ǽb�C\n",me);
	if( !living(guard=present("patrol guard",this_object())) ) return 1;
	message_vision("$N�j�ܡG�Fԣ�I���߭x�w�x���H�I\n",guard);
	guard->kill_ob(me);
	me->kill_ob(me);
	return 1;
}