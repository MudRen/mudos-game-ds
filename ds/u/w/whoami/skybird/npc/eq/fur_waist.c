#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name("�~�֤y�a",({"fur waist","waist"}) );
        set("long","�@�����~�ֻs�����ֱa�C\n");
      set_weight(200);
        set("unit","��");
        if (clonep() )
                set_default_object(__FILE__);
        else {
	set("value",300);
                set("unit","��");        
                set("material","fur");
                set("armor_prop/armor",2);
        }
        setup();
}
