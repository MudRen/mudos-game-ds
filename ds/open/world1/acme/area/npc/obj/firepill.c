
#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "��������" NOR, ({ "fire-red pill","pill"}));
        set("long",@LONG
�o�O�@�������⪺���ġA���_�o�X�K�������šC
LONG
        );
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�Y�U�@�����������C\n");
                set("eff_msg", HIR "�A�P��q�����E�o�@�Ѩ��y�A�X��������C\n" NOR );
        }
        set("value",2000);
        set("heal",([
         "ap" : 500,
         "mp" : 500,
         "hp" : 2500,
         ]));
        setup();
}

