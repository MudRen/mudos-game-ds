#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(CYN"���ô�a"NOR ,({ "maper waist","waist" }) );
        set("long","�@���Τd�U���s�ޤ�һs����,�X�n�B����,���ʵ��ΡC\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "skin");
        set("unit", "��" );
       set("value",1000);
        set_temp("apply/armor", 10);
        set("armor_prop/con",4);
        set("armor_prop/str",-1);
        set("armor_prop/int",-2); 
        set_temp("apply/hit",20);
        }
        setup();
}


