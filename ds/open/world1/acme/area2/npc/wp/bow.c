#include <weapon.h>
inherit BOW;
void create()
{
   set_name("��s��",({"put kop bow","bow"}));
   set("long","�o�O�@�����ʨB�ﴭ�������A�i��(shoot)�g�X�b�C\n");
   set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",230);
             set("value",1500);
                set("material","wood");
                set("limit_int",6);
		set("volume",3);
                set("limit_dex",6);
                set("limit_str",4);
     }
init_bow(30);
        setup();
}
