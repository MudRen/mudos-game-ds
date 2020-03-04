#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(HIG"�ª��y��"NOR ,({ "twist face", "face" }) );
        set("long",@long
�o�O�@�i �y�v(Acme) ���p�߿򸨦b�H�����y�СC
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit", "�i");
                set("value", 0);
        set("no_drop",1);
        }
        setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_twist", "twist");
}

int do_twist(string str)
{
    if( !str || str != "face" ) 
        return notify_fail("�A�Q�⤰���ܦ��ª�H\n");

    if( this_player()->query_condition("FaceIntCD") )
        return notify_fail("�A�{�b�٤��Q�ܦ��ª��y�C\n");

    message_vision(HIG"$N�ܦ��F�Ӥj�ª��y�C\n"NOR, this_player());

    this_player()->set_temp("FaceInt", 3);
    this_player()->add_temp("apply/int", 3);
    this_player()->apply_condition("FaceInt", 80);
    this_player()->apply_condition("FaceIntCD", 300);

    return 1;
}
