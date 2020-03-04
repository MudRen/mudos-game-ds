#include <ansi.h>
inherit F_AUTOLOAD;
inherit ITEM;

void create()
{
        set_name(HIY"�n����"NOR, ({"money fan","fan","money"}));
        set("long",
                "�Ϊk: wave <�ƶq> <�f������>\n");
        set("unit", "��");
        set("weight", 100);
        setup();
}

void init()
{
        if( this_player()==environment() ) 
        add_action("do_wave","wave");
}
int do_wave(string arg)
{
        string from;
        float amount;
        object from_ob, me, ob;

        me = this_player();
        ob = this_object();
        if( !arg || sscanf(arg, "%d %s", amount, from)!=2 )
                return notify_fail("���O�榡�Rwave <�ƶq> <�f������>\n");
        if( file_size("/obj/money/" + from + ".c") < 0)
             return notify_fail("�A�Q�ܥX���ؿ�? \n");
        if( amount < 1 ) amount = 1;
        from_ob = new("obj/money/"+from);
        from_ob->set_amount(amount);
        from_ob->move(me);
        tell_room(environment(me),me->query("name")+"�ΤO���n��"+ob->query("name")+"���G�q"+ob->query("name")+"���X�F"+chinese_number(amount)+from_ob->query("base_unit")+from_ob->query("name")+"\n",me);
        tell_object(me,"�A�ΤO���n��"+ob->query("name")+"���G�q"+ob->query("name")+"���X�F"+chinese_number(amount)+from_ob->query("base_unit")+from_ob->query("name")+"\n");
        return 1;
}


