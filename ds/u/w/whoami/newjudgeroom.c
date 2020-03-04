#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�k�|");
        set("long", "�H�H�H�H�H�H");
        set("objects", ([
                __DIR__"judge":1,
]));
        set("exits", ([
                "down":        "/open/world1/tmr/area/hotel.c",
        ]) );
        set("light",1);
        setup();
}
void init()
{
        add_action("do_cmds","");
        add_action("do_list","list");
}
int do_list()
{
        write("\n\n

�C��N�X�C��G

                "HIG"�i"NOR"�Gg\t\t"HIY"�i"NOR"�Gy\n
                "HIR"�i"NOR"�Gr\t\t"HIM"�i"NOR"�Gm\n
                "HIW"�i"NOR"�Gw\t\t"HIC"�i"NOR"�Gc\n
                "HIB"�i"NOR"�Gb\n

�^���ɽп�J answer <�Ʀr+�C��> (EX�Ganswer 12345b)

\n\n");
        return 1;
}
int do_cmds(string arg)
{
        object me = this_player();

        if(wizardp(me)) return 0;
        if(userp(me) && present("ice judge", this_object()))
        {
                if((string)query_verb() == "i"  || (string)query_verb() == "say"
                || (string)query_verb() == "l"  || (string)query_verb() == "look"
                || (string)query_verb() == "sc" || (string)query_verb() == "quit"
                || (string)query_verb() == "hp" || (string)query_verb() == "answer"
                || (string)query_verb() == "sk" || (string)query_verb() == "inventory")
                return 0;
                else
                {
                        write(HIC"�B�P�x�N�N�����D�G�A�Q�Fԣ�H�O���|�k�ʳ�I\n"NOR);
                        return 1;
                }
        }
        else return 0;
}
void test_me(object me)
{
        me->set_temp("old_starroom", me->query("valid_startroom"));
        me->set("valid_startroom", __FILE__);
        me->set_temp("last_location", base_name(environment(me)));
        message_vision("���M�@�}�{���n��F$N�C\n", me);
        me->move(this_object());
}

