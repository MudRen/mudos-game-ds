// �]�p�ΨӦsticket �o�ح��q���A���ݭn�j�q�x�s������C
#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("�w���֯ȧX", ({ "paper box","box" }) );
        set_weight(600);
        set_max_capacity(5000);
        set_max_encumbrance(5000);      // ���]�@�i�ȥu���@�J
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", @LONG
�o�O�@�Ӥ��ֻs���ȧX�A�̭��O��5000�Ӫ��ӧ��h�A
�D�`��K�ΨӦ����ȱi�β���C
�A�i�H�ϥ�size�Ӭd�ݥثe�w�g�񦳦h�ּ˪��~�C
LONG
);
                set("value", 15000);
               }
        setup();
}

void init()
{
    add_action("do_size","size");
}

int do_size()
{
    return notify_fail( sprintf("�ثe%s����%3d�˪��~�C\n", name(), sizeof(all_inventory(this_object() ))
                               ));
}

