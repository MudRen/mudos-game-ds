#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("�C�˴�",({"verdant-bamboo-rod","rod"}) );
        set("long","�@�����C�ⴳ�I���˴ҡA�O��~��p�ҨϥΪ��Z���C\n");
      set_weight(2000);
                    set("material", "steel");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�K");
                set("volume",2);
    set("value",1800);
        }
                set("wield_msg","$N���_�F�@�K$n�y�ɥ��ز��S�C\n");
init_whip(8);
        setup();
}

