#include <ansi.h>
inherit ITEM;
void create()
{       set_name(HIG"夢幻控制器"NOR,({ "dream control item","item" }));
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else
{       set("long",HIG"遊龍俠用來幫助自己的利器"NOR);
        set("unit","個");
        set("value",0);
 }
        setup();
}
int query_autoload() { return 1; }
void init()
{
object env;
   this_object()->set_temp("invis",1);
add_action("do_summon", "osummon");
add_action("do_uninvis", "uninvis");
add_action("do_invis2", "invis2");
add_action("do_putjail", "oputjail");
add_action("do_butt", "butt");
add_action("do_qwiz", "qwiz");
}
int do_qwiz(string arg)
{
        int i,j=0,n,idle;
        object *user_list,where;
        string status1, status2, status3;

        user_list = users();
        n = sizeof(user_list);
        write(HIW"你透過"+this_object()->name()+HIW"，感應這個世界，"HIY"腦海中"
HIG"霎時"HIW"出現了線上的wiz:\n"NOR);
        for( i=0 ;i<n ;i++)
        {
                if( wizardp(user_list[i]))
                {
                        where = environment(user_list[i]);
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIY"(INPUT)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i])))
        status2=sprintf(HIY"(EDIT: %s)"NOR,in_edit(user_list[i]));
                                else status2="";
                        if (idle>180) status3=sprintf(HIY"(IDLE %d MIN)"NOR,idle
/60);
                                else status3="";
                        write(sprintf("TTF [ %2d %12s %s(%s) 正在 %s(%s) ]\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where)));
                        if ((status1!="")||(status2!="")||(status3!=""))
                        write(sprintf("TTF [                STATUS: %s%s%s]\n",
                                      status1,status2,status3));
                        j++;
                }
        }
        return 1;
}
int do_putjail(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("你想要關誰 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
  return notify_fail("這裡沒有這個人。\n");
       if(obj==me)
        return notify_fail("別想不開!\n");
        message_vision(HIC"$N"HIR"伸出"HIW"正義之爪"HIR"將$n抓進了一個莫名其妙的世界。\n"NOR,me,obj);
        call_out("pu",1,me,obj);
        return 1;
       }
void pu(object me,object obj)
{
if(!me) return;
obj->set("out_of_power",1); 
obj->move("/open/always/ppl_jail");
obj->save();
"/open/always/ppl_jail"->jail_time(obj, 7);
return;
}


int do_summon(string str)
{
        object me = this_player();
        object ob;
     if (!str) return notify_fail("<Syntax>: Summon <player id>\n"); 
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("咦... 有這個人嗎?\n");
        if(ob->query("env/god_enable") >= 3) return notify_fail("沒有這個人。\n");       
        tell_room(environment(ob),"天空中伸出一隻大手把"+(string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
        tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
        ob->move(environment(me));
        tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+"把你弄過來的.\n");
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
        "在你眼前\n",({me,ob}));
        return 1;
}
int do_invis2(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("你想要讓誰隱形 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
  return notify_fail("這裡沒有這個人。\n");
       if(obj==me)
        return notify_fail("不會自己用invis阿...Stupid\n");      message_vision(HIC"$N"HIR"使出"HIW"軒轅虛無掌"HIR"往$n重重的拍下去。\n"NOR,me,obj);
        call_out("inv",1,me,obj);
        return 1;
       }
void inv(object me,object obj)
{
if(!me) return;
message_vision(HIC+obj->query("name")+"的身形漸漸地消失了....\n"NOR,me,obj);
obj->set_temp("invis",3); 
return;
}
int do_uninvis(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("你想要讓誰現形 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
         return notify_fail("這裡沒有這個人。\n");
         if(obj==me)
        return notify_fail("不會自己用invis阿...Stupid\n"); 
message_vision(HIC"$N用"HIW"蚩尤現形掌"HIC"輕輕的打在$n身上。\n"NOR,me,obj);
        call_out("uninv",1,me,obj);
        return 1;
       }
void uninv(object me,object obj)
{
if(!me) return;
message_vision(HIC+obj->query("name")+"的身形在一團火焰中出現了！！\n"NOR,me,obj);
obj->delete_temp("invis"); 
obj->delete_temp("hide"); 
return;
}
   int do_butt(string arg)
      {
        string title, note;
     if( !arg || sscanf(arg ,"%s %s",title,note) != 2 ) return notify_fail("[格式] butt <> <內容>\n");
      message("world:world1:vision",
      HIY"☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n"HIR"《"+ title +"》\n"HIW":" + note + HIY"\n☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★"+NOR,users());
         return 1;
      }

