#include <weapon.h>
inherit FORK;
void create()
{
set_name("�����W",({"dark spear","spear"}));
// �]"mike pen","pen","mike"�o��wield��wield pen or wield mike or wield mike pen�N�i�˳�
set_weight(28000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
�o�O�@�⨸�c���K�W, ���H�������л\�F�A������!\n");
set("unit", "��");
set("spear",75); //���F�o��..�N��skill 50�~��wield�B�]�]�w�F�Z���������O..�����O���w�Opudon����...�A�ۤvtry
set("value",4500);
}
 init_fork(30);
 setup();
}
