inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("������", ({ "tea pot","pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "�@�x�������A�\�b����A���L�����H���ΡC\n");
                set("unit", "�x");
                set("value", 20);
                set("heal_ap",45+random(6));
                set("heal_mp",45+random(6));
                set("heal_hp",45+random(6));
                set("water_remaining",50);
        }
}
void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("level")>5)
        {
return notify_fail("�A�`�N�춼�����W�K�F�i�G�i: ���Τ��u���ѵ��ŧC�󤭯Ū����a���ΡC\n");
        }
        else return ::do_drink(arg);
}
