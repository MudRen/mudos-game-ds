#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        seteuid(getuid());
        set_name(HIG"�קﾹ"NOR,({"anything item","item"}));
        set("long","�m��קﾹ\n");
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
this_player()->set("guild_rank",HIC"�ѳz"HIY"�Ѧt�騽"HIC"�U��"NOR);
this_player()->set("name",HIW"�y���L��l"NOR);

 return 1;

}

