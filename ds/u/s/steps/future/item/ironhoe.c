#include <weapon.h>
inherit STAFF;
void create()
{
          set_name("�K�S",({"iron hoe","hoe"}));
          set("long","�@�ⴶ�q���K�S�A�i�H�Ψӫ����M½�P�d�g�C\n");
          set_weight(5000);
          if (clonep() )
          set_default_object(__FILE__);
          else {
          set("unit","��");
          set("value",100);
          set("material","iron");
          init_staff(10);
          } 
          setup();
}
