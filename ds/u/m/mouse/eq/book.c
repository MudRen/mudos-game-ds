#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
    set_name(HIW+BLK"�]��"NOR+YEL"�_Ų"NOR, ({ "night moon book", "book", "moon", "night" }));
    set("long", "���o�۲H�����������_�_��A���L���X�B�o���]�����}�A�ݨӥu\n"
                "���S�w���D�H�~��ϥγo�Ӫ��~�C\n");

    set_weight(1200);
    if( clonep() ) set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 0);
    }
    set("limit_lv", 80);
    set("armor_prop/armor", 200);
    set("armor_prop/shield", 200);
    set("armor_prop/dodge", 10);
    set("armor_prop/str", 10);
    set("armor_prop/con", 10);
    set("armor_prop/int", 10);
    set("armor_prop/dex", 10);
    call_out("heal_book", 10);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_open", "openbook");
    add_action("do_close", "closebook");
}
void heal_book()
{
    object me = environment(this_object());

    if( !this_object() || !me ) return;
    if( !me->is_fighting() ) {
        call_out("heal_book", 60);
        return;
    }
    if( me->query_temp("openbook") == 1 && me->query_temp("armor/shield") == this_object() ) {
        switch( random(2) ) {
            case 0: me->receive_heal("hp", me->query("max_hp"));
                    me->receive_heal("ap", me->query("max_ap"));
                    me->receive_heal("mp", me->query("max_mp"));
                    message_vision("\n$N"HIY"�{ģ�۲��䪺����A�v���F$n"HIY"���W���ˤf�C\n\n"NOR, this_object(), me);
                    break;
            case 1: me->receive_curing("head", 1);
                    me->receive_curing("body", 1);
                    me->receive_curing("left_arm", 1);
                    me->receive_curing("left_leg", 1);
                    me->receive_curing("right_arm", 1);
                    me->receive_curing("right_leg", 1);
                    message_vision("\n$N"HIR"�Ϯg�F�Ӷ����L�z�G���A�v��$n"HIR"�Ҩ������ˡC\n\n"NOR, this_object(), me);
                    break;
            default: message_vision("$N�y�L�{�{�F�@�U�A���O�S�o�ͥ���ơC\n"NOR, this_object(), me);
                    break;
        }
    }
    call_out("heal_book", 30);
}
int do_open(string arg)
{
    object me = this_player();

    if( me->query_temp("openbook") == 1 ) return notify_fail("�A�w�g�N�_�奴�}�F�C\n");

    if( wizardp(me) && me->query_temp("armor/shield") == this_object() ) {
        message_vision(HIM"\n$n�N�]�O�t�X���l�b$N"HIM"�W���X�@�D�Ť�A�u���Ť������$N"HIM"�_�ʤF�_��...\n"NOR, this_object(), me);
        message_vision(HIW"$N"HIW"�o�X�j�P���{�����ĤѻڡA�쥻�ѤW���ʦL�~�M�N���Ѷ}�A�ҧt����q������J$n�餺�C\n\n"NOR, this_object(), me);
        me->set_temp("openbook", 1);
    } else {
        message_vision("$n�ϺɦY�����O��Q���}$N�A���O$N�̵M�@�L�ҰʡC\n"NOR, this_object(), me);
        if( wizardp(me) ) tell_object(me, "�A�������˳ƫ�~��ϥΥ\\��C\n");
    }
    return 1;
}
int do_close(string arg)
{
    object me = this_player();

    if( me->query_temp("openbook") != 1 ) return notify_fail("�_��ڥ��N�S�����}�A�O�n������F��C\n");

    message_vision(HIM"$n�C�n����F�@�ǩG��A$N"HIM"�S�v���X�F�_�ӡC\n"NOR, this_object(), me);
    me->delete_temp("openbook");
    return 1;
}
