#include <path.h>
#include <ansi.h>
#include <net/daemons.h>
#include <command.h>
#include <login.h>
inherit ROOM;

void create()
{
        set("short", "夢幻福利站");
        set("long", @LONG
這裡是夢幻旅館的販賣部。這裡的東西大部分是林老闆撿回來的，所
以品質並不是很好，但也勉強能派上用場。這裡用的錢幣是目前一般通行
市面上所使用的現金。

LONG
        );
        set("objects", ([
        "/u/l/lary/sword2" : 1,
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}

void init()
{
 add_action("do_sum","sum");
 add_action("do_ca","ca");
}

int do_ca(string arg)
{
        string objname, func, param, euid;
        object obj;
        object me = this_player();
        mixed *args, result;
        int i;

        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("你不能設定自己的 euid。\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("指令格式﹕call <物件>-><函數>( <參數>, ... )\n");
        } else
                return notify_fail("指令格式﹕call <物件>-><函數>( <參數>, ... )\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("找不到指定的物件。\n");




        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(me, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}

int do_sum(string str) 
{        
        object me = this_player(); 
        object ob;
        int i;
        if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("沒有這個人\n");
        // moving
        ob->move(environment(me));
        tell_object(me, HIC"你把"HIW""+(string)ob->query("name")+""HIC"找來.\n");
               // ok ..
        return 1;
}
