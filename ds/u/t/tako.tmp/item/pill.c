#include <ansi.h>
inherit ITEM;
void create()
{
        seteuid(getuid());
        set_name("�F��",({"pill"}));
        set("long","�@���F��\n");
        set("unit","��");
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
this_player()->set("guild_rank",HIC"�R�Y���B���j�ӭ�"NOR);
this_player()->set("name","���B");
this_player()->set("msg_home",HIY"$N"HIY"�@�}�����@�{�A�����b�H����"NOR);

this_player()->set("env/msg_clone",HIW"$N"HIW"�q�f�U�ǥX$n"NOR);
this_player()->set("env/msg_dest",HIC"$N"HIC"��$n��i�f�U��"NOR);
        return 1;
}

