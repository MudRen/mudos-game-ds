#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("���b���C", ({ "schiavona sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "��}�����b���C�A�֦��������M�b�M�Q���P�����@��O�@�A�i�P
  �ɶi������ά����������A���M�L�۷�R�ΡC\n");
                set("value", 2500);
        }
        init_sword(48);
        setup();
}

