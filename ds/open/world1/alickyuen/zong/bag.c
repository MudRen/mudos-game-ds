#include <armor.h>
#include <ansi2.h>

inherit WAIST;

void create ()
{
   set_name(HIY"���]"NOR, ({ "fragrant bag", "bag" })); 
   set("long", @LONG
���]�O�@�ئN�����ר����A�ΦU���C�⪺���������n���A�̭���m��
�ơA�K�O���]�C�H�e�_�s���]�O�@���ܭ��n���k���A�~�����k�Ĥl��
�n�|�_�C�{�b���׬O�ө��ε�W����ݨ�U�ؤ��P�y�������]�b�c��
�A�C�{�ݤȡA�U�a���i�������b�c�死�]���u��W���ʦU�����]�A��
�O�H�R������C

-2008 �~�ݤȸ`���~ By Alickyuen@DS
LONG);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("unit", "��" );
      set("armor_prop/armor", 15);
      set("armor_prop/shield", 15);
      set("value", 0);
   }
   setup ();

   call_out("heal", 60);
}

int query_autoload () { return 1; }

void heal ()
{
   object me = environment(this_object());

   if( !this_object() || !me ) return;

   if( interactive(me) && me->query_temp("armor/waist") == this_object())
   {
      if( me->query("hp") < me->query("max_hp") )
      {
         me->add("hp", random(50));
         tell_object(me, YEL"���]���o�X�������O�A��M�P����O���ҫ�_�C\n"NOR);
      }
      if( me->query("mp") < me->query("max_mp") )
      {
         me->add("mp", random(50));
         tell_object(me, YEL"���]���o�X�������O�A��M�P��k�O���ҫ�_�C\n"NOR);
      }
      if( me->query("ap") < me->query("max_ap") )
      {
         me->add("ap", random(50));
         tell_object(me, YEL"���]���o�X�������O�A��M�P�줺�l���ҫ�_�C\n"NOR);
      }
   }
   call_out("heal", random(60));
}
