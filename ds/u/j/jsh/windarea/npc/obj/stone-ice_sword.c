#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name(HIC"�k�ѡE�B�}"NOR, ({ "stone-ice sword" , "sword" }) );
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",3); 
                set("value",8000);
                set("unit", "��"); 
                set("long", "�Ķ��ѥ~���۩�ű�y�����C�A���O����O�ųz�����A������`�h�O\n"
                            "�ΦB���һs�A�B���ĤơA���O�Z�ˤ⪺�C\n"); 
        } 
        set("weapon_prop/con",1);
        set("weapon_prop/dex",2);
        set("weapon_prop/str",-1);
        set("weapon_prop/int",-2);
        set("weapon_prop/bar",-1);
        set("weapon_prop/tec",1);
        init_sword(50+random(3));
        setup();
}


