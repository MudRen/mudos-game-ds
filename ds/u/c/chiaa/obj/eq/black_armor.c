//u/c/chiaa/obj/eq/black_armor.c
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
                        
void create()
{
     set_name(BLU"����"CYN"�ԥ�"NOR,({"black armor","armor"}) );
     set("long","�H�öQ�������V�X�������y�Ӧ�������,���q���@�벯�ҨӪ����C\n");
 
   if( clonep() )
            set_default_object(__FILE__);
        else {
       
        set_weight(10000);
        set("unit", "�M");
        set("value",5000);
        set("material","steel silk");  //���� �� ����
        set("armor_prop/armor",50 );  //�W�[���m�O50
        }
        setup();
}
