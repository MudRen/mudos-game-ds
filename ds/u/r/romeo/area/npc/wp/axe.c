#include <weapon.h>

inherit AXE;

void create()
{
        set_name("�S�R����",({"ghost-axe","axe"}) );
        set("long","�Ѧ��D�椧�h�A�b�������a�����C�C���ƪ����y�S�R�A�ʤJ���򤺦Ӧ��C\n");
          set_weight(1700);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                    set("material", "rock");
      set("value",900);
        }
          init_axe(8);
        setup();
}
