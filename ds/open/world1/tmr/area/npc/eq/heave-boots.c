#include <armor.h>

inherit BOOTS;void create()
{
        set_name("���u",({"heavy boots","boots"}) );
        set("long","�o�O�@���p�����u�l�A�Q�����O�x�C");
        set_weight(4000);
  if ( clonep() )
    set_default_object(__FILE__);
        else
        {
                set("volume",1);
                set("unit","��");
                set("value",3000);
                set("armor_prop/armor",12);
        }
        setup();
}

