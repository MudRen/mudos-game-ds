#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"�t���ĤY"NOR, ({ "X'mas pill","pill" }));
        set("long",@long
�@���ݨӤQ�����ժ��ĤY�A���b��������a���x�N�C
long
        );
        set("weight", 200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "��");
        set("value", 1);
        set("heal_hp",1000);      
        set("heal_mp",1000);
        set("heal_ap",1000);
        set("eat_msg",HIW "$N�Y�U�@�����ժ��ĤY�A�L�̻����a�o�X�@�n�u�B�v�C" NOR );
        }
 setup();
}

