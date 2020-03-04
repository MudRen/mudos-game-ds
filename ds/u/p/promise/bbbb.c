// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;
static string *victims = ({});
void create()
{
        set("short", "巫師會客室");
        set("long",@LONG
這裡是巫師和玩家聊天的地方﹐如果你有什麼意見要讓巫師們知道﹐在這裡
留言是最快的途徑﹐不過如果是對於遊戲中的問題﹐請您先確定我們提供的說明
文件裡沒有說明﹐再提出疑問﹐巫師的主要職責並不是教玩家如何玩。
    為了杜絕機器人﹐您可以在這裡檢舉(accuse)某個玩家﹐該名玩家會被抓去
做一些小小的測驗﹐請勿利用來騷擾別人。
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

         
        if( !arg ) return notify_fail("你要檢舉誰﹖\n");
        if( ob = find_player(arg) )
        {
                if( ob==this_player() )

                        return notify_fail("你要檢舉自己﹖\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) + "已經死了﹐放他一馬吧。\n");
                if( ob->query_temp("killer") )
                        return notify_fail( ob->name(1) + "正在逃命暫時不能檢舉。\n");
        if(ob->is_inactive()) return notify_fail( ob->name(1) + "目前正處於閒置模式中。\n");
                if(!env=environment(ob))
                        return notify_fail("你要檢舉誰﹖\n");
                env_file=base_name(env);
                if(env_file=="/d/wiz/courthouse")
                        return notify_fail(ob->name(1) + "已經在接受測驗了。\n");
                                tell_object(ob,"某人檢舉你是個機器人﹐請你接受一個小小的測驗。\n" NOR); 
 message("world:world1:vision",
HIG"\n[0;1;37;44m�[1mi[1m�[1mC[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mj[0m "HIW"某人"HIW"看不慣"HIB+ ob->name(1)+HIW"的放機和態度等等的作風，在此時被抓去審判廳審問了！！
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

int do_look(string arg)
{
        if( arg == "west" )
{
        return 1;
}
}
// add by alickyuen@ds


