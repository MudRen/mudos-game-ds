#include <armor.h>
#include <ansi.h>
inherit CLOTH;
 
void create()
{
set_name(HIC"�Ц�"NOR,({"bird robe","robe"}) );
set("long","�o�O�@��ΦФ�s������A, ���M�D�`����, ���O���m�O�]���a�C\n");
set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("material", "cloth");
              set("unit", "��");
              set("material", "silk");
              set("armor_prop/armor", 10);
              set("limit_dex",10);
              set("armor_prop/dex", 1);
        }
        setup();
}
