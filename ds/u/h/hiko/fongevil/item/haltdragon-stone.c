#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("�b�s��", ({ "halfdragon stone", "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "�@���J���s�����J�A�i�O�u���@�b\n");
                set("unit", "��");
                set("value",0);                
        }
        setup();
}







