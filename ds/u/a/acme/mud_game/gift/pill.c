#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("���}�����Y", ({ "pill" }));
        set_weight(1);
        set("long","���}�����Y�A�Y(eating)�F�|�W�[�H���g���(exp)�C\n");
        if( !clonep() ) {
                set("unit", "��");
                set("long","���}�����Y�A�Y(eating)�F�|�W�[�H���g���(exp)�C\n");
        }
        setup();
}

void init()
{
        add_action("do_eating","eating");
}

int do_eating(string arg)
{
        if( !arg ) return notify_fail("�A�Q�Y����H\n");
        if( arg != this_object()->query("id") )
                return notify_fail("�A�Q�Y����H\n");
        message_vision("$N�Y�U�F�@��$n�üW�[�F "+this_object()->query("add_exp")+" �I�H���g���(exp)�C\n",this_player(),this_object());
        this_player()->add("exp",this_object()->query("add_exp"));
        destruct(this_object());
        return 1;
}
