#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("���]",({"steel ball","ball"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "��");
                set("base_volume",1);
                set("base_weight",300);
        set("long",@LONG
�@���b���q�f�C�����H�B�i�����p���]�A�O�Ѽo�K���Ʃһs�����C
LONG);
        }
        init_throwing(14);
        setup();
        set("value",100);
        set("volume", 1);
        set_amount(1);
}
