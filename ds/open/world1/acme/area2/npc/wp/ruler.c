#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("�K��",({"iron ruler","ruler"}));
set("long","�o�O�@��I�������ءA���G�O�ΤW�n�����K�ҥ��y�Ӧ����C\n");
set_weight(4000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("limit_int",10);
set("unit", "��");
set("value",500);
set("material","iron");
        }
init_dagger(30);
        setup();
}
