// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;
static string *victims = ({});
void create()
{
        set("short", "�Ův�|�ȫ�");
        set("long",@LONG
�o�̬O�Ův�M���a��Ѫ��a��M�p�G�A������N���n���Ův�̪��D�M�b�o��
�d���O�̧֪��~�|�M���L�p�G�O���C���������D�M�бz���T�w�ڭ̴��Ѫ�����
���̨S�������M�A���X�ðݡM�Ův���D�n¾�d�ä��O�Ъ��a�p�󪱡C
    ���F���������H�M�z�i�H�b�o�����|(accuse)�Y�Ӫ��a�M�ӦW���a�|�Q��h
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
 }
void init()
{
        add_action("do_accuse", "accuse");
        add_action("do_look", "look");
}

int do_accuse(string arg)
{
        object ob,env;
        string s,env_file;

         
        if( !arg ) return notify_fail("�A�n���|�֡S\n");
        if( ob = find_player(arg) )
        {
                if( ob==this_player() )

                        return notify_fail("�A�n���|�ۤv�S\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) + "�w�g���F�M��L�@���a�C\n");
                if( ob->query_temp("killer") )
                        return notify_fail( ob->name(1) + "���b�k�R�Ȯɤ������|�C\n");
        if(ob->is_inactive()) return notify_fail( ob->name(1) + "�ثe���B�󶢸m�Ҧ����C\n");
                if(!env=environment(ob))
                        return notify_fail("�A�n���|�֡S\n");
                env_file=base_name(env);
                if(env_file=="/d/wiz/courthouse")
                        return notify_fail(ob->name(1) + "�w�g�b��������F�C\n");
                                tell_object(ob,"�Y�H���|�A�O�Ӿ����H�M�ЧA�����@�Ӥp�p������C\n" NOR); 
 message("world:world1:vision",
HIG"\n[0;1;37;44m�[1mi[1m�[1mC[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mj[0m "HIW"�Y�H"HIW"�ݤ��D"HIB+ ob->name(1)+HIW"������M�A�׵������@���A�b���ɳQ��h�f�P�U�f�ݤF�I�I
\n\n"NOR,users());
        // ob->set("accuse_position",env_file);
    switch(ob->money_type())
    {
      case 1 : ob->set("accuse_position","/open/world1/tmr/area/hotel");
               break;
      case 2 : ob->set("accuse_position","/open/world2/lichi_town_2/map_5_26");
               break;
      case 3 : ob->set("accuse_position","/open/world3/tmr/basic/hotel");
               break;
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


