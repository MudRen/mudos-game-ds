//u/c/chiaa/obj/eq/conch_helmet.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
  set_name(WHT"����"HIG"��"HIC"�U"NOR ,({ "conch helmet","helmet" }));
  set("long", "�o�O�ή��������ͪ��[�u�Ӧ����Y��,�i�H�ݨ즳�����۪�������\n");
    set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("material", "conch");  //���� ����
                set("limit_con",12);  //����ڰ����15
                set("armor_prop/armor",  10);  //���m�O+10
                set("armor_prop/shield", 1);   //���+1
                set("value", 2000); //����
        }
 set("weapon_prop/dodge",5);        //�[ enable �ޯ�5

        setup();
}
