#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name(HIG "�A��j"NOR,({"gin yi pike","pike"}));
    set("long","�o��j�O�§ʸ̴M�`�T�x�ҨϥΪ����j�A������ҷҡA�¤O�L�a�C\n");
     set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
       set("value",2250);
set("volume",4);
          set("material","iron");
        }
        set("limit_str",12);
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        init_fork(36);
        setup();
}
