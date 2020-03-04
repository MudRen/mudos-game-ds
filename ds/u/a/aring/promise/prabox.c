// 從 CS 的Ckboy/box.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"粉盒"NOR, ({"box"}));
        set("long","附有鏡子的小粉盒\n使用方法: 化�� pra <某物(人)>\n卸�� unpra\n");
        set("unit", "盒");
}

void init()
{
        if( this_player()==environment() )
        add_action("do_pra","pra");
        add_action("do_unpra","unpra");
}

int do_pra(string arg)
{
        object me,*inv;
        int i;
        me=this_player();
        inv = all_inventory(environment(me));
        if(!arg) return notify_fail("你要扮成誰?\n");
        if(me->query("pra")) return notify_fail("你的�菑w經夠濃了!\n");
                for(i=0; i<sizeof(inv); i++)
                  {
                   if( arg == inv[i]->query("id"))
                    {
                        me->set("pra/bak_name", me->query("name"));
                        me->set("pra/bak_title", me->query("title"));
                        me->set("pra/bak_nickname", me->query("nickname"));
                        me->set("pra/bak_id", me->query("id"));
                        me->set("pra/bak_gender", me->query("gender"));
                        me->set("pra/pra", 1);
                        me->set("name", inv[i]->query("name"));
                        me->set("title", inv[i]->query("title"));
                        me->set("nickname", inv[i]->query("nickname"));
                        me->set("id", inv[i]->query("id"));
                        me->set("gender", inv[i]->query("gender"));
                        write(HIW"你拿出粉盒撲撲撲的扮成了"HIY+inv[i]->query("name")+"\n"NOR);
                        say(HIC+me->query("pra/bak_name")+HIW+"拿出粉盒撲撲撲的扮成了"HIY+inv[i]->query("name")+"\n"NOR);
                        return 1;
                  }
        return notify_fail("這裡沒這個人?\n");
}

int do_unpra(string arg)
{
        object me;


        me=this_player();

        if(!me->query("pra")) return notify_fail("你沒化��!!\n");

                me->set("name", me->query("pra/bak_name"));
                me->set("title", me->query("pra/bak_title"));
                me->set("nickname", me->query("pra/bak_nickname"));
                me->set("id", me->query("pra/bak_id"));
                me->set("gender", me->query("pra/bak_gender"));
                me->delete("pra");

                write(HIW"你將�菬齯F, 回復原本的面貌\n"NOR);
                say(HIC+me->query("name")+HIW+"將�菬齯F, 回復原本的面貌\n"NOR);
                return 1;
}


