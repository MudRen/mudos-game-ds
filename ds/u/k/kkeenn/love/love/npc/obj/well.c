inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("����", ({ "well" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "�@�f���A���L���������̶��ΡC\n");
                set("unit", "�f");
                set("value", 0);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",70);
                set("drink_msg","$N���F�@������̪����A�B�P�B�P~~�n�n�ܼڡC\n");
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
    if(me->query("level")>10)
        {
return notify_fail("�A�`�N�줫�ǤW�K�F�i�G�i: �����u���ѵ��ŤQ�ťH�U�����a
���ΡC\n");
        }
        else 
        {
                set("heal_ap",50+random(5));
                set("heal_mp",50+random(5));
                set("heal_hp",50+random(10));
                return ::do_drink(arg);
        }
}

