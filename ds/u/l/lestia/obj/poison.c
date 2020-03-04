#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"�r��"NOR, ({ "poison" }));
        set("long", "�o�O�r��, �i�Hthrow�b�O�H���W�C\n");
        set("unit", "�]");
        set("value", 10000);
        set_weight(1);
}

void init()
{
        add_action("do_throw","throw");
}

int do_throw(string arg)
{
        string obname, id;
        object item, ob;

        if(!arg) return notify_fail("throw <item> to <target>\n");
        if(sscanf(arg, "%s to %s", obname, id) != 2) return notify_fail("throw <item> to <target>\n");
        if(!item = present(obname, this_player())) return notify_fail("�A�S���o�تF��C\n");
        if(base_name(item) != base_name(this_object())) return notify_fail("���F�褣��o�˥ΡC\n");
        if(!ob = present(id, environment(this_player()))) return notify_fail("�o�̨S���o�ӤH�C\n");
        if(!living(ob)) return notify_fail("�����O�����C\n");
        message_vision("$N���W���r���x�V�F$n, $n���W�}�l����r���I�k...\n", this_player(), ob);
        ob->apply_condition("poison", 6);
        destruct(this_object());
        return 1;
}

