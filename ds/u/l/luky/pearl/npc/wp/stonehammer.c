#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("�ۺl",({"stone hammer","hammer"}));
set_weight(26500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","�ݨ�o��I���S���ꪺ�j�ۺl, �ϩ��ɥ��S�^��F�۾��ɥN�C\n");
            set("unit", "��");
            set("rigidity",97); //�w��
            set("material","stone"); //����
set("hammer",48);
set("weapon_prop/dex",-3);
set("weapon_prop/mus",5);
set("value",5250);
           }
init_hammer(769);
        setup();
}



