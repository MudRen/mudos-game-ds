#include <ansi.h>
inherit ITEM;

string *longs = ({
  "�o�O�@���w�ʦL���j�ۡA�W���ٳ�ۤ@�����ѲũG�զ�����÷�A���G�]���~�N�w�[�����Y�A\n�W�����ůȦ��ǲ渨�A���ǳQ�I�k�A���������S�X�F�F��A�O�H�����i���C\n",
  HIR"�j�ۤW�٦��Ǧ��C\n"NOR,
});

void create()
{
        set_name(HIR"�ʦL���j��"NOR, ({ "cachet stone", "stone" }));
        set("long", longs[0] );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1);
                set("no_get", 1);
                set("no_sac", 1);
        }
        setup();
}

void init()
{
        add_action("do_place", "place");
}

int do_place(string arg)
{
        object me, ob, tar;
        me = this_player();
        ob = this_object();

        if( !arg ) return notify_fail("�A�n���^����F�赹�j�ۡH\n");
        if( !objectp(tar = present(arg, me)) )
                return notify_fail("�A���W�S���o�ӪF���A�n��򲽪��r�H\n");
        if( tar->query("id") != "fox teeth" )
		return notify_fail("�A��" + tar->name() + "���^���j�ۡA���L���G�S����Ƶo�͡A��O�S���F�U�ӡI\n");
        else
        {
                this_object()->set("long", longs[0] + longs[1] );
                message_vision(HIY"$N��$n"HIY"��b" + name() + HIY"�A���L�@�|��A$n"HIY"���������F�A������G�ǨӤF�@�}�}������I�I\n"NOR, me, tar);
                destruct(tar);
        }
        write("�i�H�} !...:P\n");
        return 1;
}
