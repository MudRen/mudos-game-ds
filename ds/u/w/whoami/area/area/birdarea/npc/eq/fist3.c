#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
    set_name("�E����",({"nine-fox claw","claw"}) );
    set("long","�E�������l�A���ˤO�D�`�j�A�ǻ��u�n�t�W�o�����l�A
�s���|�Z�\\�����`�H�]�i�H�ܦ��^���C\n");
        set_weight(7000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value",20000); 
        set("material","gold"); 
        }
        set("weapon_prop/dex", 4);
        set("weapon_prop/str", 3);
        init_fist(60);
        setup();
}

