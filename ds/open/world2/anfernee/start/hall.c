// bug.c
#include <path.h>
inherit ROOM;
string look_sign(object me);
void create()
{
	set("short", "���]�j�U");
	set("long", @LONG
�o�̬O�ڤۮ��]���j�U�C�j�U�����������۪����ӱ�A�e�褣������
���D�A�����W�K�F�@�ǧi��(Note)�C�����䦳�Ӫ��Y�A���Y���t�@�ݪx
�ۯ�����������~�A�ϤH�Pı��̭������i��ĳ�����j�O�q�C�k��h�O��
���]���ӫ~����B�C

LONG
	);
	set("objects", ([
	__DIR__"npc/master" : 1,
	ALWAYS"newspaper": 1,
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"login",
 "west" : __DIR__"bug",
 "east" : __DIR__"shoproom",
 "north": __DIR__"hall2",
 "up": __DIR__"prayroom",
// "past" : TMR_PAST"area/hotel",
	]) );
	set("item_desc", ([
		"note": (: look_sign :),
		"�i��": (: look_sign :),
	]) );
	set("light",1);
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_kill",1);
	setup();
	call_other( "/obj/board/login_b", "???" );
}

string look_sign(object me)
{
   if( file_size("/open/world2/anfernee/start/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/anfernee/start/note.txt") );
    return "\n";
   } else return " SORRY. �����غc��. \n";
}

