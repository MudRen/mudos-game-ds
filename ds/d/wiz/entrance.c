// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;
nosave string *victims = ({});
void create()
{
	set("short", "�Ův�|�ȫ�");
	set("long",@LONG
�o�̬O�Ův�M���a��Ѫ��a��M�p�G�A������N���n���Ův�̪��D�M�b�o��
�d���O�̧֪��~�|�M���L�p�G�O���C���������D�M�бz���T�w�ڭ̴��Ѫ�����
���̨S�������M�A���X�ðݡM�Ův���D�n¾�d�ä��O�Ъ��a�p�󪱡C
    [1;33m���F���������H�M�z�i�H�b�o�����|(accuse)�Y�Ӫ��a[0m�M�ӦW���a�|�Q��h
���@�Ǥp�p������M�ФŧQ�Ψ����Z�O�H�C
LONG
);
	set("exits", ([
		"west" : "/d/wiz/hall1",
        "east" : "/open/world2/anfernee/start/bug",
]) );
	set("no_fight", 1);
set("no_recall",1);
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
	add_action("do_look", "look");
}

int do_accuse(string arg)
{
	object ob,env;
         string env_file;

/*      return notify_fail("��p, �ثe���a���ݨϥ� accuse ���Y��, ��������. by linjack\n");
        if( (int)this_player()->query("level") < 25 )
                return notify_fail("�A���ŤӧC�F�M�S�����|�O�H���v�O�C\n");*/
          if( !wizardp(this_player()) )
                return notify_fail("��p, �ثe���a���ݨϥ� accuse ���Y��, ��������. by linjack\n");

	if( !arg ) return notify_fail("�A�n���|�֡S\n");
	if( ob = find_player(arg) )
	{
		if( ob==this_player() )
			return notify_fail("�A�n���|�ۤv�S\n");
		if( ob->is_ghost() )
			return notify_fail( ob->name(1) + "�w�g���F�M��L�@���a�C\n");
		if( ob->query_temp("killer") )
			return notify_fail( ob->name(1) + "���b�k�R�Ȯɤ������|�C\n");
		if( member_array(geteuid(ob),victims) != -1)
			return notify_fail( ob->name(1) + "�̪�w�g�Q���|�L�F�Ȯɤ������|�C\n");
        if(ob->is_inactive()) return notify_fail( ob->name(1) + "�ثe���B�󶢸m�Ҧ����C\n");
		if(!env=environment(ob))
			return notify_fail("�A�n���|�֡S\n");
		env_file=base_name(env);
		if(env_file=="/d/wiz/courthouse")
			return notify_fail(ob->name(1) + "�w�g�b��������F�C\n");
		if( wizardp(ob) )
			return notify_fail("�A�������|�Ův�C\n");
                tell_object(ob, HIW + this_player()->name(1) + " (" + this_player()->query("id") + ") ���|�A�O�Ӿ����H�M�ЧA�����@�Ӥp�p������C\n" NOR);
        // ob->set("accuse_position",env_file);
    switch(ob->money_type())
    {
/*
      case 1 : ob->set("accuse_position","/open/world1/tmr/area/hotel");
               break;
      case 2 : ob->set("accuse_position","/open/world2/lichi_town_2/map_5_26");
               break;
      case 3 : ob->set("accuse_position","/open/world3/tmr/basic/hotel");
               break;
*/
      default : ob->set("accuse_position","/open/world2/anfernee/start/hall");
                break;
    }
		victims += ({geteuid(ob)});
		ob->save();
		ROBOT_CHECK->test_me(ob);
		if(!wizardp(this_player()))
		{
			write("Ok. �w�g�N�A���|����H�e�h������C\n");
			write("���F�קK���H�ξ����H�����|���Z�O�H�M�ЧA�]�����ۦP������C\n");
            // this_player()->set("accuse_position",base_name(this_object()));
     this_player()->set("accuse_position","/open/world2/anfernee/start/hall");
			this_player()->save();
			ROBOT_CHECK->test_me(this_player());
		}
		log_file("robot_accuse",
			sprintf("%s accused %s on %s.\n", this_player()->query("id"), ob->query("id"), ctime(time())));
		return 1;
	}
	return notify_fail("�ثe�u�W�èS���o�쪱�a�C\n");
}

void reset()
{
  add("reborn",1);
  if(query("reborn") < 4) return;
  delete("reborn");
	::reset();
	victims = ({});
}

int do_look(string arg)
{
	if( arg == "west" )
{
	return 1;
}
}
// add by alickyuen@ds
