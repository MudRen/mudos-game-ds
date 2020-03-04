// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�Ův�|�ȫ�");
	set("long",
		"�o�̬O�Ův�M���a��Ѫ��a��M�p�G�A������N���n���Ův�̪��D�M�b�o��\n"
	"�d���O�̧֪��~�|�M���L�p�G�O���C���������D�M�бz���T�w�ڭ̴��Ѫ�����\n"
	"���̨S�������M�A���X�ðݡM�Ův���D�n¾�d�ä��O�Ъ��a�p�󪱡C\n"
	"    ���F���������H�M�z�i�H�b�o�����|(accuse)�Y�Ӫ��a�M�ӦW���a�|�Q��h\n"
	"���@�Ǥp�p������M�ثe�o���\\��|�������󭭨�M�ФŧQ�Ψ����Z�O�H�C\n");
	set("exits", ([
		"west" : "/d/wiz/hall1",
        "east" : "/open/world2/anfernee/start/bug",
]) );
	set("no_fight", 1);
	set("no_magic", 1);
   set("light",1);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("���̥u���Ův�~��i�h�C\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
	object ob;
	string s;

	if( (int)this_player()->query("age") < 15 )
		return notify_fail("�A�~���Ӥp�F�M�S�����|�O�H���v�O�C\n");

	if( !arg ) return notify_fail("�A�n���|�֡S\n");
	if( ob = find_player(arg) ) {
		if( ob==this_player() )
			return notify_fail("�A�n���|�ۤv�S\n");
		if( ob->is_ghost() )
			return notify_fail( ob->name(1) + "�w�g���F�M��L�@���a�C\n");
		if( wizardp(ob) )
			return notify_fail("�A�������|�Ův�C\n");
		if( this_player()->query_temp("accuse")>=1 || this_player()->query("accuse")>10 )
			return notify_fail("�A����@�A�����|���a�C\n");
		this_player()->set_temp("accuse",1);
		this_player()->add("accuse",1);
		tell_object(ob, HIW + this_player()->name(1) + "���|�A�O�Ӿ����H�M�ЧA�����@�Ӥp�p������C\n" NOR);
		ROBOT_CHECK->test_me(ob);
		write("Ok. �w�g�N�A���|����H�e�h������C\n");
		write("���F�קK���H�ξ����H�����|���Z�O�H�M�ЧA�]�����ۦP������C\n");
		ROBOT_CHECK->test_me(this_player());
		log_file("robot_accuse",
			sprintf("%s accused %s on %s.\n", this_player()->query("id"), ob->query("id"), ctime(time())));
		return 1;
	}
	return notify_fail("�ثe�u�W�èS���o�쪱�a�C\n");
}

