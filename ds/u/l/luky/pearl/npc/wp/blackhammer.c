#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("�������",({"dark hammer","hammer"}));
// �]"mike pen","pen","mike"�o��wield��wield pen or wield mike or wield mike pen�N�i�˳�
set_weight(40000);
if( clonep() )
    set_default_object(__FILE__);
  else {
set("long","\n
�@��I��������, �~���٥]�F�@�h�{�G���¦����\n");
set("unit", "��");
set("hammer",160);//skill 160���a�nskill 160�~��ϥ�by pudon
set("value",6300);
 }
 setup();
}
