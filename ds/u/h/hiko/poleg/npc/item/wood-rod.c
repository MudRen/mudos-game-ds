#include <weapon.h>

inherit WHIP;

void create()
{
    set_name("����",({ "wood rod","rod" }) );
        set("long","�@�K�Ѱ��һs�������M�`����@�ΡC\n");
      set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�K");
                set("volume",2);
                set("value",1500);
        }
                set("wield_msg","$N���_�F�@�K$n�R��Z���C\n");
init_whip(16);
        setup();        
}       


