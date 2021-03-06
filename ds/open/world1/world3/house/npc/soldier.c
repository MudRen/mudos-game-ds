#include <ansi.h>
inherit NPC;
void create()
{
        set_name("機械裝甲兵" ,({ "engine soldier","soldier" }) );
        set("level",5);
        set("age", 35);
        set("long",@long
他是一隻由晶片、電路、和金屬板所製成的機械裝甲兵。
這是最基本的裝甲兵，只能執行簡單的任務。
指令：
      認識主人： know <id>
      忘記主人： forget <某隻裝甲兵>
      執行動作： control <某隻裝甲兵> to <指令>

long
);
        setup();
} 
void init()
{ 
         add_action("do_know","know");
         add_action("do_forget","forget");
         add_action("do_control","control");
}
int do_know(string arg)
{
        object me,obj;
        me=this_player();
        obj=this_object();
        if(!obj->query("user"))
        {
          if( !arg ) return notify_fail("你要讓他認識誰？\n");
          message_vision("$N在裝甲兵體內輸了幾個字，裝甲兵從此認定"+arg+"為他的主人。\n",me);
          obj->set("user",arg);
        }
        else {
          if(me->query("id")==obj->query("user")) return notify_fail("你就是他的主人。\n");
          tell_object(me,"他已經有一個主人了，無法再記憶多餘之人。\n");
        }
        return 1;
}
int do_forget(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();
        if(arg == "soldier" || arg =="engine soldier")
        {
          if(ob->query("user") != me->query("id") )
          {
            message_vision("$N偷偷的想把手伸入裝甲兵的體中，但是被發現了。\n",me);
            ob->kill_ob(me);
          }         
          else {
            message_vision("$N手伸入裝甲兵的體中按了一下，裝甲兵忘記了主人了。\n",me);
            ob->delete("user");
          }
        }
        else {
           tell_object(me,"你要讓誰忘了主人？\n");
        }
        return 1;
}
int do_control(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if(ob->query("user")!=me->query("id") ) return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕control <某人> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}
