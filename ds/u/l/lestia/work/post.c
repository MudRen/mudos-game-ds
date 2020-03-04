#define WALLDATA        "/u/l/lestia/log1/post.txt"
#include <ansi.h>
inherit ROOM;
string base_long;
void load_wall_data();
void create() {

     set("short", HIC"留言房"NOR);

        base_long = @LONG



         
你要post 什麼?



---------------------------------------------------
LONG;
        set("long", base_long);
        set("exits", ([
   "down" : "/u/l/lestia/workroom",
        ]));

        setup();
        load_wall_data();
}
void init()
{
write (HIW+"\n
嗨∼"+HIB+this_player()->query("name") +HIC+"--"+HIY+"有問題可以留下來喔(post xxx)∼！\n\n \n"+NOR);
   add_action("to_post","post");
}
int to_post(string arg) {

        object usr;

        usr = this_player();
  if(!userp(usr) )
                return notify_fail("非玩家角色不能留言。\n");
if(usr->query_temp("invis")) return notify_fail("隱形不能留言。\n");


        if(arg) {
 write_file(WALLDATA, usr->query("name")+"("+ usr->query("id") +"):" + arg + "\n");
                message_vision("$N一直不斷的寫寫寫，終於把留言寫上了。\n", usr);
                tell_object(usr, "放心吧! 您的留言會很快的答覆您的!\n");
                load_wall_data();
                return 1;
        }
        else
                return notify_fail("您要留什麼留言?\n");


}

void load_wall_data() {

        string appendlong;

        if(file_size(WALLDATA) == -1) {
                appendlong = "\n    暫時沒有任何的ｐｏｓｔ。";
        }
        else {
                appendlong = "\n    以下是每個人在這裡所留的ｐｏｓｔ:\n\n" + read_file(WALLDATA);
        }

        set("long", base_long + appendlong + "\n");

}


