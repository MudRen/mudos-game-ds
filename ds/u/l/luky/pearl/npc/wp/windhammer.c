#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("[1;36m������[0m",({"wind hammer","hammer"}));
set_weight(40000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n
�o����Y���g�Q�����I�k�b�W��,���M�ܭ�,���ϥΰ_�ӫo�۷�K�Q\n");  
            set("unit", "��");
            set("rigidity",85); //�w��
            set("material","steel"); //����
set("hammer",50);
set("weapon_prop/dex",3);
set("value",4750);
           }
init_hammer(800);
        setup();
}



