#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name(HIW"�ժ��m"NOR,({ "white linen","linen" }) );
        set("long","�Ψȳ¥[�u�V�⪺���m�A�i�H����L���ˮ`�C\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","cotton");
        set("unit", "��" );
        set("value",1000);
        set("armor_prop/armor", 3); 
        set("armor_prop/con", 1); 
        } 
        setup();
}