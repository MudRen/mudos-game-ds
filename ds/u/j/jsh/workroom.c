#include <ansi.h> 
#include <login.h>
inherit ROOM;
string query_long();
static string *victims = ({});
void create()
{ 
set("short", HIC"魔術空間"NOR);
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

/*      return notify_fail("抱歉, 目前玩家氾濫使用 accuse 太嚴重, 予此停用. by linjack\n");
        if( (int)this_player()->query("level") < 25 )
                return notify_fail("你等級太低了﹐沒有檢舉別人的權力。\n");*/
          if( !wizardp(this_player()) )
                return notify_fail("抱歉, 目前玩家氾濫使用 accuse 太嚴重, 予此停用. by linjack\n");

        if( !arg ) return notify_fail("你要檢舉誰﹖\n");
        if( ob = find_player(arg) )
        {
                if( ob==this_player() )
                        return notify_fail("你要檢舉自己﹖\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) + "已經死了﹐放他一馬吧。\n");
                if( ob->query_temp("killer") )
                        return notify_fail( ob->name(1) + "正在逃命暫時不能檢舉。\n");
                if( member_array(geteuid(ob),victims) != -1)
                        return notify_fail( ob->name(1) + "最近已經被檢舉過了暫時不能檢舉。\n");
        if(ob->is_inactive()) return notify_fail( ob->name(1) + "目前正處於閒置模式中。\n");
                if(!env=environment(ob))
                        return notify_fail("你要檢舉誰﹖\n");
                env_file=base_name(env);
                if(env_file=="/d/wiz/courthouse")
                        return notify_fail(ob->name(1) + "已經在接受測驗了。\n");
                if( wizardp(ob) )
                        return notify_fail("你不能檢舉巫師。\n");
                tell_object(ob, HIW + this_player()->name(1) + " (" + this_player()->query("id") + ") 檢舉你是個機器人﹐請你接受一個小小的測驗。\n" NOR);
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
                        write("Ok. 已經將你檢舉的對象送去做測驗。\n");
                        write("為了避免有人用機器人亂檢舉騷擾別人﹐請你也接受相同的測驗。\n");
            // this_player()->set("accuse_position",base_name(this_object()));
     this_player()->set("accuse_position","/open/world2/anfernee/start/hall");
                        this_player()->save();
                        ROBOT_CHECK->test_me(this_player());
                }
                log_file("robot_accuse",
                        sprintf("%s accused %s on %s.\n", this_player()->query("id"), ob->query("id"), ctime(time())));
                return 1;
        }
        return notify_fail("目前線上並沒有這位玩家。\n");
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
             str = HIR"\n===============線上巫師有================\n"NOR;
             
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
     message_vision(HIW"\n 又來我的 Workroom 發呆啦？"+this_player()->query("name")+"\n\n"NOR, this_player());
  }else {     
message_vision(HIW"\n 嗨! "+this_player()->name()+" 歡迎來到魔術空間!!\n\n"NOR, this_player());
    }
return;  
}
}
