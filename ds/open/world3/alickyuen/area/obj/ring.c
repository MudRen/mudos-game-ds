#include <armor.h> 
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIG"�A�ɯZ��"NOR, ({ "green ring","ring" }) );
        set("long","�@�u�ܺ}�G���٫��A�A�i�H�յ۰t���ݬݡC\n");
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "�u");
        set("material", "jade");
        set("armor_prop/str",1);
        set("wear_msg",HIG"$N���W�F�o�u�A�ɯZ��, �y�ɷPı��@�ѫܤj���O�q�C"NOR);
        }
        setup();
}

