#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR"�C�C����"NOR,({"seven staff","staff","_SEVEN_STAFF_"}));
set("long",
  "�@��O���D�D����ܪ��]���A�������Q�εL�d���Ĵ��ҦӦ��A�o�����͡C\n"
"�ͤ��o��ͧ�L�A�ݵۧ��Wį�ʪ���{���Y�A�A���T�����ߴH�C\n"
);
        set_weight(12000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("value",3000);
		set("volume",4);
          set("limit_str",30);
        }
        set("weapon_prop/int",2);
init_staff(40);
        setup();
} 

