#include <weapon.h>
inherit BOW;
void create()
{
   set_name("���}",({"long bow","bow"}));
   set("long","�o�O�@���y�H�`�ϥΪ����}�A�Y���W���b�A�i��(shoot)�g�X�b�C\n");
   set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",200);
set("volume",2);
                set("material","wood");
}
               set("limit_int",6);
               set("limit_dex",6);
               set("limit_str",4);
       init_bow(10);
       setup();
}

