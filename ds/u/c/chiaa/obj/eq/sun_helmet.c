//u/c/chiaa/obj/eq/sun_helmet.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
  set_name(HIY"����"WHT"�Y"HIB"��"NOR ,({ "sun helmet","helmet" }));
  set("long", "�o�O�ζ����P�ѵM���q�ۥ[�u�Ӧ����Y��,���o�Xģ�������~,
     �N�n������F�@�@��.\n");
    set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��" );
              set("material", "gold ore");  //���� �� �q��            
              set("armor_prop/armor", 30);  //���m�O+30
              set("armor_prop/shield", 5);  //���+5
              set("value", 2000); //����
              set("wear_msg","$N�N$n�w�w���b�Y�W,�������o�Xģ�������~!!\n");
              set("unequip_msg","$N�N$n���U,���~�H�Y���h�C\n");
        }
              set("weapon_prop/force",15);        //�[ enable �ޯ�15
 
        setup();
}
