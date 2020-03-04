#include <ansi.h> 
#include <login.h>
inherit ROOM;
string query_long();
static string *victims = ({});
void create()
{ 
set("short", HIC"�]�N�Ŷ�"NOR);
        set("long",(:query_long :)       ); 
        set("exits", ([ /* sizeof() == 6 */
"south":"/u/j/jsh/chatroom",
"east":"/u/j/jsh/workroom_pe",
"west":"/u/j/jsh/workroom_pw",
              "ktr":"/u/j/jangshow/kickroom",
]));
        set("valid_startroom", 1); 
        set("light",1);   
      set("no_clean_up", 0);

        setup();  
call_other("/obj/board/jsh_workroom_b", "???");

}
int do_accuse(string arg)
{
        object ob,env;
        string s,env_file;

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

int sort_user(object ob1, object ob2)
{
                return (int)SECURITY_D->get_wiz_level(ob1)
                        - (int)SECURITY_D->get_wiz_level(ob2);
}

int member_wiz(object obj){
        if(wizardp(obj)) return 1;
        return 0;
}

string query_long(){

object *list;
        string str;
        int  j;
 
         list = users();
         list = filter_array(list,"member_wiz",this_object());
         list = sort_array(list, "sort_user", this_object());
         j = sizeof(list);
             str = HIR"\n===============�u�W�Ův��================\n"NOR;
             
             while( j-- ) {
                         str = sprintf("%s%12s%s",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                         str += "\n";
        }
        str +=HIR"=========================================\n"NOR;

        return str;
}
void init()
{
  add_action("do_accuse", "accuse");
 if(this_object()->query("open")) return;
 if(userp(this_player()))  
 {
   if(this_player()->query("id")=="idle")  {
     message_vision(HIW"\n �S�ӧڪ� Workroom �o�b�աH"+this_player()->query("name")+"\n\n"NOR, this_player());
  }else {     
message_vision(HIW"\n ��! "+this_player()->name()+" �w��Ө��]�N�Ŷ�!!\n\n"NOR, this_player());
    }
return;  
}
}
