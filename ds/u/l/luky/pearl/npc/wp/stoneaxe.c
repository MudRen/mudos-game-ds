#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
set_name("�۩�",({"stone axe","axe"}));
set_weight(56500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","�ݰ_�ӥu���j�O�h�ധ�R�o��I���S���ꪺ�j�۩�C\n");
            set("unit", "��");
            set("rigidity",96); //�w��
            set("material","stone"); //����
set("axe",78);
set("weapon_prop/dex",-1);
set("weapon_prop/mus",3);
set("value",6850);
           }
        setup();
}



