#include <ansi2.h>
#include <armor.h>
inherit PANTS;

void create()
{
   set_name(BBLU HIB"�`�Ŧ�"HIY"�u��"NOR,({ "mazarine knee breeches", "breeches" }) );
  set("long",@LONG
    �g�夭���u�Ǫ����A����f�U�ŵ��A��y�X��ı�j�ۮ𮧡C�y����ƺ��I
�A���Y�ʷP��q�i�{�C�����f�U����ʨΡA�]�p�W��ΡA����H���i�H��X��
�ڭ���I
�o��˳Ƭ�roba�b2008�~�u�����_�v���ʤ���o�����~�C
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "��");
    set("value", 100);
        set("wear_msg", HIC"��W�o��Ǥl�ɡA$N�Pı��ۤv�������Y�`�ت��J�I�C"NOR);
        set("unequip_msg", WHT "��$N��U�Ǥl���P�ɡA�g�D�H���W�W�λ����������V$N�����I�I�C\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/con",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}


int query_autoload() { return 1; }

