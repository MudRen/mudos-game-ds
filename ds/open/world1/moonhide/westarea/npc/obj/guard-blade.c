#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�v��̤��M",({"sun-follow blade","blade"}) );
        set("long","�v��̤��M�O��ȥզ⪺�j�M�A���`�B�O�������@�˪������W����C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",2000);
        set("volume",5);
        set("material","iron");
        init_blade(42);
        }
        setup();
}


