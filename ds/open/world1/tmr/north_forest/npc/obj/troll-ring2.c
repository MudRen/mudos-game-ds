#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name( "�˪�����" ,({"troll ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long",@LONG
�˪��O�t�٥��]�@�ڤ������v�^���A�b���G�ʦ~�e�A�˪��v��
�t�ٳ����b�j�x�����񪺮q���w�~�A���M���ɥ��S�����h�[�C��
�ۮw�����Դ����H���b������A���_�I�ǡC�����ԤQ�X�~�A�ѩ�
���˪�����ɡA�̫�ש󥴱ѤF�H���A�]�@�ϤF�t�ٳ����C�˪���
�٤]�N�q�b���ɳQű�y�X�ӡA�ΨӺq�|�˪����^�m�C
LONG
);
    set("value",10000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","�u");
  } 
  set("armor_prop/dex", 1);
  set("armor_prop/con", 1);
  set("armor_prop/armor", 5);
  setup();
}

