#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
   set_name(HIW"�ѨϤ��l"NOR,({ "angel wing", "wing" }) );
  set("long",@LONG
    �o�O�@�ӳy���_�S����M�A��������������M�W�Y�������~��A
�����F���������Z�A�b�����W�Ƶ۲H�H���ȥզ���~�A���ۧϩ���
�g�z�@���·t�����ءA���X�M�����~�b��M�����H�H�����o�ۡA�n
���H�ɳ��i�ຶ���A���L�׬O�b�h�K�P���Ӷ����U�@���٬O�i�H�M��
���ݨ쥦�������A���L�O�H�_�Ǫ��O�A������o��M�u�����⪺����
�A�ӨS���k�⪺�����C
�o��˳Ƭ�deaon�b2008�~�u�����_�v���ʤ���o�����~�C
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
        set("wear_msg",
HIW"      ���i�h�g�f�e�d�e�f�g�� "           NOR HIG"��"HIC"$N"HIG"�N"HIW"�ѨϤ��l"HIG"���_\n"
HIW"    ��"HBWHT"���@���h�g�f�e�d�c��"NOR HIW"��"NOR HIW" �ѨϤ��l"HIG"�����~�V�ӶV�`��\n"NOR
HIW"  ��"HBWHT"���@���i�g�f�e�d�c��"NOR HIW"��"  NOR HIG"   ��A�A���ݲM���ɭ�\n"
HIW"��"HBWHT"���@�������h�g�e�c�i"NOR HIW"��"    NOR HIC"     $N"HIG"������w�g�Ʀ��@�����l\n"
HIW"���i�i���@   ���@�@��"                  NOR HIG"        �ô��o�۩M��Ӥ@�˲H�H������\n"NOR
);
        set("unequip_msg",HIG"��"HIC"$N"HIG"�N"HIW"�ѨϤ��l"HIG"��}��A���⪺���l�Ƭ��I�I���~���h�A�^�_��즳���ˤl�C\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  set("armor_prop/show_damage",1);
  set("armor_prop/int",2);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }


