//updated by alickyuen 9/12
#include <armor.h> 
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIG"�A�ɯZ��"NOR, ({ "green ring","ring" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�u�ܺ}�q���٫�,\n"
                           "�A�i�H�յ۰t�a�ݬݡC\n");
                set("unit", "�u");
                set("material", "jade");
set("armor_prop/str",1);
                set("no_sac",1);
set("value",0);
		set("wear_msg",HIG"$N���W�F�o�u�A�ɯZ��, �y�ɷPı��@�ѫܤj���O�q�C"NOR);
        }
        setup();
}
