#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���s����", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "�@�Ӥj����, �̭��˪��O�s�u����....@_@, ���L�����̰{�{�o�G..? �]�\\�A���ӷj��(search)�@�U�C\n");
                set("unit", "��");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
                set("drink_msg","$N�s�U�y�ܤF�X�f$n�̪��s�u���C\n");

        }
        
        setup();
}

void init()
{
        add_action("do_drink", "drink");
      add_action("do_search", "search");
      add_action("do_take", "take");
}

int do_drink(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
    if(me->query("level")>5)
        {
return notify_fail("�A�`�N������W�K�F�i�G�i: ���Τ��u���ѵ��Ť��ťH�U�����a
���ΡC\n");
        }
        else 
        {
                set("heal_ap",40+random(10));
                set("heal_mp",40+random(10));
                set("heal_hp",40+random(10));
                return ::do_drink(arg);
        }
}

int do_search(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("�A�n�j������?\n");
        if( a!="pot" && a!="���s����" )
                return notify_fail("�A�����M�F��? �o�̨S���o�تF��!\n");
      tell_object(me, HIY"�A�o�{�������G���@�����Ӫ��A�A�i�H�⥦��(take)�X��!\n"NOR);
          me->move(where1);
        return 1;
}


void clear() {
        set("long", "�@�Ӥj����, �̭��˪��O�s�u����....@_@, ���L�����̰{�{�o�G..? �]�\\�A���ӷj��(search)�@�U�C\n");
        delete_temp("get_plant");
}

int do_take(string arg)
{
        object me,golden;
        me = this_player();
        golden = new(__DIR__"gold_plant.c");
        if( random(70) > 55 && !query_temp("get_plant") )
        {
                message_vision("$N�Τ@���j��b�����̶ñǡA��X�F�@����⪺�Ӫ��I\n",me);
                golden->move(me);
                set_temp("get_plant",1);
                set("long",@LONG
�@�Ӥj����, �̭��˪��O�s�u����....@_@
LONG
                );
                call_out("clear",600+random(300) );
        } else {
                message_vision("$N�Τ@���j��b�����̶ñǡA���O���F�Q���~�|����Y�H�~�A�S���O����ì�I\n",me);
        }
        return 1;
}


