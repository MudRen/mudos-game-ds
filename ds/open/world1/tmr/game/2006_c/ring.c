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
        }
         set("armor_prop/int",3 );
         set("armor_prop/str",3);
         set("armor_prop/dex",3 );
         set("armor_prop/con",3 );
         set("armor_prop/armor",20);

        setup();
}

