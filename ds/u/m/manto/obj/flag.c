
#include <ansi.h>
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIR"�p����X"NOR, ({"national flag","flag"}));
        if( clonep() )
        set_default_object(__FILE__);
        else {
set("long", HIY"�W���s����R���g�ۡG"HIC"�x�W�[�o�I�I�I�I�I\n\n"HIW"��� ����� ����� �������I�I�I"NOR);
        set("unit", "�u");
        set("base_unit", "�u");
        set("value", 10);
        }
        setup();
}
void init()
{
        object ob;

        if( this_player() && environment()==this_player() ) {
                add_action("do_wave", "wave");
        }
}

int do_wave(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" || arg!="flag")
                return notify_fail("�A�n���Rԣ�H\n");

        message_vision(HIW"$N"HIW"�g���a���R�ۤ�W��$n"HIW"�I�I\n"NOR,this_player(),this_object());
        return 1;
}
