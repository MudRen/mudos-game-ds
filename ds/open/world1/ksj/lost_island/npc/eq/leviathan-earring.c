#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIC"��������"NOR ,({ "leviathan earring","earring" }) );
  set("long",@LONG
�`���_�ۻs�����@������A�q�j����  �Q���ȴ˪������Ҩ��o�A��
������Z�i�ӽo�A��u�륩�A�_���ť��y��A�e�{��������Ū���
�A�A�b���a�W�O�e�ҥ����A��������X�{�b�Q���ȴ˪��{���C
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("unit", "��");
    set("value",100000);
  }
  set("limit_lv",30);
  set("armor_prop/armor",1);
  set("armor_prop/con", 3);
  setup();
}

int query_autoload() { return 1; }

