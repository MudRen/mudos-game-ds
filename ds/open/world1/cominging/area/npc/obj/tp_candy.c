#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"���}"NOR, ({ "red lane candy", "candy" }));
        set("long", "�o�O�@����ƥ��G���@���p�}�G�A�Y�F�n������諸�@�ΡC\n");
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1250);
                set("add_tp", 25);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player(), env;
        int max_tp = me->query("level")*3+5;

        if( !arg ) return 0;

        if( !this_object() ) return 0;

        if( !this_object()->id(arg) ) return 0;

        if( !env = environment(this_object()) ) return 0;

        if( env != me ) return 0;

        if( query("add_tp") )
        {
                if( me->query("talk_point") < max_tp )
                        me->add("talk_point", query("add_tp"));
                if( me->query("talk_point") > max_tp )
                        me->set("talk_point", max_tp);
        }

        if( this_player()->is_fighting() ) this_player()->add_block(1);

        message_vision("$N���_�@��$n, �@�f�K�]�F�U�h, �y�ɳ��V���G�n�F�\\�h�I\n", me, this_object());
        destruct(this_object());
        return 1;
}

int is_pill() { return 1; }
int is_food() { return 1; }

