#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIC"�]��"NOR, ({ "Dreamcast ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�o�T�٤l�O�j�]�����ۥΤ��s�ߧ@�����A�����̳o�T�٤l����Q���ۮ��^...\n");
                set("unit", "�u");
        set("value",10000);
        set_weight(600);
              set("material","jade");
                set("armor_prop/armor", 10);
         set("armor_prop/str",1);
         set("armor_prop/con",2);
         set("armor_prop/bar",1);
        }
        setup();
}


