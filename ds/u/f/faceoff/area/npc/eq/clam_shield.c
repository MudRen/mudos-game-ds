#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(YEL"���F��"NOR ,({ "clam shield","shield" }) );
        set("long","�o�O�@�ӨB�����Υ��F�ߥ[�W�K���X�Ӫ��j��, �ݰ_�Ӭ۷����C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(2000);
        set("material", "iron");
        set("unit", "��" );
      set("value",5400);
        set("armor_prop/armor", 20);
        set("limit_str",15);
        set("armor_prop/con",1);
        }
        setup();
}