#include <ansi.h> 
inherit ITEM; 
void create()
{
        set_name(HIY"���s��"NOR, ({"turn dragon-mirror", "mirror" }));
        if( clonep() )
                set_default_object(__FILE__);
        else { 
                set_weight(1000);
                set("long", "�@������s���Ϯת���l�A���ϥ��A�C�Ө��������@�ӥW�ѡC\n");
                set("unit", "��");
                set("material", "golden"); 
                set("no_sell",1); 
                set("no_drop",1);
        }
}

