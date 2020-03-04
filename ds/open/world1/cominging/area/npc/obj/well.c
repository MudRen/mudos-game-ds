inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("����",({"well"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�O�@�ӨѤH�����Ϊ������A�������`�צn���ܲ`���ˤl�C\n");
                set("unit","�y");
                set("no_get",1);
                set("no_sac",1);
                set("value",1);
                set("heal_mp",random(10));
                set("heal_ap",1+random(10));
                set("water_remaining",250);
        }
        set("drink_msg","$N�q�����̧ˤF�X�f���ܡC\n");
    set("finish_drink_msg","$N������̾l�U�����ܥ��F�C\n");
        setup();
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
                return notify_fail("�A�`�N������W�K�F�i�G�i: ���Τ��u���ѵ��Ť��ťH�U�����a���ΡC\n");
        else return ::do_drink(arg);
}

