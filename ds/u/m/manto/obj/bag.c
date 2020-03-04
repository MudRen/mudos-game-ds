#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�]�l�U"NOR, ({ "dumping bag","bag" }) );
        set_weight(600);
        set_max_capacity(500);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�f");
                set("long", "�o�O�@�f�j�U�l�A���լ۶��A���G���_�����]�O�C\n");
                set("value",10000);
               }
        setup();
}
void init()
{
      add_action("catchmob", "catch");
      add_action("freemob", "free");
}
int catchmob(string arg)
{
    object me, ob;
    string myid, myname, mobname;
    me = this_player();

    if( !arg ) return notify_fail("�A�n�줰��F��S\n");
    if( !objectp(ob = present(arg, environment(me))) )
        return notify_fail("�o�̨S���o�˪F��C\n");
    if( stringp(me->query( "have_one" )))
        return notify_fail("�A�u������@���C\n");
    if(userp(ob) || !living(ob))
        return notify_fail("�ϥι�H�O���X�k���C\n");
    if(!ob->is_character() || ob->is_corpse())
        return notify_fail("�A�ݲM���@�I�A���ä��O�����C\n");

    myid    = capitalize(me->query("id"));
    myname  = me->query("name");
    mobname = ob->query("name");

    me->set("have_one", base_name( ob ));
    me->set("mob_name", mobname);
    message_vision("$N�������a��$n�A�M���"HIW"����"HIR"�U"NOR"��$n�Y�W�@�M�C\n"NOR
                HIB"\n$N"HIB"��$n"HIB"���\\���U�F�I\n"NOR, me, ob);;
    destruct(ob);
    return 1;
}
int freemob()
{
    object me, ob, charger;
    string charger_base;
    me = this_player();
    charger_base = me->query("have_one");
    if( !charger_base )
    return notify_fail("�A�������U�̨èS������F��i�H���A��X�Ӫ��E\n");

    me->delete("short");
    me->delete("mobname");
    me->delete("have_one");

    charger = new( charger_base );
    charger->move( environment( me ) ); 
    charger->set("creater",me);
message_vision
("$N��"HIW"����"HIR"�U"NOR"�@�ϡA$n�q"HIW"����"HIR"�U"NOR"�̱��F�X�ӡE\n"NOR, me, charger);
    return 1;
}

