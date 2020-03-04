#include <ansi.h>
inherit NPC;
void create()
{
set_name("恨無敵",({"vicch"}));
set("level",25);
set("age",45);
set("long","一個殺人不眨眼的大魔頭，從他眼中可看見一絲怨恨。\n");
set("gender", "男性");
        setup();
}
void init()
{
         add_action("do_force","force");
}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
//      if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <某鬼魂> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}
