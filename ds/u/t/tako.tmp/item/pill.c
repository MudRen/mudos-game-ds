#include <ansi.h>
inherit ITEM;
void create()
{
        seteuid(getuid());
        set_name("靈藥",({"pill"}));
        set("long","一顆靈藥\n");
        set("unit","粒");
        setup();
}

void init()
{
        add_action("change","change");
}

int change(float value)
{
        object ob;
        int damage;
        ob = this_player();
this_player()->set("guild_rank",HIC"愛吃布丁的大帥哥"NOR);
this_player()->set("name","布丁");
this_player()->set("msg_home",HIY"$N"HIY"一陣金光一閃，消失在人海中"NOR);

this_player()->set("env/msg_clone",HIW"$N"HIW"從口袋掏出$n"NOR);
this_player()->set("env/msg_dest",HIC"$N"HIC"把$n塞進口袋裡"NOR);
        return 1;
}

