#include <ansi.h> 
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIG"�ý���"NOR, ({ "ivy whip" , "whip" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "��");
                set("long", "�o�O�@��D�h�M���I�k�Ϊ��C�C\n");
                set("value", 500);
        }
        init_whip(30);
        setup();
}

