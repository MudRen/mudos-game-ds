#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
  set_name( HIW "�T�d"HIM"�дo��" NOR , ({ "thousand-hair whip","whip", "THOUSAND_HAIR_WHIP"}) );
    set("long", "   ���ҬҪ��A�����@�k���������������ޡA��ۦ�����
�¤O�w�W�B�Z�L�A�]�����󱡫������̤l�A�u�n��߭׽m�A
����b�Z�L���F��@�w���a��C
    �M�ӡA���F��Z�L���@�y���⪺�ҬɡA�h�ߦ��a�i�@�B
����ѭ������v�ҳХߪ��u�T�d�дo���v�~���i��F��C�u
�T�d�дo���v�����������̤l�A�b���F�C�~���ɶ����W�d��
�v�A�H�S�����\\�ߪk���Ĥ�ﵽ�v��A���̫ܳ�d�ܤC��
�Ӥj�\\�i���ɡA�ŤU���v�òV�i����@�����@�A�����C�@��
�������̤l�S�����W���Z���C
\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "iron");
    set("value",0);
    set("no_sell",1);
    set("wield_msg", CYN "��$N�N$n"CYN"���b�⤤�ɡA�����z�S�X�@�ѬݲH�ͦ��B�ѫo�@�����W��ı���C\n"NOR);
  }
  init_whip(5);
  set("weapon_prop/armor",1);
  setup();
}


