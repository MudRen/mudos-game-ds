#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�ܢӢ�´֤W��",({"net clothes","clothes"}) );
	set("long",@LONG
�o�O�@��W�P�W��A�ɤU�~���H���̷R�C
LONG);
	set_weight(1470);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",8);
        setup();
        set("value",1210);
        set("volume", 4);
}
int query_autoload() { return 1; }
