#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIB"�k�۫l��"NOR ,({ "meteoric-stone armor","armor" }) );
        set("long",@LONG
        
ť���O�ӥj�ɴ�,�ѥ~���Ӥ@�Ӥj���Y,�ּY�ܦa�a�����ɭ�,�E��
�ϥX�Q���\�O�⥦�פF�U��,�]�I�t�������O�q,�Q�E�׻s���@��
����,�Q����T        
LONG
);
        set_weight(10000);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("unit", "��");
                set("limit_con",8);
        }
        set("value",7000);
        set("volume",6);
        set("no_sac",1);
        set("armor_prop/armor",45);
        set("armor_prop/shield",10);
        set("armor_prop/dodge",-6);
        set("armor_prop/dex",-2);
        set("armor_prop/con",2);
        setup();
}


