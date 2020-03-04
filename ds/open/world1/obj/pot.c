inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�j����", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "�@�Ӥj�����A�m��b�a�W�A���L�����H���ΡC\n");
                set("unit", "��");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
                set("drink_msg","$N�s�U�y�ܤF�X�f$n�̪������C\n");
        }
        
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

        set("heal_ap",40+random(10));
        set("heal_mp",40+random(10));
        set("heal_hp",40+random(10));
        return ::do_drink(arg);
}


