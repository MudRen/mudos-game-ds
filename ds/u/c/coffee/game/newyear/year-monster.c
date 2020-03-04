#include <ansi.h>
inherit NPC;
mapping exit=([ ]); 
string where ="";

mapping areas= ([
        "/open/world1/acme/area/" : "天城",
        "/open/world1/moonhide/area/" : "天界",
        "/open/world1/tmr/area/" : "滄縣",
        "/open/world1/wilfred/meadow/" : "牯牛草原",
        "/open/world1/wu_sha_town/" : "無沙鎮", 
        "/open/world1/cominging/area/" : "步靈城",]);

int restart();
string eq_check();
void create()
{
        set_name(HIY"年獸"NOR, ({ "year monster","monster"}) );
        set("long","一隻非常強壯的野獸，在過年時才會來這裡。\n");
        set("title",HIG"新年快樂"NOR);
        set("level",30);
        set("race","野獸");
        set("age",777);
        set("no_fight", 1);
        set("monster-beard",1);
        set("chat_chance", 10);
        set("chat_msg", ({
//                (: return_home(load_object("/open/world1/cominging/area/boo-lin")) :),
                "年獸朝著天空不停的喊叫「吼~」！\n", }) 
        );
        setup();
             set_living_name("monster-beard");
}
void init()
{
        object me,obj;
        ::init();
        me=this_player();
        if(objectp(obj=present("cracker",me) ) )
        {
          call_out("flee",2);
        }
}
int flee()
{
        int i;
        object me,obj,env;
        string to_dir,to_dir_name,*dir,*dir_name;
        obj=this_object();
        me=this_player();

        env = environment(me);
        exit = env->query("exits");
        dir_name = keys(exit);
        dir = values(exit);

        i = random(sizeof(dir));
        to_dir = dir[i];
        to_dir_name = dir_name[i];
        obj->move(to_dir);
        message_vision("$n發現$N拿著紅色的東西，十分好奇。\n",me,obj);
        write( obj->query("name")+"往"+to_dir_name+"緩慢的走過去了。\n");
        return 1;
}

