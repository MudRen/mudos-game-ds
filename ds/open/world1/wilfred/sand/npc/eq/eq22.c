#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit ARMOR;
void create()
{
  set_name(HIW"����֥�"NOR ,({ "dragon armor","armor" }) );
  set("long",@LONG
�o�O�@��x�ۻȦ���~���s���Z�ҡA���b��W�����A�o�Ƭ����C
�۶ǫe�j�ɥN�Ѧa�D�T�A�s�s�L���A�C���s�H�j���z�ƸѦ��T�A��
�a��s�s��(�{)�Y�s�s���~�A�Ʀʦ~�ۦw�L�ơC�C���s�����b�Y�s
�s�q�l������ءA��⺥���ର�ȥզ�A�G�٨䬰�C�����s�A��
�֥ҥ������o�X�L�z�����~�A�ŷx�B���G�C
LONG
);
  set_weight(2500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",20000);
    set("replica_ob",__DIR__"eq24");
  }
  set("limit_level",25);
  set("armor_prop/armor",44);
  set("armor_prop/con",3);
  set("armor_prop/dex",-2);
   set("armor_prop/bar",1);
  set("armor_prop/wit",-1);
  set("armor_prop/dodge",-15);
  set("beast_armor_type","armor");
  set("beast_armor_prop/armor",64);
  set("beast_armor_prop/shield",30);
  set("beast_armor_prop/con",13);
  set("beast_armor_prop/dex",20);
  set("beast_armor_prop/bar",1);
  set("beast_armor_prop/dodge",25);
  setup();
  this_object()->start_light(1);
}
