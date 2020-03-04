#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIG"��������"NOR ,({ "pan flute", "flute" }) );
        set("long",@long
�����Q��v�b���ΤH����줧�~�A͢�S�÷K�a�b���ΤH����t�A�a���~
���g���B����B�����B�x�઺���ġA�ݮ��ۡA�չϫI�����p���ΤH����
��C�ӳo�O�@�ڪ������H����a���u�áA�����D�j��(blowout)���|�o��
����ơC
long
);
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit", "��");
                set("value", 0);
        }
        setup();
}

// int query_autoload() { return 1; }

void init()
{
    add_action("do_blowout", "blowout");
}

int do_blowout(string str)
{
    string arg, carg;

    if( this_player()->query_condition("PanFluteCD") )
        return notify_fail("�A�w�g�֦����������O�F�C\n");

    if( !arg || sscanf(str, "flute %s", arg) != 1) 
        return notify_fail("�A�Q�n�j������H\n");
        switch(arg) {
                case "bar": carg = "�~��";break;
                case "bio": carg = "�ͪ�";break;
                case "sou": carg = "���F";break;
                case "tec": carg = "���";break;
                case "wit": carg = "�]�k";break;
                default:
                        return notify_fail("�A�u���� bar, bio, wit, sou, �� tec �@�ئ��աC\n");
        }
    
    message_vision(
        HIG"$N�j���_�@�ڵu�áA�ǥX���H�߬���" + HIW "" + carg + HIG"���X�۫ߡA���K�F�Ҧ����H�ƪ��C\n"NOR, this_player() );
    message_vision(
        HIY "$N���W�o�X��󪺦Ϫ��̨��A���G���د��t���O�q�C\n"NOR, this_player() );
        
        
    this_player()->set_temp("PanFlute", arg);
    this_player()->add_temp("apply/" + arg, 1);
    this_player()->apply_condition("PanFlute", 120);
    this_player()->apply_condition("PanFluteCD", 600);

    return 1;
}

