
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( "�K�S"  ,({"iron hoe","hoe", "_IRON_HOE_"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long",@LONG
�o�O�@��A�a�`�����K�S�A�̱`�Ψӫ��g�C
LONG
);
               set("volume",6);
               set("value",100);
               set("material", "iron");
        }
      init_staff(15);
      setup();
}

