#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("Arai�t��",({"arai armor","armor"}) );
        set("long",@LONG
�o�O�@��饻�i�f��Arai�t�ߡA���i�H�O�@�ϥΪ̪���դ�����~�O
���ˮ`�A�H�T�O�w���C
LONG
);
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "��");
                set("limit_level",30);
        }
        set("armor_prop/armor",25);
        setup();
        set("value",24500);
        set("volume", 30);
}
int query_autoload() { return 1; }
