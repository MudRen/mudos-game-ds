#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"�t��"HIW"�w�֧٫�"NOR, ({ "christmas ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
  set("long",@LONG
�o�O�@�u���������~�t�Ϭ��ʪ��w�֧٫��A�٫��W�O�ۤ@��ģ�������_�ۡC
LONG
);
                set("unit", "�u");
        set("value",1);
        set_weight(1);
        set("material","gold");
         set("armor_prop/int",1 + random(3) );
         set("armor_prop/str",1 + random(3) );
         set("armor_prop/dex",1 + random(3) );
         set("armor_prop/con",1 + random(3) );
         set("armor_prop/armor", 5 + random(20) );
        }
        setup();
}

