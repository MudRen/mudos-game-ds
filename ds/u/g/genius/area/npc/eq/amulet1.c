#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIG"�������_���@����"NOR, ({ "tourmarlina amulet","amulet" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o�����屾�F�@�Ӻ��_�۪��Y�l�A�o�X�{�{�����~�A�Q����ģ���C\n");
                set("unit", "��");
                set("value",1);
                set("material","diamond");
        }
        set("armor_prop/int",3);
        set("armor_prop/armor",20);
        set("armor_prop/shield",10);
        setup();
}
