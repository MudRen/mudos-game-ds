// bug.c

inherit ROOM;

void create()
{
	set("short", "���Φ^����");
	set("long", @LONG
���F�W�i��Mud���\��A��M�ݭn�U�쪱�a�������H�Ψ�U�A�^��Bug
�i�H���ڤۤC���[�������A�]�i�H���U�쪱�o��ɿ��A��M�A�^��Bug
�N�|�����p���Ҽ���C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hall",
 "west" : "/d/wiz/entrance",
	]) );
 set("hide_exits", ([ "north" : __DIR__"award" ]));
	set("objects", ([
	__DIR__"npc/banker" : 1,
	]) );
	set("light",1);
set("no_recall",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
	call_other( "/obj/board/bug_b", "???" );
}

