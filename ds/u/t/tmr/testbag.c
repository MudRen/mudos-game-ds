#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create ()
{
   set_name("���]", ({ "fragrant bag", "bag" })); 
   set("long", @LONG
���]�O�@�ئN�����ר����A�ΦU���C�⪺���������n���A�̭���m��
�ơA�K�O���]�C�H�e�_�s���]�O�@���ܭ��n���k���A�~�����k�Ĥl��
�n�|�_�C�{�b���׬O�ө��ε�W����ݨ�U�ؤ��P�y�������]�b�c��
�A�C�{�ݤȡA�U�a���i�������b�c�死�]���u��W���ʦU�����]�A��
�O�H�R������C
LONG);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "��" );
      set("armor_prop/armor", 1);
      set("value", 100);
   }
   setup ();
}

