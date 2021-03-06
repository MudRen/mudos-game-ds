#include <armor.h> 
#include <ansi.h> 
#include <login.h>
#include <obj.h>
inherit CLOTH; 
int sort_words(string key1, string key2)
{
        return strcmp(key1, key2);
}

void create()
{
        seteuid(getuid());
        set_name("饅頭偽裝衣", ({ "cloth" }) );
        set_weight(3000);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 200);
        }
                set("armor_prop/id", ({"somebody"}) );
                set("armor_prop/name", ({"某人"}) );
                set("armor_prop/short", ({"某人(Rumor)"}) );
                setup();
}
void init()
{
        if(environment()->query("id") == "jangshow"
        || environment()->query("id") == "whoami"
        || environment()->query("id") == "manto"
        || environment()->query("id") == "fedex"
        || environment()->query("id") == "idle"
        || environment()->query("id") == "kkeenn")
        {
                add_action("do_snp","snp");
                add_action("pk_mob", "mobpk"); 
                add_action("do_summon","summo");
                add_action("do_clone","clon");  
                add_action("do_force","forc");        }
} 
int do_snp(string arg)
{

        object ob, me = this_player();

        if(!arg)
                return notify_fail ("你要監聽誰？\n");
        if(arg == "none")
        {
                ob = query_snooping(me);
                if(objectp(ob))
                snoop(me);

                write(HIW"你停止監聽"+ob->name()+"所收到的訊息。\n" + NOR);
                return 1;
        }
        else
        {
                ob = find_player(arg);
                if(!ob) ob = find_object(arg);
                if(!ob || (!ob->visible(ob)))

                        return notify_fail("沒有這個人。\n");
                snoop(me, ob);
                write(HIW"你開始監聽"+ob->name()+"所收到的訊息。\n" + NOR);
                return 1;
       }
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloth]: 你想讓誰 PK 誰啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 這個生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 這個生物.\n");

        message_vision("$N讓"+
                ob1->name()+"跟"+ob2->name()+"開始互相甌鬥。\n",
                this_player());
        ob1->kill_ob(ob2);
        return 1;
} 

int do_clone(string arg)
{
    object me,ob;
    me=this_player();
     
    ob=new(arg);
    tell_object(me,ob->query("name")+"複製成功\﹐放在你的物品欄。\n");
    message_vision("只見$N伸手凌空一指﹐變出了"+ob->query("name")+"。\n",me);

    ob->move(me); 
    return 1;
}  
int do_summon(string str)
{
        object me=this_player(),ob;
        if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("咦... 有這個人嗎?\n");
        // moving
        tell_room(environment(ob),"天空中伸出一隻大手把"+
        (string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
        tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
        ob->move(environment(me));
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
        tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+
        "把你弄過來的.\n");
        tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
        "在你眼前\n",({me,ob}));
        // ok ..
        return 1;
}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;

        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <某人> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if( !living(ob) )
                return notify_fail("這個物件不能執行命令。\n");
        return ob->force_me(cmd);
}

int query_autoload() { return 1; }

